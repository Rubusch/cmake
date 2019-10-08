## simple header
##
## build and run as follows:
## $ mkdir build
## $ cd build
## $ cmake ..
## $ make
##
## binary package
## $ cpack --config CPackConfig.cmake
##
## source package
## $ cpack --config CPackSourceConfig.cmake
##
################################################################################

## Basic
cmake_minimum_required (VERSION 2.6)
project (Basic)

## (opt) version number
set (Basic_VERSION_MAJOR 1)
set (Basic_VERSION_MINOR 0)

## build an executable: executable name, then sources
add_executable(main.exe main.cpp)

## cpack driven installer package
include (InstallRequiredSystemLibraries)
set (CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/License.txt")
set (CPACK_PACKAGE_VERSION_MAJOR "${Basic_VERSION_MAJOR}")
set (CPACK_PACKAGE_VERSION_MINOR "${Basic_VERSION_MINOR}")
include (CPack)
