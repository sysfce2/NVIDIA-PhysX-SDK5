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

#ifndef PXG_KERNEL_NAMES_H
#define PXG_KERNEL_NAMES_H

///////////////////////////////////////////////
//simulation controller kernels
///////////////////////////////////////////////
KERNEL_DEF(MERGE_AABBMGR_HANDLES, "mergeChangedAABBMgrHandlesLaunch")
KERNEL_DEF(UPDATE_BODY_EXTERNAL_VELOCITIES, "updateBodyExternalVelocitiesLaunch")
KERNEL_DEF(UPDATE_SHAPES, "updateShapesLaunch")
KERNEL_DEF(UPDATE_BODIES, "updateBodiesLaunch")
KERNEL_DEF(UPDATE_BODIES_DIRECT_API, "updateBodiesLaunchDirectAPI")
KERNEL_DEF(NEW_ARTICULATIONS, "newArticulationsLaunch")
KERNEL_DEF(UPDATE_ARTICULATIONS, "updateArticulationsLaunch")
KERNEL_DEF(UPDATE_JOINTS, "updateJointsLaunch")
KERNEL_DEF(UPDATE_TRANSFORMCACHE_AND_BOUNDARRAY, "updateTransformCacheAndBoundArrayLaunch")
KERNEL_DEF(MERGE_TRANSFORMCACHE_AND_BOUNDARRAY_CHANGES, "mergeTransformCacheAndBoundArrayChanges")
KERNEL_DEF(UPDATE_AABBMGR_HANDLES, "updateChangedAABBMgrHandlesLaunch")
KERNEL_DEF(COMPUTE_FROZEN_UNFROZEN_HISTOGRAM, "computeFrozenAndUnfrozenHistogramLaunch")
KERNEL_DEF(OUTPUT_FROZEN_UNFROZEN_HISTOGRAM, "outputFrozenAndUnfrozenHistogram")
KERNEL_DEF(CREATE_FROZEN_UNFROZEN_ARRAY, "createFrozenAndUnfrozenArray")

//////////////////////////////////////////////
//broad phase kernels
/////////////////////////////////////////////
KERNEL_DEF(BP_TRANSLATE_AABBS, "translateAABBsLaunch")
KERNEL_DEF(BP_MARK_DELETEDPAIRS, "markRemovedPairsLaunch")
KERNEL_DEF(BP_UPDATE_DELETEDPAIRS, "markRemovedPairsProjectionsLaunch")
KERNEL_DEF(BP_UPDATE_UPDATEDPAIRS, "markUpdatedPairsLaunch")
KERNEL_DEF(BP_UPDATE_UPDATEDPAIRS2, "markUpdatedPairsLaunch2")
KERNEL_DEF(BP_UPDATE_CREATEDPAIRS, "markCreatedPairsLaunch")
KERNEL_DEF(BP_INITIALIZE_SAPBOX, "initializeSapBox1DLaunch")
KERNEL_DEF(BP_COMPUTE_ENDPT_HISTOGRAM, "computeEndPtsHistogram")
KERNEL_DEF(BP_OUTPUT_ENDPT_HISTOGRAM, "outputEndPtsHistogram")
KERNEL_DEF(BP_CREATE_REGIONS, "createRegionsKernel")
KERNEL_DEF(BP_COMPUTE_START_REGION_HISTOGRAM, "computeStartRegionsHistogram")
KERNEL_DEF(BP_OUTPUT_START_REGION_HISTOGRAM, "outputStartRegionsHistogram")
KERNEL_DEF(BP_COMPUTE_REGION_HISTOGRAM, "computeRegionsHistogram")
KERNEL_DEF(BP_OUTPUT_REGION_HISTOGRAM, "outputRegionsHistogram")
KERNEL_DEF(BP_WRITEOUT_ACTIVE_HISTOGRAM, "writeOutStartAndActiveRegionHistogram")
KERNEL_DEF(BP_COMPUTE_ACTIVE_HISTOGRAM, "computeStartAndActiveRegionHistogram")
KERNEL_DEF(BP_OUTPUT_ACTIVE_HISTOGRAM, "outputOrderedActiveRegionHistogram")
KERNEL_DEF(BP_COMPUTE_OVERLAPCHECKS_HISTOGRAM, "computeOverlapChecksForRegionsHistogram")
KERNEL_DEF(BP_OUTPUT_OVERLAPCHECKS_HISTOGRAM, "outputOverlapChecksForRegionHistogram")
KERNEL_DEF(BP_CLEAR_NEWFLAG, "clearNewFlagLaunch")
KERNEL_DEF(BP_INITIALIZE_RANKS, "initializeRadixRanks")
KERNEL_DEF(BP_UDPATE_HANDLES, "updateHandles")
KERNEL_DEF(BP_COMPUTE_INCREMENTAL_CMP_COUNTS1, "computeIncrementalComparisonHistograms_Stage1")
KERNEL_DEF(BP_COMPUTE_INCREMENTAL_CMP_COUNTS2, "computeIncrementalComparisonHistograms_Stage2")
KERNEL_DEF(BP_INCREMENTAL_SAP, "performIncrementalSAP")
KERNEL_DEF(BP_GENERATE_FOUNDPAIR_NEWBOUNDS, "generateFoundPairsForNewBoundsRegion")
KERNEL_DEF(BP_WRITEOUT_OVERLAPCHECKS_HISTOGRAM_NEWBOUNDS, "writeOutOverlapChecksForInsertedBoundsRegionsHistogram")
KERNEL_DEF(BP_ACCUMULATE_REPORT_STAGE_1, "accumulateReportsStage_1")
KERNEL_DEF(BP_ACCUMULATE_REPORT_STAGE_2, "accumulateReportsStage_2")
KERNEL_DEF(BP_COPY_REPORTS, "copyReports")

