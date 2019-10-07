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
set (Tutorial_VERSION_MINOR 0)

## add top level of include directories
include_directories ("${PROJECT_SOURCE_DIR}/include")

## add source directory
add_subdirectory (src)

## build an executable: executable name, then sources
add_executable(main.exe main.cpp)

## link as library to the project
target_link_libraries (Basic LibA)
