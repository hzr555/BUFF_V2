set(MVSDK_PATH_ROOT "/opt/DahuaTech/MVviewer/include")
set(GenICam_INCLUDE_PATH "GenICam")
set(Infra_INCLUDE_PATH "Infra" )
set(Media_INCLUDE_PATH "Media")
set(Memory_INCLUDE_PATH "Memory")
set(MVSDK_LIBRARIES_ROOT "/opt/DahuaTech/MVviewer/lib/*.so")

SET(MVSDK_INCLUDE_DIR ${MVSDK_PATH_ROOT};${MVSDK_PATH_ROOT}/${GenICam_INCLUDE_PATH};${MVSDK_PATH_ROOT}/${Infra_INCLUDE_PATH};${MVSDK_PATH_ROOT}/${Media_INCLUDE_PATH};${MVSDK_PATH_ROOT}/${Memory_INCLUDE_PATH})
SET(MVSDK_LIBRARIES "")
file(GLOB MVSDK_LIBRARIES ${MVSDK_LIBRARIES_ROOT})

FIND_PATH(MVSDK_INCLUDE_DIRECTORIES  MVSDK_INCLUDE_DIR)
FIND_LIBRARY(MVSDK_LINK_LIBRARIES  MVSDK_LIBRARIES)

#寻找MVSDK的包
SET(MVSDK_FOUND TRUE)

