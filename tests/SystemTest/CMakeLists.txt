#----------------------------------------------------------------------------
# CMakeLists.txt
#----------------------------------------------------------------------------

cmake_minimum_required(VERSION 2.6)
project(SystemTest)

include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}/../../include
  )

# Platform
# FIXME: Code duplication
if ("${CC_PLATFORM}" STREQUAL "LINUX")
  set(CMAKE_CXX_FLAGS "-DLINUX")
  set(EXE_SUFFIX "")
  link_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/../../build
    ${CMAKE_CURRENT_SOURCE_DIR}/../../deps/lib/linux
    )
  #FIXME: Is linking with all these libraries necessary?
  set(platformLibraries
    "glfw3"
    "X11"
    "Xrandr"
    "Xi"
    "Xinerama"
    "Xxf86vm"
    "Xcursor"
    "GL"
    "pthread"
    )
  set(platformFlags "")

elseif ("${CC_PLATFORM}" STREQUAL "EMSC")
  set(CMAKE_CXX_FLAGS "-DEMSC")
  set(EXE_SUFFIX ".html")
  link_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/../../build
    )
  set(platformLibraries
    ""
    )
  set(platformFlags "")

elseif ("${CC_PLATFORM}" STREQUAL "WINDOWS")
  set(CMAKE_CXX_FLAGS "-DWINDOWS")
  set(EXE_SUFFIX "")
  link_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/../../build/Debug
    ${CMAKE_CURRENT_SOURCE_DIR}/../../deps/lib/windows
    )
  set(platformLibraries
    "OpenGL32"
    "glfw3"
    )
  set(platformFlags
    "WIN32"
    )

else()
  message(FATAL_ERROR "Platform ${CC_PLATFORM} not supported")
endif()

file(GLOB_RECURSE all_sources
  ${CMAKE_CURRENT_SOURCE_DIR}/*.cc
  )

add_executable(SystemTest${EXE_SUFFIX} ${platformFlags} ${all_sources})

target_link_libraries(SystemTest${EXE_SUFFIX} CC ${platformLibraries})
