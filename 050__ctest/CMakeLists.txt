## simple header
##
## build and run as follows:
## $ mkdir build && cd build
## $ cmake -DCMAKE_INSTALL_PREFIX=./ ..
## $ make
## $ ctest
##
################################################################################

## 1. project
cmake_minimum_required (VERSION 2.6)
project(Basic)



## 2. ctest (do not include ctest before project)
include(CTest)

## add_test(<name>, <what is executed in shell>)
## NOTE: tested is against a regex

## test: runs?
add_test(BasicRuns main.exe 25)

## test: computes 3*7 = 21?
add_test(BasicComputes21 main.exe 3)
set_tests_properties (BasicComputes21 PROPERTIES PASS_REGULAR_EXPRESSION "21")

## test: does it handle negative numbers
add_test(BasicNegative21 main.exe -3)
set_tests_properties(BasicNegative21 PROPERTIES PASS_REGULAR_EXPRESSION "-2.*") # we test regex

## test: floats (no! we handle int)
add_test (BasicFloats main.exe 0.0001)
set_tests_properties (BasicFloats PROPERTIES PASS_REGULAR_EXPRESSION "0") # result for negative will be '0'


## test generation
##
## simplify life by defining a macro
macro (do_test arg result)
  add_test (BasicComp${arg} main.exe ${arg})
  set_tests_properties (BasicComp${arg}
    PROPERTIES PASS_REGULAR_EXPRESSION ${result})
endmacro (do_test)

## run the macro generated tests
do_test(1 "7")
do_test(2 "14")
do_test(3 "21")
do_test(4 "28")
do_test(5 "35")
do_test(6 "42")
do_test(7 "49")
do_test(8 "56")
do_test(9 "63")
do_test(10 "70")



## (opt) version number
set(Basic_VERSION_MAJOR 1)
set(Basic_VERSION_MINOR 0)

## 3. includes
## add top level of include directories
include_directories ("${PROJECT_SOURCE_DIR}/include")


## 4. what is build (lib/exe)
## build an executable: executable name, and link sources
add_executable(main.exe main.cpp src/a.cpp)

## 5. installer
install(TARGETS main.exe DESTINATION bin)
install(FILES include/a.h DESTINATION include)
