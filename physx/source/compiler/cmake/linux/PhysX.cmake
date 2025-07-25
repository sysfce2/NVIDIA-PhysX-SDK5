## Redistribution and use in source and binary forms, with or without
## modification, are permitted provided that the following conditions
## are met:
##  * Redistributions of source code must retain the above copyright
##    notice, this list of conditions and the following disclaimer.
##  * Redistributions in binary form must reproduce the above copyright
##    notice, this list of conditions and the following disclaimer in the
##    documentation and/or other materials provided with the distribution.
##  * Neither the name of NVIDIA CORPORATION nor the names of its
##    contributors may be used to endorse or promote products derived
##    from this software without specific prior written permission.
##
## THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS ''AS IS'' AND ANY
## EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
## IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
## PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR
## CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
## EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
## PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
## PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
## OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
## (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
## OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
##
## Copyright (c) 2008-2025 NVIDIA Corporation. All rights reserved.

#
# Build PhysX (PROJECT not SOLUTION)
#

SET(PHYSX_GPU_HEADERS
	${PHYSX_ROOT_DIR}/include/gpu/PxGpu.h
    ${PHYSX_ROOT_DIR}/include/gpu/PxPhysicsGpu.h
)
SOURCE_GROUP(include\\gpu FILES ${PHYSX_GPU_HEADERS})

SET(PHYSX_CUDACONTEXT_MANAGER_GPU_HEADERS
	${PHYSX_ROOT_DIR}/include/cudamanager/PxCudaContextManager.h
	${PHYSX_ROOT_DIR}/include/cudamanager/PxCudaContext.h
	${PHYSX_ROOT_DIR}/include/cudamanager/PxCudaTypes.h
)
SOURCE_GROUP(include\\cudamanager FILES ${PHYSX_CUDACONTEXT_MANAGER_GPU_HEADERS})

SET(PHYSX_PLATFORM_INCLUDES
)

SET(PHYSX_PLATFORM_OBJECT_FILES
	$<TARGET_OBJECTS:LowLevel>
	$<TARGET_OBJECTS:LowLevelAABB>
	$<TARGET_OBJECTS:LowLevelDynamics>
	$<TARGET_OBJECTS:PhysXTask>
	$<TARGET_OBJECTS:SceneQuery>
	$<TARGET_OBJECTS:SimulationController>	
)

SET(PHYSX_PLATFORM_SRC_FILES
	${PHYSX_GPU_HEADERS}
	${PHYSX_CUDACONTEXT_MANAGER_GPU_HEADERS}
	${PX_SOURCE_DIR}/gpu/PxGpu.cpp
	${PX_SOURCE_DIR}/gpu/PxPhysXGpuModuleLoader.cpp
	
	${PHYSX_PLATFORM_OBJECT_FILES}
)

IF(NOT PUBLIC_RELEASE)
    LIST(APPEND PHYSX_PLATFORM_SRC_FILES
        ${PX_SOURCE_DIR}/internal/device/linux/PhysXIndicatorLinux.cpp
    )
ENDIF()

INSTALL(FILES ${PHYSX_GPU_HEADERS} DESTINATION include/gpu)
INSTALL(FILES ${PHYSX_CUDACONTEXT_MANAGER_GPU_HEADERS} DESTINATION include/cudamanager)

IF(PX_GENERATE_STATIC_LIBRARIES)
	SET(PHYSX_LIBTYPE STATIC)
	SET(PXPHYSX_LIBTYPE_DEFS 
		PX_PHYSX_STATIC_LIB;
	)	
ELSE()
	SET(PHYSX_LIBTYPE SHARED)
	SET(PXPHYSX_LIBTYPE_DEFS
		PX_PHYSX_CORE_EXPORTS;
	)
ENDIF()

IF(PX_GENERATE_GPU_STATIC_LIBRARIES)
	SET(PXPHYSX_GPU_DEFS PX_PHYSX_GPU_STATIC)
ENDIF()

# Set default PhysXGpu shared library name
IF(CMAKE_SIZEOF_VOID_P EQUAL 8)
    SET(BITNESS_STRING "64")
ELSE()
    SET(BITNESS_STRING "32")
ENDIF()
SET(PHYSX_GPU_SHARED_LIB_NAME_DEF PX_PHYSX_GPU_SHARED_LIB_NAME=libPhysXGpu_${BITNESS_STRING}.so)

SET(PHYSX_COMPILE_DEFS
	# Common to all configurations
	${PHYSX_LINUX_COMPILE_DEFS};${PXPHYSX_LIBTYPE_DEFS};${PHYSX_GPU_SHARED_LIB_NAME_DEF};${PXPHYSX_GPU_DEFS}

	$<$<CONFIG:debug>:${PHYSX_LINUX_DEBUG_COMPILE_DEFS};>
	$<$<CONFIG:checked>:${PHYSX_LINUX_CHECKED_COMPILE_DEFS};>
	$<$<CONFIG:profile>:${PHYSX_LINUX_PROFILE_COMPILE_DEFS};>
	$<$<CONFIG:release>:${PHYSX_LINUX_RELEASE_COMPILE_DEFS};>
)

SET(PHYSX_PLATFORM_LINK_FLAGS " ")
SET(PHYSX_PLATFORM_LINK_FLAGS_DEBUG " ")
SET(PHYSX_PLATFORM_LINK_FLAGS_CHECKED " ")
SET(PHYSX_PLATFORM_LINK_FLAGS_PROFILE " ")
SET(PHYSX_PLATFORM_LINK_FLAGS_RELEASE " ")

SET(PHYSX_PLATFORM_LINKED_LIBS dl)

IF ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
  SET_SOURCE_FILES_PROPERTIES(${PX_SOURCE_DIR}/omnipvd/OmniPvdPxSampler.cpp PROPERTIES COMPILE_FLAGS "-fpermissive -Wno-error")
ENDIF()

IF(NOT PUBLIC_RELEASE)
	SET(PHYSX_DEVICE_SOURCE
		${PX_SOURCE_DIR}/internal/device/PhysXIndicator.h
	)
	SOURCE_GROUP(src\\device FILES ${PHYSX_DEVICE_SOURCE})
	
	LIST(APPEND PHYSX_PLATFORM_INCLUDES
		${PHYSX_SOURCE_DIR}/physx/src/internal/device
	)
ELSE()
	SET(PHYSX_DEVICE_SOURCE
	)
ENDIF()
