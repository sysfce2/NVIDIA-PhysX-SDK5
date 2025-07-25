// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions
// are met:
//  * Redistributions of source code must retain the above copyright
//    notice, this list of conditions and the following disclaimer.
//  * Redistributions in binary form must reproduce the above copyright
//    notice, this list of conditions and the following disclaimer in the
//    documentation and/or other materials provided with the distribution.
//  * Neither the name of NVIDIA CORPORATION nor the names of its
//    contributors may be used to endorse or promote products derived
//    from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS ''AS IS'' AND ANY
// EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
// PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR
// CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
// EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
// PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
// OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// Copyright (c) 2008-2025 NVIDIA Corporation. All rights reserved.
// Copyright (c) 2004-2008 AGEIA Technologies, Inc. All rights reserved.
// Copyright (c) 2001-2004 NovodeX AG. All rights reserved.  

#ifndef DY_ARTICULATION_CPUGPU_H
#define DY_ARTICULATION_CPUGPU_H

#include "foundation/PxSimpleTypes.h"
#include "foundation/PxBasicTemplates.h"
#include "PxArticulationJointReducedCoordinate.h"
#include "CmSpatialVector.h"
#include "DyFeatherstoneArticulationUtils.h"

#define DY_MIN_RESPONSE 1e-12f
#define DY_ARTICULATION_MIN_RESPONSE 1e-12f
#define DY_ARTICULATION_CFM	2e-4f
#define DY_ARTICULATION_PGS_BIAS_COEFFICIENT 0.8f

