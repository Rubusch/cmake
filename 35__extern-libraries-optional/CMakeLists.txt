## simple header
##
## build and run as follows:
## $ mkdir build
## $ cd build
## $ cmake ../
## $ make
## $ ./main.exe
##
################################################################################

## Basic
cmake_minimum_required (VERSION 2.6)
project (Basic)

## (opt) version number
set (Basic_VERSION_MAJOR 1)
set (Basic_VERSION_MINOR 0)

## obtain version number from sources
configure_file (
  "${PROJECT_SOURCE_DIR}/config.h.in"
  "${PROJECT_BINARY_DIR}/config.h"
  )

## add explicitely a header directory
include_directories("${PROJECT_BINARY_DIR}")

## parse sub directory for LibA (depending if source uses it or not)
option (USE_MYLIB
        "Use my provided library implementation" ON)

## set up a #define USE_MYLIB in CMakeLists.txt and in source,
## define set in config.in.h
if (USE_MYLIB)
  include_directories ("${PROJECT_SOURCE_DIR}/LibA")
  add_subdirectory (LibA)
  set (EXTRA_LIBS ${EXTRA_LIBS} MyLibAFunctions)
endif (USE_MYLIB)

## build the executable 'main.exe': executable name, then sources
add_executable(main.exe main.cpp)

## add LibA to the executable 'main.exe'
target_link_libraries (main.exe  ${EXTRA_LIBS})