///////////////////////////////////////////////
//narrow phase kernels
//////////////////////////////////////////////
KERNEL_DEF(FINISH_CONTACTS_KERNEL, "finishContactsKernel")
KERNEL_DEF(MEM_COPY_BALANCED_KERNEL, "MemCopyBalanced")
KERNEL_DEF(REMOVE_CONTACT_MANAGERS_1, "removeContactManagers_Stage1")
KERNEL_DEF(REMOVE_CONTACT_MANAGERS_2, "removeContactManagers_Stage2")
KERNEL_DEF(REMOVE_CONTACT_MANAGERS_3, "removeContactManagers_Stage3")
KERNEL_DEF(REMOVE_CONTACT_MANAGERS_4, "removeContactManagers_Stage4")
KERNEL_DEF(REMOVE_CONTACT_MANAGERS_5, "removeContactManagers_Stage5")
KERNEL_DEF(COMPACT_LOST_FOUND_PAIRS_1, "prepareLostFoundPairs_Stage1")
KERNEL_DEF(COMPACT_LOST_FOUND_PAIRS_2, "prepareLostFoundPairs_Stage2")
KERNEL_DEF(SPHERE_KERNEL_MAIN, "sphereNphase_Kernel")
KERNEL_DEF(BOX_BOX_KERNEL_MAIN, "boxBoxNphase_Kernel")
KERNEL_DEF(CONVEX_PLANE_KERNEL_MAIN, "convexPlaneNphase_Kernel")
KERNEL_DEF(CONVEXCORE_PLANE_KERNEL_MAIN, "convexCorePlaneNphase_Kernel")
KERNEL_DEF(CONVEXCORE_CONVEX_KERNEL_MAIN, "convexCoreConvexNphase_Kernel")
KERNEL_DEF(CONVEXCORE_TRIMESH_KERNEL32_MAIN, "convexCoreTrimeshNphase_Kernel32")
KERNEL_DEF(CONVEXCORE_TETMESH_KERNEL32_MAIN, "convexCoreTetmeshNphase_Kernel32")
KERNEL_DEF(CONVEXCORE_CLOTHMESH_KERNEL32_MAIN, "convexCoreClothmeshNphase_Kernel32")
KERNEL_DEF(CONVEX_CONVEX_KERNEL_EARLY_OUT, "convexConvexNphase_stage1Kernel")
KERNEL_DEF(CONVEX_CONVEX_KERNEL_MAIN, "convexConvexNphase_stage2Kernel")
KERNEL_DEF(REMOVE_CONTACT_MANAGERS_5_CVXTRI, "removeContactManagers_Stage5_CvxTri")
KERNEL_DEF(INITIALIZE_MANIFOLDS, "initializeManifolds")
KERNEL_DEF(CONVEX_TRIMESH_MIDPHASE, "midphaseGeneratePairs")
KERNEL_DEF(CONVEX_TRIMESH_CORE, "convexTrimeshNarrowphase")
KERNEL_DEF(CONVEX_TRIMESH_SORT_TRIANGLES, "sortTriangleIndices")
KERNEL_DEF(CONVEX_TRIMESH_POST_PROCESS, "convexTrimeshPostProcess")
KERNEL_DEF(CONVEX_HEIGHTFIELD_POST_PROCESS, "convexHeightfieldPostProcess")
KERNEL_DEF(CONVEX_TRIMESH_CORRELATE, "convexTrimeshCorrelate")
KERNEL_DEF(CONVEX_TRIMESH_FINISHCONTACTS, "convexTrimeshFinishContacts")
KERNEL_DEF(CONVEX_HEIGHTFIELD_MIDPHASE, "convexHeightFieldMidphase")
KERNEL_DEF(CONVEX_HEIGHTFIELD_CORE, "convexHeightfieldNarrowphase")
KERNEL_DEF(SPHERE_TRIMESH_CORE, "sphereTrimeshNarrowphase")
KERNEL_DEF(SPHERE_HEIGHTFIELD_CORE, "sphereHeightfieldNarrowphase")
KERNEL_DEF(TRIMESH_PLANE_CORE, "trimeshPlaneNarrowphase")
KERNEL_DEF(TRIMESH_HEIGHTFIELD_CORE, "trimeshHeightfieldNarrowphase")
KERNEL_DEF(TRIMESH_TRIMESH_CORE, "triangleTriangleCollision")
KERNEL_DEF(TRIMESH_TRIMESH_OVERLAP, "triangleTriangleOverlaps")

KERNEL_DEF(EVALUATE_POINT_DISTANCES_SDF, "evaluatePointDistancesSDFBatch")

KERNEL_DEF(UPDATE_FRICTION_PATCHES, "updateFrictionPatches")

////////////////////////////////////////////////////////////////
//solver kernels
///////////////////////////////////////////////////////////////
KERNEL_DEF(PRE_INTEGRATION, "preIntegrationLaunch")
KERNEL_DEF(CONTACT_CONSTRAINT_PREPREP_BLOCK, "constraintContactBlockPrePrepLaunch")
KERNEL_DEF(JOINT_CONSTRAINT_PREPREP, "constraint1DPrePrepLaunch")
KERNEL_DEF(JOINT_CONSTRAINT_PREPREP_BLOCK, "constraint1DBlockPrePrepLaunch")
KERNEL_DEF(JOINT_CONSTRAINT_PREPARE_BLOCK_PARALLEL, "jointConstraintBlockPrepareParallelLaunch")
KERNEL_DEF(CONTACT_CONSTRAINT_PREPARE_BLOCK_PARALLEL, "contactConstraintBlockPrepareParallelLaunch")
KERNEL_DEF(ZERO_BODIES, "ZeroBodies")
KERNEL_DEF(SOLVE_BLOCK_PARTITION, "solveBlockPartition")
KERNEL_DEF(CONCLUDE_BLOCKS, "concludeBlocks")
KERNEL_DEF(WRITEBACK_BLOCKS, "writebackBlocks")
KERNEL_DEF(WRITE_BACK_BODIES, "writeBackBodies")
KERNEL_DEF(COMPUTE_AVERAGE_VELOCITY, "computeAverageSolverBodyVelocity")
KERNEL_DEF(PROPAGATE_BODY_VELOCITY, "propagateSolverBodyVelocity")
KERNEL_DEF(INITIALIZE_INPUT_AND_RANKS_B, "initialRanksAndBodyIndexB")
KERNEL_DEF(INITIALIZE_INPUT_AND_RANKS_A, "initialRanksAndBodyIndexA")
KERNEL_DEF(RADIXSORT_SINGLEBLOCK, "bodyInputAndRanksSingleBlockLaunch")
KERNEL_DEF(RADIXSORT_CALCULATERANKS, "bodyInputAndRanksBlocksLaunch")
KERNEL_DEF(REORGANIZE_THRESHOLDSTREAM, "reorganizeThresholdElements")
KERNEL_DEF(COMPUTE_ACCUMULATED_THRESHOLDSTREAM, "computeAccumulateThresholdStream")
KERNEL_DEF(OUTPUT_ACCUMULATED_THRESHOLDSTREAM, "outputAccumulateThresholdStream")
KERNEL_DEF(WRITEOUT_ACCUMULATEDFORCEPEROBJECT, "writeoutAccumulatedForcePerObject")
KERNEL_DEF(COMPUTE_EXCEEDEDFORCE_THRESHOLDELEMENT_INDICE, "computeExceededForceThresholdElementIndice")
KERNEL_DEF(OUTPUT_EXCEEDEDFORCE_THRESHOLDELEMENT_INDICE, "outputExceededForceThresholdElementIndice")
KERNEL_DEF(SET_THRESHOLDELEMENT_MASK, "setThresholdElementsMask")
KERNEL_DEF(COMPUTE_THRESHOLDELEMENT_MASK_INDICES, "computeThresholdElementMaskIndices")
KERNEL_DEF(OUTPUT_THRESHOLDELEMENT_MASK_INDICES, "outputThresholdPairsMaskIndices")
KERNEL_DEF(CREATE_FORCECHANGE_THRESHOLDELEMENTS, "createForceChangeThresholdElements")
KERNEL_DEF(SOLVE_UNIFIED, "solveBlockUnified")
KERNEL_DEF(PROPAGATE_STATIC_SOLVER_VELOCITIES, "propagateStaticSolverBodyVelocities")

////////////////////////////////////////////////////////////////
//integration kernels
///////////////////////////////////////////////////////////////
KERNEL_DEF(INTEGRATE_CORE_PARALLEL, "integrateCoreParallelLaunch")
KERNEL_DEF(CLEAR_FRICTION_PATCH_COUNTS, "clearFrictionPatchCounts")
KERNEL_DEF(DMA_CHANGED_ELEMS, "dmaBackChangedElems")
KERNEL_DEF(BP_SIGNAL_COMPLETE, "bpSignalComplete")

KERNEL_DEF(DMA_CONSTRAINT_RESIDUAL, "dmaConstraintResidual")
KERNEL_DEF(DMA_ARTICULATION_RESIDUAL, "dmaArticulationResidual")