namespace physx
{
namespace Dy
{
struct ArticulationImplicitDriveDesc
{
	PX_CUDA_CALLABLE PX_FORCE_INLINE ArticulationImplicitDriveDesc(PxZERO)
		: driveTargetVelPlusInitialBias(0.0f),
			driveBiasCoefficient(0.0f),
			driveVelMultiplier(0.0f),
			driveImpulseMultiplier(0.0f),
			driveTargetPosBias(0.0f)
	{
	}
	PX_CUDA_CALLABLE PX_FORCE_INLINE ArticulationImplicitDriveDesc
		(const PxReal targetVelPlusInitialBias, const PxReal biasCoefficient, const PxReal velMultiplier,
		 const PxReal impulseMultiplier, const PxReal targetPosBias)
			:	driveTargetVelPlusInitialBias(targetVelPlusInitialBias),
				driveBiasCoefficient(biasCoefficient),
				driveVelMultiplier(velMultiplier),
				driveImpulseMultiplier(impulseMultiplier),
				driveTargetPosBias(targetPosBias)
	{
	}
	PxReal driveTargetVelPlusInitialBias;
	PxReal driveBiasCoefficient;
	PxReal driveVelMultiplier;
	PxReal driveImpulseMultiplier;
	PxReal driveTargetPosBias;
};

PX_CUDA_CALLABLE PX_FORCE_INLINE ArticulationImplicitDriveDesc computeImplicitDriveParamsForceDrive
(const PxReal stiffness, const PxReal damping, const PxReal dt, const PxReal simDt,
 const PxReal unitResponse, const PxReal geomError, const PxReal targetVelocity, const bool isTGSSolver)
{
	ArticulationImplicitDriveDesc driveDesc(PxZero);
	const PxReal a = dt * (dt * stiffness + damping);
	const PxReal b = dt * (damping * targetVelocity);
	const PxReal x = unitResponse > 0.f ? 1.0f / (1.0f + a * unitResponse) : 0.f;
	const PxReal initialBias = geomError - (simDt - dt) * targetVelocity; //equal to geomError for PGS as simDt = dt
	const PxReal driveBiasCoefficient = stiffness * x * dt;
	driveDesc.driveTargetVelPlusInitialBias = (x * b) + driveBiasCoefficient * initialBias;
	driveDesc.driveVelMultiplier = -x * a;
	driveDesc.driveBiasCoefficient = driveBiasCoefficient;
	driveDesc.driveImpulseMultiplier = isTGSSolver ? 1.f : 1.0f - x;
	driveDesc.driveTargetPosBias = isTGSSolver ? driveBiasCoefficient * targetVelocity : 0.f;
	return driveDesc;
}

PX_CUDA_CALLABLE PX_FORCE_INLINE ArticulationImplicitDriveDesc computeImplicitDriveParamsAccelerationDrive
(const PxReal stiffness, const PxReal damping, const PxReal dt, const PxReal simDt,
 const PxReal recipUnitResponse, const PxReal geomError, const PxReal targetVelocity, const bool isTGSSolver)
{
	ArticulationImplicitDriveDesc driveDesc(PxZero);
	const PxReal a = dt * (dt * stiffness + damping);
	const PxReal b = dt * (damping * targetVelocity);
	const PxReal x = 1.0f / (1.0f + a);
	const PxReal initialBias = geomError - (simDt - dt) * targetVelocity; //equal to geomError for PGS as simDt = dt
	const PxReal driveBiasCoefficient = stiffness * x * recipUnitResponse * dt;
	driveDesc.driveTargetVelPlusInitialBias = (x * b * recipUnitResponse) + driveBiasCoefficient * initialBias;
	driveDesc.driveVelMultiplier = -x * a * recipUnitResponse;
	driveDesc.driveBiasCoefficient = driveBiasCoefficient;
	driveDesc.driveImpulseMultiplier = isTGSSolver ? 1.f : 1.0f - x;
	driveDesc.driveTargetPosBias = isTGSSolver ? driveBiasCoefficient * targetVelocity : 0.f;
	return driveDesc;	
}


/**
\brief Compute the parameters for an implicitly integrated spring.
\param[in] driveType is the type of drive. 
\param[in] stiffness is the drive stiffness (force per unit position bias)
\param[in] damping is the drive damping (force per unit velocity bias)
\param[in] dt is the timestep that will be used to forward integrate the spring position bias.
\param[in] simDt is the simulation timestep.
\param[in] unitResponse is the multiplier that converts impulse to velocity change.
\param[in] recipUnitResponse is the reciprocal of unitResponse
\param[in] geomError is the position bias with value (targetPos - currentPos)
\param[in] targetVelocity is the target velocity of the drive.
\param[in] isTGSSolver should be set true when computing implicit spring params for TGS and false for PGS.
\return The implicit spring parameters.
*/
PX_CUDA_CALLABLE PX_FORCE_INLINE ArticulationImplicitDriveDesc computeImplicitDriveParams
(const PxArticulationDriveType::Enum driveType, const PxReal stiffness, const PxReal damping, const PxReal dt, const PxReal simDt,
 const PxReal unitResponse, const PxReal recipUnitResponse, const PxReal geomError, const PxReal targetVelocity, const bool isTGSSolver)
{
	ArticulationImplicitDriveDesc driveDesc(PxZero);
	switch (driveType)
	{
	case PxArticulationDriveType::eFORCE:
	{
		driveDesc = computeImplicitDriveParamsForceDrive(stiffness, damping, dt, simDt, unitResponse, geomError, targetVelocity, isTGSSolver);
	}
	break;
	case PxArticulationDriveType::eACCELERATION:
	{
		driveDesc = computeImplicitDriveParamsAccelerationDrive(stiffness, damping, dt, simDt, recipUnitResponse, geomError, targetVelocity, isTGSSolver);
	}
	break;
	case PxArticulationDriveType::eNONE:
	{
		PX_ASSERT(false);
	}
	break;
	}
	return driveDesc;
}

/**
\brief Compute the friction impulse. 
\param[in] frictionImpulse is the accumulated frictiom impulse on the current simulation step.
\param[in] staticFrictionImpulse is threshold to prevent motion of the joint.
\param[in] dynamicFrictionImpulse is constant friction applied to moving joints .
\param[in] viscousFrictionCoefficient is the coefficient of velocity dependent friction term.
\param[in] jointVel is the current velocity of the joint.
\return The friction impulse.
*/
PX_CUDA_CALLABLE PX_FORCE_INLINE PxReal computeFrictionImpulse
(PxReal frictionImpulse, const PxReal staticFrictionImpulse, const PxReal dynamicFrictionImpulse, const PxReal viscousFrictionCoefficient, const PxReal jointVel)
{
	if (PxAbs(frictionImpulse) > staticFrictionImpulse)
		{
			frictionImpulse = PxClamp(frictionImpulse, -dynamicFrictionImpulse - viscousFrictionCoefficient * PxAbs(jointVel), dynamicFrictionImpulse + viscousFrictionCoefficient * PxAbs(jointVel));
		}
	return frictionImpulse;
}

/**
\brief Compute the drive impulse for an implicitly integrated spring. 
\param[in] accumulatedDriveImpulse is the drive impulse that has accumulated since the solver started on the current simulation step.
\param[in] jointVel is the current velocity of the joint.
\param[in] jointDeltaPos is the change in joint position that has accumulated since the solver started on the current simulation step.
\param[in] elapsedTime is the time elapsed on the current simulation step (used only for the TGS solver).
\param[in] driveDesc is the implicit spring params.
\return The impulse for the implicitly integrated spring.
*/
PX_CUDA_CALLABLE PX_FORCE_INLINE PxReal computeDriveImpulse
(const PxReal accumulatedDriveImpulse, const PxReal jointVel, const PxReal jointDeltaPos, const PxReal elapsedTime, const ArticulationImplicitDriveDesc& driveDesc)
{
	const PxReal unclampedForce = 
		accumulatedDriveImpulse * driveDesc.driveImpulseMultiplier 
		+ jointVel * driveDesc.driveVelMultiplier
		+ driveDesc.driveTargetVelPlusInitialBias
		- jointDeltaPos * driveDesc.driveBiasCoefficient
		+ elapsedTime * driveDesc.driveTargetPosBias;
	return unclampedForce;
}



PX_CUDA_CALLABLE PX_INLINE PxPair<PxReal, PxReal> computeBoundsForNegativeImpulse(
    PxReal velDeviation, 
    PxReal max, 
    PxReal denom1, 
    PxReal denom2,
	PxReal impulse)
{
    PxReal bound1;
    PxReal bound2;

    // invalid case
	if(PxAbs(denom1) < PX_EPS_F32)
	{
		return PxPair<PxReal, PxReal>(-PX_MAX_F32, PX_MAX_F32);
	}
	if (PxAbs(denom2) < PX_EPS_F32) 
	{
        bound1 = (velDeviation - max) / denom1;
		if (PxAbs(velDeviation + max) < PX_EPS_F32)
			bound2 = PX_MAX_F32;
		else
      	  bound2 = (velDeviation + max) > 0.0f  ? PX_MAX_F32 : -PX_MAX_F32;
		
		return PxPair<PxReal, PxReal>(bound1, PxMin(0.0f, bound2));
    }
    
	bound1 = (velDeviation - max) / denom1;
    bound2 = (velDeviation + max) / denom2;


    if (denom2 >= 0.0f) {
		return PxPair<PxReal, PxReal>(PxMax(bound1, impulse), PxMin(0.0f, bound2));
	}
	else {
		return PxPair<PxReal, PxReal>( PxMax(PxMax(bound1, bound2), impulse), 0.0f);
	}
}


PX_CUDA_CALLABLE PX_INLINE PxPair<PxReal, PxReal> computeBoundsForPositiveImpulse(
    PxReal velDeviation, 
    PxReal max, 
    PxReal denom1, 
    PxReal denom2,
	PxReal impulse)
{
    PxReal bound1;
    PxReal bound2;

    // invalid case
	if(PxAbs(denom2) < PX_EPS_F32)
	{
		return PxPair<PxReal, PxReal>(-PX_MAX_F32, PX_MAX_F32);
	}

	if (PxAbs(denom1) < PX_EPS_F32) 
	{
        bound2 = (velDeviation + max) / denom2;
		if (PxAbs(velDeviation - max) < PX_EPS_F32)
			bound1 = -PX_MAX_F32;
		else
      	  bound1 = (velDeviation - max) > 0.0f  ? PX_MAX_F32 : -PX_MAX_F32;
		return PxPair<PxReal, PxReal>(PxMax(0.0f, bound1), bound2);
    }
    bound1 = (velDeviation - max) / denom1;
    bound2 = (velDeviation + max) / denom2;

    if (denom1 >= 0.0f) {
		return PxPair<PxReal, PxReal>(PxMax(0.0f, bound1), PxMin(bound2, impulse));
	}
	else {
		return PxPair<PxReal, PxReal>(0.0f, PxMin(PxMin(bound1, bound2), impulse));
	}
}

/**
\brief Compute the drive impulse implicitly. 
\param[in] jointVel0 is the joint velocity before drive impulse is applied.
\param[in] driveImpulse0 accumulated drive effort until the current iteration.
\param[in] driveImpulse drive impulse to be clamped.
\param[in] response response.
\param[in] maxJointVel max actuator velocity.
\param[in] maxImpulse max impulse.
\param[in] speedImpulseGradient speed impulse gradient of the performance envelope.
\return The clamped drive impulse.
*/
PX_CUDA_CALLABLE PX_INLINE PxReal clampDriveImpulse(
    PxReal jointVel0,
    PxReal driveImpulse0,
    PxReal driveImpulse,
    PxReal response,
    PxReal maxJointVel,
    PxReal maxImpulse,
    PxReal speedImpulseGradient,
    PxReal velocityDependentResistance)
{

	PxReal velDeviation = driveImpulse0 * response - jointVel0;
	PxPair<PxReal, PxReal> bounds1;
	PxPair<PxReal, PxReal> bounds2;

	if (driveImpulse > 0.0f)  {
		PxReal denom1 = response - speedImpulseGradient;
		PxReal denom2 = response + speedImpulseGradient;
		bounds1 = computeBoundsForPositiveImpulse(velDeviation, maxJointVel, denom1, denom2, driveImpulse);
		if (velocityDependentResistance == 0.0f) {
			bounds2 = PxPair<PxReal, PxReal>(-maxImpulse, maxImpulse);
		} else {
			denom1 =  response - 1.0f / velocityDependentResistance;
			denom2 =  response + 1.0f / velocityDependentResistance;
			bounds2 = computeBoundsForPositiveImpulse(velDeviation, maxImpulse / velocityDependentResistance, denom1, denom2, driveImpulse);
		}

	}

	else
	{
		PxReal denom1 = response + speedImpulseGradient;
		PxReal denom2 = response - speedImpulseGradient;
		bounds1 = computeBoundsForNegativeImpulse(velDeviation, maxJointVel, denom1, denom2, driveImpulse);
		if (velocityDependentResistance == 0.0f) {
			bounds2 = PxPair<PxReal, PxReal>(-maxImpulse, maxImpulse);
		} else {
			denom1 =  response + 1.0f / velocityDependentResistance;
			denom2 =  response - 1.0f / velocityDependentResistance;
			bounds2 = computeBoundsForNegativeImpulse(velDeviation, maxImpulse / velocityDependentResistance, denom1, denom2, driveImpulse);
		}
	}

    // Combine bounds
    PxReal lowerBound = PxMax(bounds1.first, bounds2.first);
    PxReal upperBound = PxMin(bounds1.second, bounds2.second);

    // Check for invalid bounds
    if (lowerBound > upperBound) {
        return 0.0f;
    }
    return PxClamp(driveImpulse, lowerBound, upperBound);
}

/**
\brief Apply limit constraints to an articulation joint dof.
1) Compute the delta impulse required to maintain limit constraints. 
2) Individually accumulate the impulses that have been applied to maintain both the lower and upper limit.
3) Compute the updated joint speed after applying the delta impulse.
\param[in] dt is the timestep of the simulation
\param[in] recipDt has value 1/dt 
\param[in] isVelIter is true if we are performing a velocity iteration, false if performing a position iteration.
\param[in] response is the deltaSpeed response of the joint dof to a unit impulse.
\param[in] recipResponse has value 1/response.
\param[in] erp is the Baumgarte multiplier used to resolve a fraction of the limit error.
\param[in] errorLow is the lower bound of the limit.
\param[in] errorHigh is the upper bound of the limit.
\param[in] jointPDelta is the change to the joint position that has accumulated over solver iterations.
\param[in,out] lowImpulse_ is the accumulated impulse that has been applied to maintain the limit's lower bound.
\param[in,out] highImpulse_ is the accumulated impulse that has applied to maintain the limit's upper bound.
\param[in,out] jointV_ is the joint speed before and after applying the limit impulses.
\return deltaImpulse required to enforce the upper and lower limits.
*/
PX_CUDA_CALLABLE PX_FORCE_INLINE PxReal computeLimitImpulse
(const PxReal dt, const PxReal recipDt, const bool  isVelIter, 
 const PxReal response, const PxReal recipResponse, const PxReal erp,
 const PxReal errorLow, const PxReal errorHigh,  
 const PxReal jointPDelta,
 PxReal& lowImpulse_, PxReal& highImpulse_, PxReal& jointV_)
{
	// PT: avoid aliasing
	PxReal jointV = jointV_;
	PxReal lowImpulse = lowImpulse_;
	PxReal highImpulse = highImpulse_;

	const PxReal futureDeltaJointP = jointPDelta + jointV * dt;

	// for all errors: Negative means violated
	const PxReal currErrLow = errorLow + jointPDelta;
	const PxReal nextErrLow = errorLow + futureDeltaJointP;
	const PxReal currErrHigh = errorHigh - jointPDelta;
	const PxReal nextErrHigh = errorHigh - futureDeltaJointP;

	bool limited = false;
	bool newLow = false;
	bool newHigh = false;

	const PxReal tolerance = 0.f;

	PxReal deltaF = 0.f;
	if (currErrLow < tolerance || nextErrLow < tolerance)
	{
		PxReal newJointV = jointV;
		limited = true;
		if (currErrLow < tolerance)
		{
			if (!isVelIter)
				newJointV = -currErrLow * recipDt * erp;
		}
		else
		{
			// Currently we're not in violation of the limit but would be after this time step given the current velocity.
			// To prevent that future violation, we want the current velocity to only take us right to the limit, not across it 
			newJointV = -currErrLow * recipDt;
		}

		// In position iterations, the newJointV is now such that we end up exactly on the limit after this time step (ignoring erp)
		// However, we ignored the current velocity, which may already take us further away from the limit than the newJointV.
		// Therefore, we additionally have to check now that the impulse we're applying is only repulsive overall.

		const PxReal deltaV = newJointV - jointV;
		deltaF = PxMax(lowImpulse + deltaV * recipResponse, 0.f) - lowImpulse; // accumulated limit impulse must be repulsive
		lowImpulse += deltaF;
		newLow = true;
	}
	else if (currErrHigh < tolerance || nextErrHigh < tolerance)
	{
		PxReal newJointV = jointV;
		limited = true;
		if (currErrHigh < tolerance)
		{
			if (!isVelIter)
				newJointV = currErrHigh * recipDt * erp;
		}
		else
			newJointV = currErrHigh * recipDt;

		const PxReal deltaV = newJointV - jointV;
		deltaF = PxMin(highImpulse + deltaV * recipResponse, 0.f) - highImpulse;
		highImpulse += deltaF;
		newHigh = true;
	}

	if (!limited)
	{
		// If no limit is violated right now, it could still be that a limit was active in an earlier iteration and
		// overshot. Therefore, we give that limit from which the joint position is currently moving away a chance to
		// pull back and correct the overshoot.
		// The pull-back impulse is the smaller of
		//     a) The impulse needed to bring the joint velocity to zero.
		//     b) The opposite impulse of the already applied joint limit impulse, thereby cancelling out the accumulated effect of the limit.

		const PxReal impulseForZeroVel = -jointV * recipResponse; 
		if (jointV > 0.f) // moving away from the lower limit
		{
			deltaF = PxMax(impulseForZeroVel, -lowImpulse);
			lowImpulse += deltaF;
			newLow = true;
		}
		else // moving away from the higher limit
		{
			deltaF = PxMin(impulseForZeroVel, -highImpulse);
			highImpulse += deltaF;
			newHigh = true;
		}
	}

	jointV += deltaF * response;

	if(newLow)
		lowImpulse_ = lowImpulse;
	if(newHigh)
		highImpulse_ = highImpulse;
	jointV_ = jointV;

	return deltaF;
}


/**
\brief Translate a spatial vector from the frame of one link (the source link) to the frame of another link (the target link).
\param[in] offset is the vector from the source link to the target link (== posTargetLink - posSourceLlink)
\param[in] s is the spatial vector in the frame of the source link with s.top representing the angular part of the 
spatial vector and s.bottom representing the linear part of the spatial vector.
\return The spatial vector translated into the frame of the target link with top representing the angular part of the spatial vector
and bottom representing the linear part of the spatial vector.
*/
PX_CUDA_CALLABLE PX_FORCE_INLINE Cm::SpatialVectorF translateSpatialVector(const PxVec3& offset, const Cm::SpatialVectorF& s)
{
	return Cm::SpatialVectorF(s.top, s.bottom + offset.cross(s.top));
}

/**
\brief Propagate to the parent link 
a) a spatial impulse applied to a child link
b) a joint impulse applied to the child link's inbound joint.
The Mirtich equivalent is the equation for Y in Figure 5.7, page 141 but with a modification
to account for a joint impulse applied to the child link's inbound joint.
If the joint impulse is Q and the child link impulse is YChildW then the parent link impulse has
the form:
YParentW = translateChildToParent{ YChildW + (I * s) *(Q - s^T * YChildW)/(s * I * s^T) }
Optionally accumulate [Q - S^T * YChildW] because this can be useful to reuse when propagating
delta spatial velocity from parent link to child link.
\param[in] parentToChild is the vector from parent link to child link such that childLinkPos == parentLinkPos + parentToChild
\param[in] YChildW is the link impulse to apply to the child link expressed in the world frame.
\param[in] jointDofImpulse is an optional of array joint impulses ({Q}) to apply to each dof of the inbound joint of the child link.
\param[in] jointDofISInvStISW is (I * s) / (s^T * I * s) with one entry for each dof of the child link's inbound joint.
\param[in] jointDofMotionMatrixW is the motion matrix s with one entry for each dof of the child link's inbound joint.
\param[in] dofCount is the number of dofs of the child link's incoming joint.
\param[in,out] jointDofQMinusStY accumulates [Q - s^T * YChildW] for each dof of the child link's inbound joint.
\note jointDofQMinusStY may be NULL if there is no need to accumulate [Q - s^T * YChildW] for each dof of the child link's inbound joint.
\note jointDofImpulse may be NULL if the intention is that zero joint impulse should be propagated.
\note jointDofImpulse, jointDofISInvStISW, jointDofMotionMatrixW and jointDofQMinusStY have dofCount entries ie one entry for each dof of the joint. 
\return The propagated spatial impulse in the world frame.
*/
PX_CUDA_CALLABLE PX_FORCE_INLINE Cm::SpatialVectorF propagateImpulseW
(const PxVec3& parentToChild, 
 const Cm::SpatialVectorF& YChildW, 
 const PxReal* jointDofImpulse, const Cm::SpatialVectorF* jointDofISInvStISW, const Cm::UnAlignedSpatialVector* jointDofMotionMatrixW, const PxU8 dofCount, 
 PxReal* jointDofQMinusStY)
{
	//See Mirtich Figure 5.7 page 141
	//Mirtich equivalent after accounting for joint impulse: 
	//	childToParentTranform{ Y +  (I * s) * (Q - s^T* Y)]/ (s^T * I * s) }

	Cm::SpatialVectorF YParentW(PxVec3(0, 0, 0), PxVec3(0, 0, 0));
	for (PxU8 ind = 0; ind < dofCount; ++ind)
	{
		//(Q - s^T* Y) 			
		const Cm::UnAlignedSpatialVector& sa = jointDofMotionMatrixW[ind];
		const PxReal Q = jointDofImpulse ? jointDofImpulse[ind] : 0.0f;
		const PxReal QMinusStY = Q - (sa.innerProduct(YChildW));
		PX_ASSERT(PxIsFinite(QMinusStY));

		//(I * s) * (Q - s^T* Y)]/ (s^T * I * s) 			
		YParentW += jointDofISInvStISW[ind] * QMinusStY;

		//Accumulate (Q - s^T * Y)
		PX_ASSERT(!jointDofQMinusStY || PxIsFinite(jointDofQMinusStY[ind]));
		if(jointDofQMinusStY) 
			jointDofQMinusStY[ind] += QMinusStY;
	}
	//Y +  [(I * s) * (Q - s^T* Y)]/ (s^T * I * s)]
	YParentW += YChildW;

	//parent space's spatial zero acceleration impulse
	//parentToChild satisfies parent = child + parentToChild.
	return translateSpatialVector(parentToChild, YParentW);
}

/**
/brief Propagate an acceleration (or velocity) from a parent link to a child link.
This function exploits existing knowledge of Q_i - s_i^T * Z_i^A.  If this is not known it is recommended to use
propagateVelocityW().
\param[in] parentToChild is the vector from parent link to child link such that childLinkPos == parentLinkPos + parentToChild
\param[in] parentLinkAccelerationW is the parent link acceleration (or velocity) expressed in the world frame.
\param[in] invStISW is the Mirtich equivalent of 1/[S_i^T * I_i^A * S_i]
\param[in] motionMatrixW is the Mirth equivalent of S_i of the child link's inbound joint.
\param[in] IsW is the Mirtich equvialent of I_i^A * S_i (== S_i^T * I_i^A)
\param[in] QMinusSTZ is the equivalent of Q_i - S_i^T * ZA_i in Mirtich notiation with 
	Q_i the joint force (or impulse) of the child link's inbound joint and ZA_i the child link 
	zero acceleration force (or impulse)
\param[in] dofCount is the number of dofs on the child links' inbound joint.
\param[out] jointAcceleration (or joint velocity) is incremented with the change arising 
	from the propagated acceleration (or velocity).
\note jointAcceleration (or velocity) may be NULL.
\return The spatial acceleration (or velocity) of the child link.
\note See Mirtich p121 and equations for propagating forces/applying accelerations and
	p141 for propagating velocities/applying impulses.
*/
PX_CUDA_CALLABLE PX_FORCE_INLINE  Cm::SpatialVectorF propagateAccelerationW(
	const PxVec3& parentToChild, const Cm::SpatialVectorF& parentLinkAccelerationW, 
	const InvStIs& invStISW, const Cm::UnAlignedSpatialVector* motionMatrixW, const Cm::SpatialVectorF* IsW, const PxReal* QMinusSTZ, const PxU32 dofCount, 
	PxReal* jointAcceleration)
{
	//parentToChild satisfies parent = child + parentToChild.
	Cm::SpatialVectorF motionAccelerationW = translateSpatialVector(-parentToChild, parentLinkAccelerationW); //parent velocity change


	//[Q_i - (s^T * Z_i^A + I_i^A * c_i)] - s^T * I_i^A * translated(vParent)
	//Alternatively we compute I_i^A * s == s^T * I_i^A
	//[Q_i - (s^T * vParent + I_i^A * c_i)] - I_i^A *s * translated(vParent)
	PxReal tJAccel[3];
	for (PxU32 ind = 0; ind < dofCount; ++ind)
	{
		const PxReal temp = IsW[ind].innerProduct(motionAccelerationW);
		tJAccel[ind] = (QMinusSTZ[ind] - temp);
	}

	//calculate jointAcceleration
	//qdot = [1 / s^T * I_i^A * s] *{  [Q_i - (s^T * vParent + I_i^A * c_i)] - I_i^A *s * translated(vParent) }
	//linkVel = translated(vParent) + qdot * s_i
	for (PxU32 ind = 0; ind < dofCount; ++ind)
	{
		PxReal jVel = 0.f;
		for (PxU32 ind2 = 0; ind2 < dofCount; ++ind2)
		{
			jVel += invStISW.invStIs[ind2][ind] * tJAccel[ind2];
		}

		motionAccelerationW.top += motionMatrixW[ind].top * jVel;
		motionAccelerationW.bottom += motionMatrixW[ind].bottom * jVel;

		if(jointAcceleration)
			jointAcceleration[ind] += jVel;
	}

	return motionAccelerationW;
}

/**
\brief Compute the equivalent of (J * M^-1 * J^T) for a mimic joint.
\param[in] rAA is the deltaQDot arising at joint A/dof A as a consequence of a unit joint impulse applied to joint A/dofA.
\param[in] rAB is the deltaQDot arising at joint A/dof A as a consequence of a unit joint impulse applied to joint B/dofB.
\param[in] rBB is the deltaQDot arising at joint B/dof B as a consequence of a unit joint impulse applied to joint B/dofB.
\param[in] rBA is the deltaQDot arising at joint B/dof B as a consequence of a unit joint impulse applied to joint A/dofA.
\param[in] gearRatio is the gear ratio of the mimic joint [qA + gearRatio * qB + offset = 0]
\note deltaQDotA = rAA * jointImpulseA + rAB * jointImpulseB
	  deltaQDotB = rBA * jointImpulseA + rBB * jointImpulseB
rAA, rAB, rBA, rBB play the role of an inverse mass matrix as follows:
	M^-1 = [rAA rAB]
		   [rBA rBB]
\return  (J * M^-1 * J^T) for a mimic joint.
*/
PX_CUDA_CALLABLE PX_FORCE_INLINE PxReal computeRecipMimicJointEffectiveInertia
(const PxReal rAA, const PxReal rAB, const PxReal rBB, const PxReal rBA, const PxReal gearRatio)
{
	return (rAA + gearRatio*(rAB + rBA) + gearRatio*gearRatio*rBB);
}

/*
\brief Compute the impulses to apply to jointA/dofA and jointB dofB that
satisfy the requirements of a mimimic joint.
\param[in] biasCoefficient is the Baumarte constant.
\param[in] dt is the timestep of the simulation.
\param[in] invDt is the reciprocal of dt used to forward integrate the joint positions.
\param[in] qA is the position of jointA/dofA
\param[in] qB is the position of jointB/dofB
\param[in] qADot is speed of jointA/dofA
\param[in] qBDot is speed of jointB/dofB
\param[in] gearRatio is a constant of the mimic joint constraint: qA + gearRatio*qB + offset = 0
\param[in] offset is a constant of the mimic joint constraint: qA + gearRatio*qB + offset = 0
\param[in] naturalFrequency is the oscillation frequency of the mimic joint's compliance (s^-1)
\param[in] dampingRatio is the damping ratio of the mimic joint's compliance.
\param[in] r is a constant derived from the mass matrix of the mimic joint. 
\param[in] isVelocityIteration is true if we are computing the impulse during a velocity iteration
 and false if we are computing the impulse during a position iteration.
\param[out] jointImpA is the joint impulse to apply to jointA/dofA to enforce the mimic constraint.
\param[out] jointImpB is the joint impulse to apply to jointB/dofB to enforce the mimic constraint.
\note r has value [J * M^-1 * J^T] with J the jacobian [1, beta] and 
M^-1 = 2x2 mass matrix describing deltaQDot effect of unit impulse applied to jointA/dofA and jointB/dofB
\note The impulses are computed with a zero constraint bias during velocity iterations.
\note r is pre-computed with computeRecipMimicJointEffectiveInertia()
\note If naturalFrequency < 0 the mimic joint is treated as a hard constraint with no compliance.
\note If dampingRatio < 0 the mimic joint is treated as a hard constraint with no compliance.
\note biasCoefficient is ignored if the mimic joint is compliant (when naturalFrequency > 0 and dampingRatio > 0).
When this is the case, biasCoefficient is replaced with a value that reflects the compliance of the mimic joint.
*/
PX_CUDA_CALLABLE PX_FORCE_INLINE void computeMimicJointImpulses
(const PxReal biasCoefficient, const PxReal dt, const PxReal invDt,
 const PxReal qA, const PxReal qB, const PxReal qADot, const PxReal qBDot, 
 const PxReal gearRatio, const PxReal offset,
 const PxReal naturalFrequency, const PxReal dampingRatio,
 const PxReal r,
 const bool isVelocityIteration,
 PxReal& jointImpA, PxReal& jointImpB)
{
	//For velocity iterations we have erp = 0.
	//But erp = dt*kp/(dt*kp + kd). If it is 0
	//then kd >> dt*kp.  If this is true then 
	//cfm =  1/[dt*(dt*kp + kd)] = 1/(dt*kd) = 0.
	
	PxReal erp = 0.0f;
	PxReal cfm = 0.0f;
	if(naturalFrequency <= 0 || dampingRatio <= 0 || isVelocityIteration)
	{
		erp = isVelocityIteration ? 0.0f : biasCoefficient;
		cfm = 0.0f;
	}
	else
	{
		//Note:
		//cfm has units velocity per unit impulse = kg^-1 for linear constraints 
		//erp is dimensionless

		//Governing equation is:
		//Jv + (r + cfm)*lambda + (erp/dt)* C = 0
		//with 
		//C = qA + G*qB + offset
		//r = rAA + G*(rAB + rBA) + rBB
		//and dt the timestep

		//Solve for lambda:   
		//lambda	= -(1/(cfm + r)] * (erp*C/dt + Jv)
		//			= -[1/(1 + r/cfm)] * [ C*(erp/(dt*cfm)) + v0*(1/cfm) ] 
		//with v0 = Jv

		//Now compare with spring
		//lambda = -[1/(1 + r*dt*(dt*kp + kd)][ C*dt*kp + v0*dt*(dt*kp + kd) ]

		//Solve for cfm by comparing terms.
		//1/cfm = dt*(dt*kp + kd)
		//cfm = 1/[dt*(dt*kp + kd)]

		//Solve for erp by comparing terms.
		//erp/(dt*cfm) = dt*kp
		//erp = dt*dt*kp*cfm = dt*kp/(dt*kp + kd)

		//Summarise results for cfm, erp.
		// cfm = 1/[dt*(dt*kp + kd)]
		// erp = dt*kp/(dt*kp + kd)

		//Now express cfm and erp in terms of natural frequency mu and damping ratio zeta
		//Start with computing kp from mu.
		//Remember that r plays role of reciprocal mass
		//kp = mu^2 / r
		//kd = 2 * (mu / r) * zeta

		//Summarise:
		//Given mu and zeta and r we have
		//kp = mu^2 / r
		//kd = 2 * (mu / r) * zeta
		//cfm = 1/[dt*(dt*kp + kd)]
		//erp = dt*kp/(dt*kp + kd)
		//lambda = -(1/(cfm + r)] * (erp*C/dt + Jv)

		//Compute cfm, erp from mu, zeta, r.
		const PxReal mu = naturalFrequency;
		const PxReal zeta = dampingRatio;
		const PxReal kp = mu * mu / r;
		const PxReal kd = 2.0f * mu * zeta / r;
		cfm = 1.0f / (dt * (dt * kp + kd));
		erp = (dt * kp) / (dt * kp + kd);
	}

	//Comute lambda
	//lambda =  -[ (erp * C/ dt) + Jv ] / [r + cfm]
	//C = qA + gearRatio* qB + offset
	//b = erp*C/dt
	//JV = qADot + gearRatio*qBDot
	const PxReal C = qA + gearRatio * qB + offset; 
	const PxReal b = erp * C * invDt;
	const PxReal Jv = qADot + gearRatio * qBDot;
	const PxReal effectiveInertia = 1.0f / (r + cfm);
	const PxReal lambda = -(b + Jv) * effectiveInertia;
	jointImpA = lambda;
	jointImpB = gearRatio * lambda;
}


} //namespace Dy
} //namespace physx
#endif //DY_ARTICULATION_CPUGPU_H
