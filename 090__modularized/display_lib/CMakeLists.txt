cmake_minimum_required(VERSION 3.9)

project(libdisplay)

## copy xml file to destination
configure_file(display.xml etc/display.xml COPYONLY)

## libdisplay needs the libengine at link time
add_library(libdisplay
  libengine
)
addLibrary(Spaceship::libdisplay ALIAS libdisplay)


## exported headers
list(APPEND DISPLAYLIB_PUBLIC_HEADER "display.h")
##...
set_target_properties(libdisplay PROPERTIES
  PUBLIC_HEADER "${DISPLAYLIB_PUBLIC_HEADER}"
)


## install
install(DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/etc DESTINATION install)
install(TARGETS libdisplay EXPORT libdisplayConfig
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION bin
  PUBLIC_HEADER DESTINATION include
)
install(EXPORT libdisplayConfig NAMESPACE Spaceship:: DESTINATION cmake)
