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

## add top level of include directories
include_directories ("${PROJECT_SOURCE_DIR}/include")

## build an executable: executable name, and link sources
add_executable(main.exe main.cpp src/a.cpp)
