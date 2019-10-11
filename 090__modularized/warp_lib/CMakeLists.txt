cmake_minimum_required(VERSION 3.9)

project(libwarp)


#CMake Error at warp_lib/CMakeLists.txt:14 (add_library):
#  Target "libwarp" links to target "Spaceship::libcapacitor" but the target
#  was not found.  Perhaps a find_package() call is missing for an IMPORTED
#  target, or an ALIAS target is missing?
find_package(libcapacitor CONFIG QUIET)


## copy xml file to destination
configure_file(warp.xml etc/warp.xml COPYONLY)


## 'libwarp' needs the 'libcapacitor' at link time
add_library(libwarp
  warp.cpp
)
add_library(Spaceship::libwarp ALIAS libwarp)


## includes (opt at particular ones on top level)
list(APPEND PRIVATE_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(libwarp
  PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
  PRIVATE "${PRIVATE_INCLUDE_DIRS}"
)


## link other library 'libcapacitor' to this library
## connect dependencies here
target_link_libraries(libwarp
  Spaceship::libcapacitor
)


## headers
list(APPEND WARPLIB_PUBLIC_HEADER "warp.h")
##...
set_target_properties(libwarp PROPERTIES
  PUBLIC_HEADER "${WARPLIB_PUBLIC_HEADER}"
)


## install & export
install(DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/etc DESTINATION install)
install(TARGETS libwarp EXPORT libwarpConfig
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION bin
  ARCHIVE DESTINATION lib # needed for static lib
  PUBLIC_HEADER DESTINATION include
)
## export name 'libwarp' via 'libwarpConfig'
install(EXPORT libwarpConfig NAMESPACE Spaceship:: DESTINATION cmake)
