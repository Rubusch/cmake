## simple header
##
## build and run as follows:
## $ mkdir build && cd build
## $ cmake -DCMAKE_INSTALL_PREFIX=./ ..
## $ make
## $ make install
## $ ./main.exe
##
################################################################################

## Basic
cmake_minimum_required (VERSION 2.6)
project (Basic)

## (opt) version number
set (Tutorial_VERSION_MAJOR 1)
set (Tutorial_VERSION_MINOR 0)

## add top level of include directories
include_directories ("${PROJECT_SOURCE_DIR}/include")

## build an executable: executable name, and link sources
add_executable(main.exe main.cpp src/a.cpp)

## installer
install (TARGETS main.exe DESTINATION bin)
install (FILES include/a.h DESTINATION include)
