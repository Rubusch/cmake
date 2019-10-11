cmake_minimum_required(VERSION 3.9)
project(libcapacitor)

## library, interface (headers)
## in order to provide the headers already at build time, either
## implement an additional -If interface (general component usage),
## or setup properties (individual usage)
#add_library(libcapacitorIf INTERFACE)
#add_library(Spaceship::libcapacitorIf ALIAS libcapacitorIf)


## library
add_library(libcapacitor
  capacitor.cpp
)
add_library(Spaceship::libcapacitor ALIAS libcapacitor)


## includes (opt at particular ones on top level)
list(APPEND LIBCAPACITOR_PUBLIC_HEADERS "capacitor.h")
##...
target_include_directories(libcapacitor
  PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)


## install/export
install(TARGETS libcapacitor EXPORT libcapacitorConfig
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION bin
  ARCHIVE DESTINATION lib
  PUBLIC_HEADER DESTINATION include
)
install(EXPORT libcapacitorConfig NAMESPACE Spaceship:: DESTINATION cmake)
install(FILES ${LIBCAPACITOR_PUBLIC_HEADERS} DESTINATION include)

## install/export, interface
#install(TARGETS libcapacitorIf EXPORT libcapacitorIfConfig)
#install(EXPORT libcapacitorIfConfig NAMESPACE Spaceship:: DESTINATION cmake)

