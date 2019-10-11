cmake_minimum_required(VERSION 3.9)
project(libengine)

## library, interface (headers)
## TODO provide the headers as 'interface' 
add_library(libengineIf INTERFACE)
add_library(Spaceship::libengineIf ALIAS libengineIf)


## library
add_library(libengine
  engine.cpp
)
add_library(Spaceship::libengine ALIAS libengine)


## includes (opt at particular ones on top level)
list(APPEND LIBENGINE_PUBLIC_HEADERS "engine.h")
##...
target_include_directories(libengine
  PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)

## TODO rm  
# ## headers
# list(APPEND ENGINELIB_PUBLIC_HEADER "engine.h")
# ##...
# set_target_properties(libengine PROPERTIES
#   PUBLIC_HEADER "${ENGINELIB_PUBLIC_HEADER}"
# )


## install/export
install(TARGETS libengine EXPORT libengineConfig
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION bin
  ARCHIVE DESTINATION lib
  PUBLIC_HEADER DESTINATION include
)
## export name 'libengine' via 'libengineConfig'
install(EXPORT libengineConfig NAMESPACE Spaceship:: DESTINATION cmake)

## install/export, interface
install(TARGETS libengineIf EXPORT libengineIfConfig)
install(EXPORT libengineIfConfig NAMESPACE Spaceship:: DESTINATION cmake)

install(FILES ${LIBENGINE_PUBLIC_HEADERS} DESTINATION include)
