cmake_minimum_required(VERSION 3.9)
project(libnavigation)


## library
add_library(libnavigation
  src/navigation.cpp
)
add_library(Spaceship::libnavigation ALIAS libnavigation)


## includes
#include_directories("${PROJECT_SOURCE_DIR}/include")

list(APPEND LIBNAVIGATION_PUBLIC_HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_include_directories(libnavigation
  PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>/include
  $<INSTALL_INTERFACE:include>
)


# ## headers 
# TODO
# list(APPEND LIBNAVIGATION_PUBLIC_HEADERS "include/navigation.h")
##...
# set_target_properties(libnavigation PROPERTIES
#   PUBLIC_HEADER "${LIBNAVIGATION_PUBLIC_HEADERS}"
# )

## possible to separate with ';', e.g. "include/navigation.h;include/control.h"
#set_target_properties(libnavigation PROPERTIES PUBLIC_HEADER "include/navigation.h")


## install & export
install(TARGETS libnavigation EXPORT libnavigationConfig
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION bin
  ARCHIVE DESTINATION lib ## static lib
  PUBLIC_HEADER DESTINATION include
)
install(FILES ${LIBENGINE_PUBLIC_HEADERS} DESTINATION include)
install(EXPORT libnavigationConfig NAMESPACE Spaceship:: DESTINATION cmake)
