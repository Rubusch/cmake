cmake_minimum_required(VERSION 3.9)
project(libnavigation)


## library
add_library(libnavigation
  src/navigation.cpp
)
add_library(Spaceship::libnavigation ALIAS libnavigation)


## includes
list(APPEND PRIVATE_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/internal)
target_include_directories(libnavigation
  PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
  PRIVATE "${PRIVATE_INCLUDE_DIRS}"
)


## headers
list(APPEND NAVIGATIONLIB_PUBLIC_HEADER "include/navigation.h")
##...
set_target_properties(libnavigation PROPERTIES
  PUBLIC_HEADER "${NAVIGATIONLIB_PUBLIC_HEADER}"
)

## install & export
install(TARGETS libnavigation EXPORT libnavigationConfig
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION bin
  ARCHIVE DESTINATION lib ## static lib
  PUBLIC_HEADER DESTINATION include
)
install(FILES include/navigation.h DESTINATION include)
install(EXPORT libnavigationConfig NAMESPACE Spaceship:: DESTINATION cmake)
