cmake_minimum_required(VERSION 3.9)

project(libdisplay)

#CMake Error at display_lib/CMakeLists.txt:14 (add_library):
#  Target "libdisplay" links to target "Spaceship::libengine" but the target
#  was not found.  Perhaps a find_package() call is missing for an IMPORTED
#  target, or an ALIAS target is missing?
find_package(libengine CONFIG REQUIRED)


## copy xml file to destination
configure_file(display.xml etc/display.xml COPYONLY)


## 'libdisplay' needs the 'libengine' at link time
add_library(libdisplay
  display.cpp
#  libengine
)
add_library(Spaceship::libdisplay ALIAS libdisplay)


## includes (opt at particular ones on top level)
list(APPEND PRIVATE_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(libdisplay
  PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
  PRIVATE "${PRIVATE_INCLUDE_DIRS}"
)


## link other library 'libengine' to this library
target_link_libraries(libdisplay Spaceship::libengine)


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
  ARCHIVE DESTINATION lib # needed for static lib
  PUBLIC_HEADER DESTINATION include
)
## export name 'libdisplay' via 'libdisplayConfig'
install(EXPORT libdisplayConfig NAMESPACE Spaceship:: DESTINATION cmake)
