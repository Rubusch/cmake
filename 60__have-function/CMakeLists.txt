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


configure_file(
  "${PROJECT_SOURCE_DIR}/config.h.in"
  "${PROJECT_BINARY_DIR}/config.h"
  )

## does this system provide the log and exp functions?
include (CheckFunctionExists)
check_function_exists (log HAVE_LOG)
check_function_exists (exp HAVE_EXP)


## build an executable: executable name, then sources
add_executable(main.exe main.cpp)
