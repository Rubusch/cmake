## generator

## first we add the generator
add_executable(generator.exe generator.cpp)

## add the command to generate the source code
add_custom_command (
  OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/a.h
  DEPENDS generator.exe
  COMMAND generator.exe ${CMAKE_CURRENT_BINARY_DIR}/a.h
  )

## add the binary tree directory to the search path
## for include files
include_directories( ${CMAKE_CURRENT_BINARY_DIR} )

## add the main library
add_library(LibA ${CMAKE_CURRENT_BINARY_DIR}/a.h)  

## installer
install (TARGETS LibA DESTINATION bin)
install (FILES a.h DESTINATION include) # the 'a.h' install is optional, just to demoesnstrate..
