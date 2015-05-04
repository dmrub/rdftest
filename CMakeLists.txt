cmake_minimum_required(VERSION 2.8)

project(rdftest)

#--------------------------------------------------
# load script for checking out projects from git
#--------------------------------------------------
list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/CMake ${PROJECT_SOURCE_DIR}/CMake/common)
include(GitExternal)

#--------------------------------------------------
# checkout common cmake tools library
# args are : location here, repo URL, repo branch
#--------------------------------------------------
Git_External(
  ${PROJECT_SOURCE_DIR}/CMake/common
  https://github.com/Eyescale/CMake.git
  subproject
  VERBOSE
)

#--------------------------------------------------
# checkout projects we want to build together
#--------------------------------------------------
Git_External(
  ${PROJECT_SOURCE_DIR}/seord
  https://github.com/dmrub/seord.git
  master
  VERBOSE
)

#--------------------------------------------------
# load add_subproject macro from common tools
#--------------------------------------------------
include(SubProject)

# Detect compiler
if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
  set(C_IS_GNU   1)
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
  set(C_IS_GNU   1)
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Intel")
  set(C_IS_INTEL 1)
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
  set(C_IS_MSVC  1)
endif()

# Enable C99 mode
if(C_IS_GNU)
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99")
endif()

if(C_IS_INTEL)
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99 -restrict")
endif()

# Enable C++11 mode
include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
if(COMPILER_SUPPORTS_CXX11)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
elseif(COMPILER_SUPPORTS_CXX0X)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
else()
        message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
endif()


#--------------------------------------------------
# Add the subprojects to our project
# args are : project name in subproject, path from here
#--------------------------------------------------
add_subproject(seord)

include_directories(
  seord/src/3rd/serd
  seord/src/3rd/sord
  seord/src/3rd/sord/src
  ${CMAKE_CURRENT_BINARY_DIR})

add_executable(pose_sordmm src/pose_sordmm.cpp ${LIBHEADERS})
target_link_libraries(pose_sordmm seord)

add_executable(pose_sordmm2 src/pose_sordmm2.cpp ${LIBHEADERS})
target_link_libraries(pose_sordmm2 seord)

add_executable(pose_sordmm_reader src/pose_sordmm_reader.cpp ${LIBHEADERS})
target_link_libraries(pose_sordmm_reader seord)
