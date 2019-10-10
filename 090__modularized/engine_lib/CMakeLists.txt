cmake_minimum_required(VERSION 3.9)
project(libengine)


add_library(libengine
  engine.cpp
)
add_library(Spaceship::libengine ALIAS libengine)


## includes (opt at particular ones on top level)
list(APPEND PRIVATE_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(libengine
  PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
  PRIVATE "${PRIVATE_INCLUDE_DIRS}"
)


## headers
list(APPEND ENGINELIB_PUBLIC_HEADER "engine.h")
##...
set_target_properties(libengine PROPERTIES
  PUBLIC_HEADER "${ENGINELIB_PUBLIC_HEADER}"
)


## install & export
install(TARGETS libengine EXPORT libengineConfig
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION bin
  ARCHIVE DESTINATION lib
  PUBLIC_HEADER DESTINATION include
)
## export name 'libengine' via 'libengineConfig'
install(EXPORT libengineConfig NAMESPACE Spaceship:: DESTINATION cmake)
