cmake_minimum_required(VERSION 3.9)

project(libdisplay)


# TODO find_package(libengine CONFIG REQUIRED)


## copy xml file to destination
configure_file(display.xml etc/display.xml COPYONLY)


## 'libdisplay' needs the 'libengine' at link time
add_library(libdisplay
  libengine
  display.cpp
)
addLibrary(Spaceship::libdisplay ALIAS libdisplay)


## includes (opt at particular ones on top level)
list(APPEND PRIVATE_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(libdisplay
  PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
  PRIVATE "${PRIVATE_INCLUDE_DIRS}"
)


## link other library 'libengine' to this library
target_link_libraries(libdisplay Spaceship::libEngine)


## headers
list(APPEND DISPLAYLIB_PUBLIC_HEADER "display.h")
##...
set_target_properties(libdisplay PROPERTIES
  PUBLIC_HEADER "${DISPLAYLIB_PUBLIC_HEADER}"
)


## install & export
install(DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/etc DESTINATION install)
install(TARGETS libdisplay EXPORT libdisplayConfig
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION bin
  PUBLIC_HEADER DESTINATION include
)
## export name 'libdisplay' via 'libdisplayConfig'
install(EXPORT libdisplayConfig NAMESPACE Spaceship:: DESTINATION cmake)
