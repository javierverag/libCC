#----------------------------------------------------------------------------
# CMakeLists.txt
#----------------------------------------------------------------------------

cmake_minimum_required(VERSION 2.6)
project(CC)

set(CC_VERSION_MAJOR 0)
set(CC_VERSION_MINOR 3)

file(GLOB_RECURSE all_sources
  ${CMAKE_CURRENT_SOURCE_DIR}/sources/*.cc
  )

# Mark debug builds
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DDEBUG")

# Platform
if ("${CC_PLATFORM}" STREQUAL "LINUX")
  file(GLOB_RECURSE sourcesToRemove
    *Windows.cc
    *Emsc.cc
    )
  set(CMAKE_CXX_FLAGS "-DLINUX")

elseif ("${CC_PLATFORM}" STREQUAL "EMSC")
  file(GLOB_RECURSE sourcesToRemove
    *Windows.cc
    *Linux.cc
    )
  set(CMAKE_CXX_FLAGS "-DEMSC")

elseif ("${CC_PLATFORM}" STREQUAL "WINDOWS")
  set(CMAKE_CXX_FLAGS "-DWINDOWS")
  file(GLOB_RECURSE sourcesToRemove
    *Linux.cc
    *Emsc.cc
    )

else ()
  message(FATAL_ERROR "Platform ${CC_PLATFORM} not supported")
endif()

# Remove other platfoms sources
list(REMOVE_ITEM all_sources ${sourcesToRemove})

include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}/include
  ${CMAKE_CURRENT_SOURCE_DIR}/deps/include
  )

add_library(CC STATIC ${all_sources})

