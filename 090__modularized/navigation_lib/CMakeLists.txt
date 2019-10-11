cmake_minimum_required(VERSION 3.9)
project(libnavigation)


## library
add_library(libnavigation
  src/navigation.cpp
)
add_library(Spaceship::libnavigation ALIAS libnavigation)


## includes
#list(APPEND LIBNAVIGATION_PUBLIC_HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_include_directories(libnavigation
  PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>/include
  $<INSTALL_INTERFACE:include>
)

## install & export
install(TARGETS libnavigation EXPORT libnavigationConfig
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION bin
  ARCHIVE DESTINATION lib ## static lib
  PUBLIC_HEADER DESTINATION include
)

install(EXPORT libnavigationConfig NAMESPACE Spaceship:: DESTINATION cmake)
