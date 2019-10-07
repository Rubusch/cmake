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
set (Tutorial_VERSION_MAJOR 1)
#set (Tutorial_VERSION_MINOR 0) ## obtain value from file

## obtain version number from sources
configure_file (
  "${PROJECT_SOURCE_DIR}/version.h.in"
  "${PROJECT_BINARY_DIR}/version.h"
  )

## add explicitely a header directory
include_directories("${PROJECT_BINARY_DIR}")

## build an executable: executable name, then sources
add_executable(main.exe main.cpp a.cpp)