////////////////////////////////////////////////////////////////
//articulation kernels
//////////////////////////////////////////////////////////////
KERNEL_DEF(ARTI_DMA_DATA, "dmaBackArticulationDataLaunch")
KERNEL_DEF(ARTI_STATIC_BATCH_PREP_FIRST, "artiSumInternalContactAndJointBatches1Launch")
KERNEL_DEF(ARTI_STATIC_BATCH_PREP_SECOND, "artiSumInternalContactAndJointBatches2Launch")
KERNEL_DEF(ARTI_SOLVE_INTERNAL_CONSTRAINTS, "artiSolveInternalConstraints1T")
KERNEL_DEF(ARTI_SOLVE_INTERNAL_CONSTRAINTS_TGS, "artiSolveInternalConstraintsTGS1T")
KERNEL_DEF(ARTI_SOLVE_INTERNAL_TENDON_AND_MIMIC_JOINT, "artiSolveInternalTendonAndMimicJointConstraints1T")
KERNEL_DEF(ARTI_COMPUTE_UNCONSTRAINED, "computeUnconstrainedVelocities1TLaunch")
KERNEL_DEF(ARTI_COMPUTE_SPATIAL_PARTIAL, "computeUnconstrainedSpatialInertiaLaunchPartial1T")
KERNEL_DEF(ARTI_COMPUTE_UNCONSTRAINED_SPATIAL_INERTIA, "computeUnconstrainedSpatialInertiaLaunch1T")
KERNEL_DEF(ARTI_COMPUTE_MASS_MATRIX, "computeMassMatrix1T")
KERNEL_DEF(ARTI_COMPUTE_UNCONSTRAINED_ACCEL, "computeUnconstrainedAccelerationsLaunch1T")
KERNEL_DEF(ARTI_SAVE_VELOCITY_PGS, "artiSaveVelocity1TPGS")
KERNEL_DEF(ARTI_UPDATE_BODIES, "updateBodiesLaunch1T")
KERNEL_DEF(ARTI_UPDATE_BODIES2, "updateBodiesLaunch_Part2")
KERNEL_DEF(ARTI_UPDATE_BODIES3, "updateBodiesLaunch_Part3")
KERNEL_DEF(ARTI_SETUP_INTERNAL, "setupInternalConstraintLaunch1T")
KERNEL_DEF(ARTI_CONTACT_PREP, "artiContactConstraintBlockPrepareLaunch")
KERNEL_DEF(ARTI_JOINT_PREP, "artiJointConstraintBlockPrepareParallelLaunch")
KERNEL_DEF(ARTI_SOLVE_BLOCK_PARTITION, "artiSolveBlockPartition")
KERNEL_DEF(ARTI_UPDATE_KINEMATIC, "artiUpdateKinematic")
KERNEL_DEF(ARTI_STEP_TGS, "stepArticulation1TTGS")
KERNEL_DEF(ARTI_CONTACT_PREP_TGS, "artiTGSContactConstraintBlockPrepareLaunch")
KERNEL_DEF(ARTI_JOINT_PREP_TGS, "artiTGSJointConstraintBlockPrepareParallelLaunch")
KERNEL_DEF(ARTI_OUTPUT_VELOCITY, "artiOutputVelocity")
KERNEL_DEF(ARTI_PUSH_IMPULSE, "artiPushImpulse")
KERNEL_DEF(ARTI_COMPUTE_DEPENDENCIES, "artiComputeDependencies")
KERNEL_DEF(ARTI_PROPAGATE_IMPULSE_PGS, "artiPropagateImpulses2PGS")
KERNEL_DEF(ARTI_PROPAGATE_IMPULSE_TGS, "artiPropagateImpulses2TGS")
KERNEL_DEF(ARTI_PROPAGATE_VELOCITY, "artiPropagateVelocity")
KERNEL_DEF(ARTI_PROPAGATE_VELOCITY_TGS, "artiPropagateVelocityTGS")
KERNEL_DEF(ARTI_SUM_SELF, "artiSumSelfContactAndJointBatches")
KERNEL_DEF(ARTI_PROPAGATE_RIGID_IMPULSES_AND_SOLVE_SELF, "artiPropagateRigidImpulsesAndSolveSelfConstraints1T")
KERNEL_DEF(ARTI_PROPAGATE_RIGID_IMPULSES_AND_SOLVE_SELF_TGS, "artiPropagateRigidImpulsesAndSolveSelfConstraintsTGS1T")
KERNEL_DEF(ARTI_APPLY_TGS_SUBSTEP_FORCES, "artiApplyTgsSubstepForces")

////////////////////////////////////////////////////////////////
//TGS solver kernels
///////////////////////////////////////////////////////////////
KERNEL_DEF(ZERO_BODIES_TGS, "ZeroBodiesTGS")
KERNEL_DEF(CONCLUDE_BLOCKS_TGS, "concludeBlocksTGS")
KERNEL_DEF(WRITEBACK_BLOCKS_TGS, "writebackBlocksTGS")
KERNEL_DEF(WRITE_BACK_BODIES_TGS, "writeBackBodiesTGS")
KERNEL_DEF(COMPUTE_AVERAGE_VELOCITY_TGS, "computeAverageSolverBodyVelocityTGS")
KERNEL_DEF(INTEGRATE_CORE_PARALLEL_TGS, "integrateCoreParallelLaunchTGS")
KERNEL_DEF(INIT_STATIC_KINEMATICS, "initStaticKinematics")
KERNEL_DEF(TGS_PRE_INTEGRATION, "preIntegrationLaunchTGS")
KERNEL_DEF(TGS_INIT_SOLVER_VELS, "initializeSolverVelocitiesTGS")
KERNEL_DEF(TGS_JOINT_CONSTRAINT_PREPARE_BLOCK_PARALLEL, "jointConstraintBlockPrepareParallelLaunchTGS")
KERNEL_DEF(TGS_CONTACT_CONSTRAINT_PREPARE_BLOCK_PARALLEL, "contactConstraintBlockPrepareParallelLaunchTGS")
KERNEL_DEF(PROPAGATE_AVERAGE_VELOCITY_TGS, "propagateAverageSolverBodyVelocityTGS")
KERNEL_DEF(PROPAGATE_STATIC_SOLVER_VELOCITIES_TGS, "propagateStaticSolverBodyVelocitiesTGS")
KERNEL_DEF(APPLY_TGS_SUBSTEP_GRAVITY, "applyTGSSubstepGravity")
KERNEL_DEF(MARK_ACTIVE_SLAB_PGS, "markActiveSlabPGS")
KERNEL_DEF(MARK_ACTIVE_SLAB_TGS, "markActiveSlabTGS")

//////////////////////////////////////////////////////////////////
//radix sort kernels
//////////////////////////////////////////////////////////////////
KERNEL_DEF(RS_MULTIBLOCK, "radixSortMultiBlockLaunch")
KERNEL_DEF(RS_CALCULATERANKS_MULTIBLOCK, "radixSortMultiCalculateRanksLaunch")
KERNEL_DEF(RS_MULTIBLOCK_COUNT, "radixSortMultiBlockLaunchWithCount")
KERNEL_DEF(RS_CALCULATERANKS_MULTIBLOCK_COUNT, "radixSortMultiCalculateRanksLaunchWithCount")
KERNEL_DEF(RS_MULTIBLOCK_NO_COUNT, "radixSortMultiBlockLaunchWithoutCount")
KERNEL_DEF(RS_CALCULATERANKS_MULTIBLOCK_NO_COUNT, "radixSortMultiCalculateRanksLaunchWithoutCount")
KERNEL_DEF(RS_COPY_HIGH_32BITS, "radixSortCopyHigh32Bits")
KERNEL_DEF(RS_DOUBLE_COPY_HIGH_32BITS2, "radixSortDoubleCopyHigh32Bits")
KERNEL_DEF(RS_COPY_VALUE, "radixSortCopy")
KERNEL_DEF(RS_DOUBLE_COPY_VALUE, "radixSortDoubleCopy")
KERNEL_DEF(RS_COPY_BITS2, "radixSortCopyBits2")
KERNEL_DEF(RS_COPY_VALUE2, "radixSortCopy2")

/////////////////////////////////////////////////////////////////
//accumulate rigid body delta velocity kernels
//those are shared by soft body and particle system
////////////////////////////////////////////////////////////////
KERNEL_DEF(ACCUMULATE_DELTAVEL_RIGIDBODY_FIRST, "accumulateDeltaVRigidFirstLaunch")
KERNEL_DEF(ACCUMULATE_DELTAVEL_RIGIDBODY_SECOND, "accumulateDeltaVRigidSecondLaunch")
KERNEL_DEF(ACCUMULATE_DELTAVEL_RIGIDBODY_SECOND_MULTI1, "accumulateDeltaVRigidSecondLaunchMultiStage1")
KERNEL_DEF(ACCUMULATE_DELTAVEL_RIGIDBODY_SECOND_MULTI2, "accumulateDeltaVRigidSecondLaunchMultiStage2")
KERNEL_DEF(ACCUMULATE_DELTAVEL_RIGIDBODY_MULTI_CLEAR, "clearDeltaVRigidSecondLaunchMulti")



