cmake_minimum_required(VERSION 3.9)
project(libengine)

# TODO find_package(libengine CONFIG REQUIRED)

add_library(Spaceship::libengine ALIAS libengine)


## exported headers
list(APPEND ENGINELIB_PUBLIC_HEADER "engine.h")
##...
set_target_properties(libnavigation PROPERTIES
  PUBLIC_HEADER "${ENGINELIB_PUBLIC_HEADER}"
)


## install
install(TARGETS libengine EXPORT libengineConfig
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION bin
  PUBLIC_HEADER DESTINATION include
)
install(EXPORT libengineConfig NAMESPACE Spaceship:: DESTINATION cmake)
