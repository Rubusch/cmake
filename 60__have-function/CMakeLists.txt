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

cmake_minimum_required (VERSION 2.6)
project (Basic)

## does this system provide the log and exp functions?
include (CheckFunctionExists)

check_function_exists(rand HAVE_RAND)
check_function_exists(exp HAVE_EXP)

## 2. eval config.h.in
configure_file(
  "${PROJECT_SOURCE_DIR}/config.h.in"
  "${PROJECT_BINARY_DIR}/config.h"
  )

include_directories("${PROJECT_BINARY_DIR}")
add_executable(main.exe main.cpp)