KERNEL_DEF(RIGID_SUM_STATIC_CONTACT1, "rigidSumInternalContactAndJointBatches1")
KERNEL_DEF(RIGID_SUM_STATIC_CONTACT2, "rigidSumInternalContactAndJointBatches2")
KERNEL_DEF(RIGID_SOLVE_STATIC_CONSTRAINTS, "solveStaticBlock")
KERNEL_DEF(RIGID_SOLVE_STATIC_CONSTRAINTS_TGS, "solveStaticBlockTGS")
KERNEL_DEF(RIGID_SOLVE_WHOLE_ISLAND_TGS, "solveWholeIslandTGS")

////////////////////////////////////////////////////////////////
//particle system kernels
///////////////////////////////////////////////////////////////	
KERNEL_DEF(PS_UPDATE_UNSORTED_ARRAY, "ps_updateUnsortedArrayLaunch")
KERNEL_DEF(PS_UPDATE_BUFFER_DATA, "ps_updateUserBufferLaunch")
KERNEL_DEF(PS_UPDATE_DIFFUSE_UNSORTED_ARRAY, "ps_updateUnsortedDiffuseArrayLaunch")
KERNEL_DEF(PS_PREINTEGRATION, "ps_preIntegrateLaunch")
KERNEL_DEF(PS_PRE_DIFFUSE_INTEGRATION, "ps_preDiffuseIntegrateLaunch")
KERNEL_DEF(PS_UPDATE_BOUND_FRIST, "ps_updateBoundFirstPassLaunch")
KERNEL_DEF(PS_UPDATE_BOUND_SECOND, "ps_updateBoundSecondPassLaunch")
KERNEL_DEF(PS_CALCULATE_HASH, "ps_calculateHashLaunch")
KERNEL_DEF(PS_CALCULATE_HASH_FOR_DIFFUSE_PARTICLES, "ps_calculateHashForDiffuseParticlesLaunch")
KERNEL_DEF(PS_REORDER_PARTICLE_FIND_CELLSTARTEND, "ps_reorderDataAndFindCellStartLaunch")
KERNEL_DEF(PS_PARTICLE_SELF_COLLISION, "ps_selfCollisionLaunch")
KERNEL_DEF(PS_PRIMITIVES_BOUND_FIRST, "ps_primitivesBoundFirstPassLaunch")
KERNEL_DEF(PS_PRIMITIVES_BOUND_SECOND, "ps_primitivesBoundSecondPassLaunch")
KERNEL_DEF(PS_PRIMITIVES_COLLISION, "ps_primitivesCollisionLaunch")
KERNEL_DEF(PS_CONVEX_COLLISION, "ps_convexCollisionLaunch")
KERNEL_DEF(PS_PRIMITIVES_DIFFUSE_COLLISION, "ps_primitivesDiffuseCollisionLaunch")
KERNEL_DEF(PS_CONVEX_DIFFUSE_COLLISION, "ps_convexDiffuseCollisionLaunch")
KERNEL_DEF(PS_TRIMESH_COLLISION, "ps_meshCollisonLaunch")
KERNEL_DEF(PS_SDF_TRIMESH_COLLISION, "ps_sdfMeshCollisonLaunch")
KERNEL_DEF(PS_HEIGHTFIELD_COLLISION, "ps_heightfieldCollisonLaunch")
KERNEL_DEF(PS_REORDER_PRIMITIVE_CONTACTS, "ps_reorderPrimitiveContactsLaunch")
KERNEL_DEF(PS_CONTACT_PREPARE, "ps_contactPrepareLaunch")
KERNEL_DEF(PS_SOLVE_PC_PARTICLE, "ps_solvePCOutputParticleDeltaVLaunch")
KERNEL_DEF(PS_SOLVE_PC_RIGID, "ps_solvePCOutputRigidDeltaVLaunch")
KERNEL_DEF(PS_SOLVE_ONEWAY_CONTACTS, "ps_solveOneWayContactDeltaVLaunch")
KERNEL_DEF(PS_FIND_RANGESTARTEND_PARTICLE_FIRST, "ps_findStartEndParticleFirstLaunch")
KERNEL_DEF(PS_FIND_RANGESTARTEND_PARTICLE_SECONE, "ps_findStartEndParticleSecondLaunch")
KERNEL_DEF(PS_ACCUMULATE_DELTAVEL_PARTICLE, "ps_accumulateDeltaVParticleLaunch")
KERNEL_DEF(PS_UPDATE_PARTICLE, "ps_updateParticleLaunch")
KERNEL_DEF(PS_INTEGRATION, "ps_integrateLaunch")
KERNEL_DEF(PS_CALCULATE_DENSITIES_AND_POTENTIALS, "ps_calculateDensityAndPotentialLaunch")
KERNEL_DEF(PS_SOLVE_DENSITIES, "ps_solveDensityLaunch")
KERNEL_DEF(PS_APPLY_DELTAS, "ps_applyDeltaLaunch")
KERNEL_DEF(PS_VORTICITY_CONFINEMENT, "ps_vorticityConfinementLaunch")
KERNEL_DEF(PS_SOLVE_VELOCITIES, "ps_solveVelocityLaunch")
KERNEL_DEF(PS_UPDATE_REMAP_VERTS, "ps_updateRemapVertsLaunch")
KERNEL_DEF(PS_SOLVE_SPRINGS, "ps_solveSpringsLaunch")
KERNEL_DEF(PS_INITIALIZE_SPRINGS, "ps_initializeSpringsLaunch")
KERNEL_DEF(PS_AVERAGEVERTS, "ps_averageVertsLaunch")
KERNEL_DEF(PS_AERODYNAMIC_1, "ps_solveAerodynamics1Launch")
KERNEL_DEF(PS_AERODYNAMIC_2, "ps_solveAerodynamics2Launch")
KERNEL_DEF(PS_CALCULATE_INFLATABLE_VOLUME, "ps_calculateInflatableVolume")
KERNEL_DEF(PS_SOLVE_INFLATABLE_VOLUME, "ps_solveInflatableVolume")
KERNEL_DEF(PS_SOLVE_SHAPES, "ps_solveShapes")
KERNEL_DEF(PS_PREP_RIGID_ATTACHMENTS, "ps_rigidAttachmentPrepareLaunch")
KERNEL_DEF(PS_SOLVE_RIGID_ATTACHMENTS, "ps_solveRigidAttachmentsLaunch")
KERNEL_DEF(PS_UPDATE_VOLUME_BOUND, "ps_update_volume_bound")
KERNEL_DEF(PS_UPDATE_SPRING, "ps_updateSprings")
KERNEL_DEF(PS_ACCUMULATE_STATIC_DENSITY, "ps_accumulateStaticDensity")
KERNEL_DEF(PS_ACCUMULATE_RIGID_DENSITY, "ps_accumulateRigidDensity")
KERNEL_DEF(PS_DIFFUSE_PARTICLES_ONE_WAY_COLLISION, "ps_diffuseParticleOneWayCollision")
KERNEL_DEF(PS_DIFFUSE_PARTICLES_UPDATE_PBF, "ps_diffuseParticleUpdatePBF")
KERNEL_DEF(PS_DIFFUSE_PARTICLES_COMPACT, "ps_diffuseParticleCompact")
KERNEL_DEF(PS_DIFFUSE_PARTICLES_CREATE, "ps_diffuseParticleCreate")
KERNEL_DEF(PS_DIFFUSE_PARTICLES_COPY, "ps_diffuseParticleCopy")
KERNEL_DEF(PS_DIFFUSE_PARTICLES_SUM, "ps_diffuseParticleSum")
KERNEL_DEF(PS_FIND_RANGESTARTEND_FEM_FIRST, "ps_findStartEndFEMFirstLaunch")
KERNEL_DEF(PS_RANGESTARTEND_FEM_SECONE, "ps_findStartEndFEMSecondLaunch")
KERNEL_DEF(PS_ACCUMULATE_FEM_PARTICLE_DELTA, "ps_accumulateFEMParticleDeltaVLaunch")
KERNEL_DEF(PS_STEP_PARTICLES, "ps_stepParticlesLaunch")
KERNEL_DEF(PS_SOLVE_PC_PARTICLE_TGS, "ps_solvePCOutputParticleDeltaVTGSLaunch")
KERNEL_DEF(PS_SOLVE_PC_RIGID_TGS, "ps_solvePCOutputRigidDeltaVTGSLaunch")
KERNEL_DEF(PS_SOLVE_RIGID_ATTACHMENTS_TGS, "ps_solveRigidAttachmentsTGSLaunch")
KERNEL_DEF(PS_FINALIZE_PARTICLES, "ps_finalizeParticlesLaunch")
KERNEL_DEF(PS_UPDATE_MATERIALS, "ps_updateMaterials")

//////////////////////////////////////////////////////////
//fem shared kernel names
//////////////////////////////////////////////////////////
KERNEL_DEF(FEM_ATTACHMENT_CONSTRAINT_PREP, "femAttachmentPrepareLaunch")

//////////////////////////////////////////////////////////
//softbody kernel names
//////////////////////////////////////////////////////////
KERNEL_DEF(SB_SIM_PREINTEGRATION, "sb_gm_preIntegrateLaunch")
KERNEL_DEF(SB_REFITBOUND, "sb_refitBoundLaunch")
KERNEL_DEF(SB_MIDPHASE_PRIMITIVES, "sb_midphaseGeneratePairsLaunch")
KERNEL_DEF(SB_PRIMITIVES_CG, "sb_primitiveContactGenLaunch")
KERNEL_DEF(SB_SB_MIDPHASE, "sb_sbMidphaseGeneratePairsLaunch")
KERNEL_DEF(SB_PS_MIDPHASE, "sb_psMidphaseGeneratePairsLaunch")
KERNEL_DEF(SB_PS_CG, "sb_psContactGenLaunch")
KERNEL_DEF(SB_CLOTH_MIDPHASE, "sb_clothMidphaseGeneratePairsLaunch")
KERNEL_DEF(SB_CLOTH_CG, "sb_clothContactGenLaunch")
KERNEL_DEF(SB_CLOTH_VERT_MIDPHASE, "sb_clothVertMidphaseGeneratePairsLaunch")
KERNEL_DEF(SB_CLOTH_VERT_CG, "sb_clothVertContactGenLaunch")
KERNEL_DEF(SB_MESH_MIDPHASE, "sb_meshMidphaseGeneratePairsLaunch")
KERNEL_DEF(SB_SDF_MESH_MIDPHASE, "sb_sdfMeshMidphaseGeneratePairsLaunch")
KERNEL_DEF(SB_MESH_CG, "sb_meshContactGenLaunch")
KERNEL_DEF(SB_HF_MIDPHASE, "sb_heightfieldMidphaseGeneratePairsLaunch")
KERNEL_DEF(SB_HF_CG, "sb_heightfieldContactGenLaunch")
KERNEL_DEF(SB_SELFCOLLISION_MIDPHASE, "sb_selfCollisionMidphaseGeneratePairsLaunch")
KERNEL_DEF(SB_REORDER_PS_CONTACTS, "sb_reorderPSContactsLaunch")
KERNEL_DEF(SB_RIGID_ATTACHMENT_CONSTRAINT_PREP, "sb_rigidAttachmentPrepareLaunch")
KERNEL_DEF(SB_RS_CONTACTPREPARE, "sb_rigidContactPrepareLaunch")
KERNEL_DEF(SB_SS_CONTACTPREPARE, "sb_softbodyContactPrepareLaunch")
KERNEL_DEF(SB_SC_CONTACTPREPARE, "sb_clothContactPrepareLaunch")
KERNEL_DEF(SB_SP_CONTACTPREPARE, "sb_particleContactPrepareLaunch")
KERNEL_DEF(SB_SOLVE_RIGID_SOFT_ATTACHMENT, "sb_solveRigidSoftAttachmentLaunch")
KERNEL_DEF(SB_SOLVE_SOFTBODY_ATTACHMENT_DELTA, "sb_solveOutputSoftBodyAttachmentDeltaVLaunch")
KERNEL_DEF(SB_SOLVE_CLOTH_ATTACHMENT_DELTA, "sb_solveOutputClothAttachmentDeltaVLaunch")
KERNEL_DEF(SB_SOLVE_PARTICLE_ATTACHMENT_DELTA, "sb_solveOutputParticleAttachmentDeltaVLaunch")
KERNEL_DEF(SB_QUERY_RIGID_SOFT_REFERENCE_COUNT, "sb_queryRigidSoftContactReferenceCountLaunch")
KERNEL_DEF(SB_SOLVE_RIGID_SOFT_COLLISION, "sb_solveRigidSoftCollisionLaunch")
KERNEL_DEF(SB_SOLVE_SOFT_SOFT_BOTH_DELTA, "sb_solveOutputSSDeltaVLaunch")
KERNEL_DEF(SB_SOLVE_SOFT_CLOTH_BOTH_DELTA, "sb_solveOutputSCDeltaVLaunch")
KERNEL_DEF(SB_SOLVE_PARTICLE_SOFT_DELTA, "sb_solveOutputSPDeltaVLaunch")
KERNEL_DEF(SB_SOLVE_PARTICLE_PARTICLE_DELTA, "sb_solveOutputParticleDeltaVLaunch")
KERNEL_DEF(SB_GM_CP_SOLVE_TETRA, "sb_gm_cp_solveTetrahedronsPartitionLaunch")
KERNEL_DEF(SB_GM_CP_SOLVE_TETRA_JACOBI_PARTITION, "sb_gm_cp_solveTetrahedronsJacobiPartitionLaunch")
KERNEL_DEF(SB_GM_UPDATETETMODELVERTS, "sb_gm_updateTetModelVertsLaunch")
KERNEL_DEF(SB_GM_ZERO_TETMULTIPLIERS, "sb_gm_zeroTetMultipliers")
KERNEL_DEF(SB_GM_CP_AVERAGEVERTS, "sb_gm_cp_averageVertsLaunch")
KERNEL_DEF(SB_UPDATETETRAROTATIONS, "sb_updateTetrahedraRotationsLaunch")
KERNEL_DEF(SB_GM_UPDATETETRAROTATIONS, "sb_gm_updateTetrahedraRotationsLaunch")
KERNEL_DEF(SB_GM_APPLY_EXTERNAL_DELTAS, "sb_gm_applyExternalDeltasLaunch")
KERNEL_DEF(SB_GM_APPLY_DEFORMATION_DELTAS, "sb_gm_applyDeformationDeltasLaunch")
KERNEL_DEF(SB_OTHER_CONTACT_REMAP_TO_SIM, "sb_other_contact_remap_to_simLaunch")
KERNEL_DEF(SB_FEM_CONTACT_REMAP_TO_SIM, "sb_fem_contact_remap_to_simLaunch")
KERNEL_DEF(SB_GM_STEPSOFTBODY, "sb_gm_stepSoftbodyLaunch")
KERNEL_DEF(SB_SOLVE_RIGID_SOFT_ATTACHMENT_TGS, "sb_solveRigidSoftAttachmentLaunchTGS")
KERNEL_DEF(SB_QUERY_RIGID_SOFT_REFERENCE_COUNT_TGS, "sb_queryRigidSoftContactReferenceCountLaunchTGS")
KERNEL_DEF(SB_SOLVE_RIGID_SOFT_COLLISION_TGS, "sb_solveRigidSoftCollisionLaunchTGS")
KERNEL_DEF(SB_SOLVE_SOFT_SOFT_BOTH_DELTA_TGS, "sb_solveOutputSSDeltaVLaunchTGS")
KERNEL_DEF(SB_CALC_STRESS, "sb_calculateStressLaunch")
KERNEL_DEF(SB_PLASTIC_DEFORM, "sb_plasticDeformLaunch")
KERNEL_DEF(SB_INIT_PLASTIC_DEFORM, "sb_initPlasticDeformLaunch")
KERNEL_DEF(SB_PLASTIC_DEFORM2, "sb_plasticDeformLaunch2")
KERNEL_DEF(SB_COPY_OR_APPLY_SOFTBODY_DATA_DEPRECATED, "sb_copyOrApplySoftBodyDataDEPRECATED")
KERNEL_DEF(SB_GM_FINALIZE_VELOCITIES, "sb_gm_finalizeVelocitiesLaunch")
KERNEL_DEF(SB_SLEEPING, "sb_sleeping")

//////////////////////////////////////////////////////////
// Direct API
//////////////////////////////////////////////////////////
KERNEL_DEF(COMPRESS_CONTACT_STAGE_1, "compressContactStage1")
KERNEL_DEF(COMPRESS_CONTACT_STAGE_2, "compressContactStage2")
KERNEL_DEF(COMPUTE_ARTI_DENSE_JACOBIANS, "computeArtiDenseJacobians")
KERNEL_DEF(COMPUTE_ARTI_MASS_MATRICES, "computeArtiMassMatrices")
KERNEL_DEF(COMPUTE_ARTI_GRAVITY_FORCES, "computeArtiGravityForces")
KERNEL_DEF(COMPUTE_ARTI_CENTRIFUGAL_FORCES, "computeArtiCentrifugalForces")
KERNEL_DEF(COMPUTE_ARTI_COM, "computeArtiCOM")
KERNEL_DEF(COMPUTE_ARTI_CENTROIDAL_MATRICES, "computeArtiCentroidalMomentumMatrices")
KERNEL_DEF(APPLY_PARTICLE_BUFFER_DATA_DEPRECATED, "applyParticleBufferDataDEPRECATED")
KERNEL_DEF(RIGID_DYNAMIC_GET_GLOBAL_POSE, "getRigidDynamicGlobalPose")
KERNEL_DEF(RIGID_DYNAMIC_GET_LINVEL, "getRigidDynamicLinearVelocity")
KERNEL_DEF(RIGID_DYNAMIC_GET_ANGVEL, "getRigidDynamicAngularVelocity")
KERNEL_DEF(RIGID_DYNAMIC_GET_LINACCEL, "getRigidDynamicLinearAcceleration")
KERNEL_DEF(RIGID_DYNAMIC_GET_ANGACCEL, "getRigidDynamicAngularAcceleration")
KERNEL_DEF(RIGID_DYNAMIC_SET_GLOBAL_POSE, "setRigidDynamicGlobalPose")
KERNEL_DEF(RIGID_DYNAMIC_SET_LINVEL, "setRigidDynamicLinearVelocity")
KERNEL_DEF(RIGID_DYNAMIC_SET_ANGVEL, "setRigidDynamicAngularVelocity")
KERNEL_DEF(RIGID_DYNAMIC_SET_FORCE, "setRigidDynamicForce")
KERNEL_DEF(RIGID_DYNAMIC_SET_TORQUE, "setRigidDynamicTorque")
KERNEL_DEF(ARTI_GET_DOF_STATES, "getArtiDofStates")
KERNEL_DEF(ARTI_GET_TRANSFORM_STATES, "getArtiTransformStates")
KERNEL_DEF(ARTI_GET_VELOCITY_STATES, "getArtiVelocityStates")
KERNEL_DEF(ARTI_GET_SPATIAL_FORCE_STATES, "getArtiSpatialForceStates")
KERNEL_DEF(ARTI_SET_DOF_STATES, "setArtiDofStates")
KERNEL_DEF(ARTI_SET_ROOT_GLOBAL_POSE_STATE, "setArtiRootGlobalPoseState")
KERNEL_DEF(ARTI_SET_ROOT_VELOCITY_STATE, "setArtiRootVelocityState")
KERNEL_DEF(ARTI_SET_LINK_FORCE_STATE, "setArtiLinkForceState")
KERNEL_DEF(ARTI_SET_LINK_TORQUE_STATE, "setArtiLinkTorqueState")
KERNEL_DEF(ARTI_SET_TENDON_STATE, "setArtiTendonState")
KERNEL_DEF(ARTI_SET_SPATIAL_TENDON_ATTACHMENT_STATE, "setArtiSpatialTendonAttachmentState")
KERNEL_DEF(ARTI_SET_FIXED_TENDON_JOINT_STATE, "setArtiFixedTendonJointState")
KERNEL_DEF(ARTI_GET_TENDON_STATE, "getArtiTendonState")
KERNEL_DEF(ARTI_GET_SPATIAL_TENDON_ATTACHMENT_STATE, "getArtiSpatialTendonAttachmentState")
KERNEL_DEF(ARTI_GET_FIXED_TENDON_JOINT_STATE, "getArtiFixedTendonJointState")
KERNEL_DEF(D6_JOINT_GET_FORCE, "getD6JointForces")
KERNEL_DEF(D6_JOINT_GET_TORQUE, "getD6JointTorques")

//////////////////////////////////////////////////////////
// Aggregate kernels
/////////////////////////////////////////////////////////
KERNEL_DEF(UPDATE_DIRTY_AGGREGATE, "updateDirtyAggregate")
KERNEL_DEF(UPDATE_AGGREGATE_BOUND, "updateAggregateBounds")
KERNEL_DEF(MARK_AGGREGATE_BOUND_BITMAP, "markAggregateBoundsUpdatedBitmap")
KERNEL_DEF(AGG_SORT_UPDATE_PROJECTIONS, "sortAndUpdateAggregateProjections")
KERNEL_DEF(AGG_SELF_COLLISION, "doSelfCollision")
KERNEL_DEF(AGG_ADD_AGGPAIRS_STAGE_1, "addAggPairsStage1")
KERNEL_DEF(AGG_ADD_AGGPAIRS_STAGE_2, "addAggPairsStage2")
KERNEL_DEF(AGG_PAIR_COLLISION, "doAggPairCollisions")
KERNEL_DEF(AGG_REMOVE_AGGPAIRS_STAGE_1, "removeAggPairsStage1")
KERNEL_DEF(AGG_REMOVE_AGGPAIRS_STAGE_2, "removeAggPairsStage2")
KERNEL_DEF(AGG_REMOVE_AGGPAIRS_STAGE_3, "removeAggPairsStage3")
KERNEL_DEF(AGG_COPY_REPORTS, "aggCopyReports")
KERNEL_DEF(CLEAR_DIRTY_AGGS, "clearDirtyAggregates")
KERNEL_DEF(COPY_USER_DATA, "copyUserData")
KERNEL_DEF(AGG_MARK_ADDED_DELETED_AGGREGATED_BOUNDS, "markAddedAndDeletedAggregatedBounds")

//////////////////////////////////////////////////////////
//FEM-cloth kernel names
//////////////////////////////////////////////////////////
KERNEL_DEF(CLOTH_SIM_PREINTEGRATION, "cloth_preIntegrateLaunch")
KERNEL_DEF(CLOTH_REFIT_BOUND, "cloth_refitBoundLaunch")
KERNEL_DEF(CLOTH_MIDPHASE_PRIMITIVES, "cloth_midphaseGeneratePairsLaunch")
KERNEL_DEF(CLOTH_SPHERE_CG, "cloth_SphereContactGenLaunch")
KERNEL_DEF(CLOTH_BOX_TRIANGLE_CG, "cloth_boxTriangleContactGenLaunch")
KERNEL_DEF(CLOTH_CONVEX_CG, "cloth_convexContactGenLaunch")
KERNEL_DEF(CLOTH_VERT_SPHERE_CG, "cloth_SphereVertexContactGenLaunch")
KERNEL_DEF(CLOTH_PLANE_VERTEX_CG, "cloth_planeVertContactGenLaunch")
KERNEL_DEF(CLOTH_MIDPHASE_VERTEX_PRIMS, "cloth_midphaseGenerateVertexPairsLaunch")
KERNEL_DEF(CLOTH_BOX_VERTEX_COLLISION, "cloth_boxVertexContactGenLaunch")
KERNEL_DEF(CLOTH_CONVEX_VERTEX_COLLISION, "cloth_convexVertexContactGenLaunch")
KERNEL_DEF(CLOTH_SELFCOLLISION_MIDPHASE_VT, "cloth_selfCollisionMidphaseVTLaunch")
KERNEL_DEF(CLOTH_SELFCOLLISION_MIDPHASE_EE, "cloth_selfCollisionMidphaseEELaunch")
KERNEL_DEF(CLOTH_DIFFERENTCLOTHCOLLISION_MIDPHASE_VT, "cloth_differentClothCollisionVTLaunch")
KERNEL_DEF(CLOTH_DIFFERENTCLOTHCOLLISION_MIDPHASE_EE, "cloth_differentClothCollisionEELaunch")
KERNEL_DEF(CLOTH_CLOTH_MIDPHASE, "cloth_clothMidphaseGeneratePairsLaunch")
KERNEL_DEF(CLOTH_PS_MIDPHASE, "cloth_psMidphaseGeneratePairsLaunch")
KERNEL_DEF(CLOTH_PS_CG, "cloth_psContactGenLaunch")
KERNEL_DEF(CLOTH_MESH_MIDPHASE, "cloth_meshMidphaseGeneratePairsLaunch")
KERNEL_DEF(CLOTH_MESH_CG, "cloth_meshContactGenLaunch")
KERNEL_DEF(CLOTH_SDF_MESH_CG, "cloth_sdfMeshContactGenLaunch")
KERNEL_DEF(CLOTH_MIDPHASE_VERTEX_MESH, "cloth_midphaseVertexMeshLaunch")
KERNEL_DEF(CLOTH_MESH_VERTEX_CG, "cloth_meshVertexContactGenLaunch")
KERNEL_DEF(CLOTH_HF_MIDPHASE, "cloth_heightfieldMidphaseGeneratePairsLaunch")
KERNEL_DEF(CLOTH_HF_CG, "cloth_heightfieldContactGenLaunch")
KERNEL_DEF(CLOTH_MIDPHASE_VERTEX_HF, "cloth_midphaseVertexHeightfieldLaunch")
KERNEL_DEF(CLOTH_HF_VERTEX_CG, "cloth_heightfieldVertexContactGenLaunch")
KERNEL_DEF(CLOTH_RIGID_ATTACHMENT_CONSTRAINT_PREP, "cloth_rigidAttachmentPrepareLaunch")
KERNEL_DEF(CLOTH_RIGID_CONTACTPREPARE, "cloth_rigidContactPrepareLaunch")
KERNEL_DEF(CLOTH_CLOTH_CONTACTPREPARE, "cloth_clothContactPrepareLaunch")
KERNEL_DEF(CLOTH_PARTICLE_CONTACTPREPARE, "cloth_particleContactPrepareLaunch")
KERNEL_DEF(CLOTH_SIM_NONSHARED_TRIANGLE_ENERGY_SOLVE, "cloth_solveNonSharedTriangleEnergyLaunch")
KERNEL_DEF(CLOTH_SIM_NONSHARED_TRIANGLE_ENERGY_SOLVE_CLUSTER, "cloth_solveNonSharedTriangleEnergyClusterLaunch")
KERNEL_DEF(CLOTH_SIM_TRIANGLEPAIR_ENERGY_SOLVE, "cloth_solveTrianglePairEnergyLaunch")
KERNEL_DEF(CLOTH_SIM_TRIANGLEPAIR_ENERGY_SOLVE_CLUSTER, "cloth_solveTrianglePairEnergyClusterLaunch")
KERNEL_DEF(CLOTH_SIM_TRIANGLEPAIR_AVERAGE_VERTS, "cloth_averageTrianglePairVertsLaunch")
KERNEL_DEF(CLOTH_SIM_STEP, "cloth_stepLaunch")
KERNEL_DEF(CLOTH_QUERY_RIGID_CLOTH_REFERENCE_COUNT, "cloth_queryRigidClothContactReferenceCountLaunch")
KERNEL_DEF(CLOTH_SOLVE_RIGID_CLOTH_COLLISION, "cloth_solveRigidClothCollisionLaunch")
KERNEL_DEF(CLOTH_SOLVE_CLOTH_VT_COLLISION, "cloth_solveClothClothDeltaVTLaunch")
KERNEL_DEF(CLOTH_SOLVE_CLOTH_EE_COLLISION, "cloth_solveClothClothDeltaEELaunch")
KERNEL_DEF(CLOTH_QUERY_CLOTH_CONTACT_VT_COUNT, "cloth_queryClothClothContactVTCountLaunch")
KERNEL_DEF(CLOTH_QUERY_CLOTH_CONTACT_EE_COUNT, "cloth_queryClothClothContactEECountLaunch")
KERNEL_DEF(CLOTH_APPLY_EXTERNAL_DELTAS, "cloth_applyExternalDeltasLaunch")
KERNEL_DEF(CLOTH_UPDATE_CLOTH_CONTACT_VALIDITY, "cloth_updateClothContactValidityLaunch")
KERNEL_DEF(CLOTH_PARTICLE_CLOTH_DELTA, "cloth_solveCPOutputClothDeltaVLaunch")
KERNEL_DEF(CLOTH_PARTICLE_PARTICLE_DELTA, "cloth_solveCPOutputParticleDeltaVLaunch")
KERNEL_DEF(CLOTH_SOLVE_RIGID_CLOTH_ATTACHMENT, "cloth_solveRigidClothAttachmentLaunch")
KERNEL_DEF(CLOTH_SOLVE_ATTACHMENT_CLOTH_CLOTH_DELTA, "cloth_solveOutputAttachmentClothClothDeltaVLaunch")
KERNEL_DEF(CLOTH_FINALIZE_VELOCITIES, "cloth_finalizeVelocitiesLaunch")
KERNEL_DEF(CLOTH_SOLVE_RIGID_CLOTH_COLLISION_TGS, "cloth_solveRigidClothCollisionTGSLaunch")
KERNEL_DEF(CLOTH_QUERY_RIGID_CLOTH_REFERENCE_COUNT_TGS, "cloth_queryRigidClothContactReferenceCountTGSLaunch")
KERNEL_DEF(CLOTH_SOLVE_RIGID_CLOTH_ATTACHMENT_TGS, "cloth_solveRigidClothAttachmentTGSLaunch")
KERNEL_DEF(CLOTH_SLEEPING, "cloth_sleeping")
KERNEL_DEF(CLOTH_IN_PLANE_DAMPING, "cloth_accumulateInPlaneDampingDeltaVelocity")
KERNEL_DEF(CLOTH_BENDING_DAMPING, "cloth_accumulateBendingDampingDeltaVelocity")
KERNEL_DEF(CLOTH_APPLY_ACCUMULATED_DAMPING, "cloth_applyAccumulatedDeltaVelocity")

//////////////////////////////////////////////////////////////
//FEM common kernel
////////////////////////////////////////////////////////////
KERNEL_DEF(FEM_REORDER_RS_CONTACTS, "fem_reorderRigidContactsLaunch")
KERNEL_DEF(CLAMP_MAX_VALUE, "clampMaxValue")
KERNEL_DEF(CLAMP_MAX_VALUES, "clampMaxValues")

//////////////////////////////////////////////////////////////
// Gpu Extension Kernels
//////////////////////////////////////////////////////////////

KERNEL_DEF(scanPerBlockKernel, "scanPerBlockKernel")
KERNEL_DEF(scanPerBlockKernel4x4, "scanPerBlockKernel4x4")
KERNEL_DEF(addBlockSumsKernel, "addBlockSumsKernel")
KERNEL_DEF(addBlockSumsKernel4x4, "addBlockSumsKernel4x4")
KERNEL_DEF(radixFourBitCountPerBlockKernel, "radixFourBitCountPerBlockKernel")
KERNEL_DEF(radixFourBitReorderKernel, "radixFourBitReorderKernel")
KERNEL_DEF(reorderKernel, "reorderKernel")

KERNEL_DEF(smoothPositionsLaunch, "smoothPositionsLaunch")
KERNEL_DEF(calculateAnisotropyLaunch, "calculateAnisotropyLaunch")
KERNEL_DEF(anisotropyKernel, "anisotropyKernel")
KERNEL_DEF(smoothPositionsKernel, "smoothPositionsKernel")

KERNEL_DEF(iso_ComputeParticleDensityUsingSDF, "iso_ComputeParticleDensityUsingSDF")
KERNEL_DEF(iso_ComputeParticleDensityUsingSDFSparse, "iso_ComputeParticleDensityUsingSDFSparse")
KERNEL_DEF(iso_ComputeParticleDensity, "iso_ComputeParticleDensity")
KERNEL_DEF(iso_ComputeParticleDensitySparse, "iso_ComputeParticleDensitySparse")
KERNEL_DEF(iso_CountCellVerts, "iso_CountCellVerts")
KERNEL_DEF(iso_CountCellVertsSparse, "iso_CountCellVertsSparse")
KERNEL_DEF(iso_CountCellVertsDC, "iso_CountCellVertsDC")
KERNEL_DEF(iso_CountCellVertsDCSparse, "iso_CountCellVertsDCSparse")
KERNEL_DEF(iso_CreateVerts, "iso_CreateVerts")
KERNEL_DEF(iso_CreateVertsSparse, "iso_CreateVertsSparse")
KERNEL_DEF(iso_CreateVertsDC, "iso_CreateVertsDC")
KERNEL_DEF(iso_CreateVertsDCSparse, "iso_CreateVertsDCSparse")
KERNEL_DEF(iso_CountTriIds, "iso_CountTriIds")
KERNEL_DEF(iso_CountTriIdsSparse, "iso_CountTriIdsSparse")
KERNEL_DEF(iso_CountTriIdsDC, "iso_CountTriIdsDC")
KERNEL_DEF(iso_CountTriIdsDCSparse, "iso_CountTriIdsDCSparse")
KERNEL_DEF(iso_CreateTriIds, "iso_CreateTriIds")
KERNEL_DEF(iso_CreateTriIdsSparse, "iso_CreateTriIdsSparse")
KERNEL_DEF(iso_CreateTriIdsDC, "iso_CreateTriIdsDC")
KERNEL_DEF(iso_CreateTriIdsDCSparse, "iso_CreateTriIdsDCSparse")
KERNEL_DEF(iso_SmoothVerts, "iso_SmoothVerts")
KERNEL_DEF(iso_AverageVerts, "iso_AverageVerts")
KERNEL_DEF(iso_SmoothNormals, "iso_SmoothNormals")
KERNEL_DEF(iso_SmoothNormalsSparse, "iso_SmoothNormalsSparse")
KERNEL_DEF(iso_SmoothNormalsNormalize, "iso_SmoothNormalsNormalize")
KERNEL_DEF(iso_SmoothNormalsNormalizeSparse, "iso_SmoothNormalsNormalizeSparse")
KERNEL_DEF(iso_ComputeNormals, "iso_ComputeNormals")
KERNEL_DEF(iso_ComputeNormalsSparse, "iso_ComputeNormalsSparse")
KERNEL_DEF(iso_NormalizeNormals, "iso_NormalizeNormals")
KERNEL_DEF(iso_NormalizeNormalsSparse, "iso_NormalizeNormalsSparse")
KERNEL_DEF(iso_GridFilterGauss, "iso_GridFilterGauss")
KERNEL_DEF(iso_GridFilterGaussSparse, "iso_GridFilterGaussSparse")
KERNEL_DEF(iso_GridFilterDilateErode, "iso_GridFilterDilateErode")
KERNEL_DEF(iso_GridFilterDilateErodeSparse, "iso_GridFilterDilateErodeSparse")

KERNEL_DEF(sg_SparseGridCalcSubgridHashes, "sg_SparseGridCalcSubgridHashes")
KERNEL_DEF(sg_SparseGridMarkRequiredNeighbors, "sg_SparseGridMarkRequiredNeighbors")
KERNEL_DEF(sg_SparseGridSortedArrayToDelta, "sg_SparseGridSortedArrayToDelta")
KERNEL_DEF(sg_SparseGridGetUniqueValues, "sg_SparseGridGetUniqueValues")
KERNEL_DEF(sg_SparseGridClearDensity, "sg_SparseGridClearDensity")
KERNEL_DEF(sg_SparseGridBuildSubgridNeighbors, "sg_SparseGridBuildSubgridNeighbors")
KERNEL_DEF(sg_MarkSubgridEndIndices, "sg_MarkSubgridEndIndices")
KERNEL_DEF(sg_ReuseSubgrids, "sg_ReuseSubgrids")
KERNEL_DEF(sg_AddReleasedSubgridsToUnusedStack, "sg_AddReleasedSubgridsToUnusedStack")
KERNEL_DEF(sg_AllocateNewSubgrids, "sg_AllocateNewSubgrids")

KERNEL_DEF(util_InterleaveBuffers, "interleaveBuffers")
KERNEL_DEF(util_InterpolateSkinnedClothVertices, "interpolateSkinnedClothVertices")
KERNEL_DEF(util_InterpolateSkinnedSoftBodyVertices, "interpolateSkinnedSoftBodyVertices")

KERNEL_DEF(util_ComputeNormals, "normalVectorsAreaWeighted")
KERNEL_DEF(util_NormalizeNormals, "normalizeNormals")
KERNEL_DEF(util_ZeroNormals, "zeroNormals")

//BVH construction kernels
KERNEL_DEF(bvh_ComputeTriangleBounds, "bvhComputeTriangleBounds")
KERNEL_DEF(bvh_ComputeTotalBounds, "bvhComputeTotalBounds")
KERNEL_DEF(bvh_ComputeTotalInvEdges, "bvhComputeTotalInvEdges")
KERNEL_DEF(bvh_CalculateMortonCodes, "bvhCalculateMortonCodes")
KERNEL_DEF(bvh_CalculateKeyDeltas, "bvhCalculateKeyDeltas")
KERNEL_DEF(bvh_CalculateKeyDeltasSquaredDistance, "bvhCalculateKeyDeltasSquaredDistance")
KERNEL_DEF(bvh_BuildLeaves, "bvhBuildLeaves")
KERNEL_DEF(bvh_BuildHierarchy, "bvhBuildHierarchy")
KERNEL_DEF(bvh_BuildHierarchyAndWindingClusters, "bvhBuildHierarchyAndWindingClusters")

//SDF Construction kernels
KERNEL_DEF(sdf_CalculateDenseGridBlocks, "sdfCalculateDenseGridBlocks")
KERNEL_DEF(sdf_CalculateDenseGridHybrid, "sdfCalculateDenseGridHybrid")
KERNEL_DEF(sdf_PopulateBackgroundSDF, "sdfPopulateBackgroundSDF")
KERNEL_DEF(sdf_MarkRequiredSdfSubgrids, "sdfMarkRequiredSdfSubgrids")
KERNEL_DEF(sdf_PopulateSdfSubgrids, "sdfPopulateSdfSubgrids")
KERNEL_DEF(sdf_CountHoles, "sdfCountHoles")
KERNEL_DEF(sdf_FindHoles, "sdfFindHoles")
KERNEL_DEF(sdf_ApplyHoleCorrections, "sdfApplyHoleCorrections")
KERNEL_DEF(sdf_CalculateDenseGridPointCloud, "sdfCalculateDenseGridPointCloud")

#endif
