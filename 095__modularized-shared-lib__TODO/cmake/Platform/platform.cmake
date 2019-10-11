## compile flags
set(CMAKE_C_FLAGS_INIT "-fPIC -shared")
set(CMAKE_CXX_FLAGS_INIT "-fPIC -shared")
set(CMAKE_CXX_FLAGS_DEBUG_INIT "-g -Wall -fPIC -shared")
set(CMAKE_CXX_LINK_EXECUTABLE "<CMAKE_CXX_COMPILER> <FLAGS> <CMAKE_CXX_LINK_FLAGS> <LINK_FLAGS> <OBJECTS> <LINK_LIBRARIES> -o <TARGET>")
#set(CMAKE_EXE_LINKER_FLAGS "-nostdlib -Ttext=0x01000000 -z max-page-size=0x1000 -T .... --entry=0x0")
#set(CMAKE_SHARED_LINKER_FLAGS "-nostdlib ....") 

## set a general build directory
#set(CMAKE_FIND_ROOT_PATH ${BUILD_DIR})

set_property(GLOBAL PROPERTY TARGET_SUPPORTS_SHARED_LIBS TRUE)
set(CMAKE_SHARED_LIBRARY_PREFIX "")
set(CMAKE_SHARED_LIBRARY_SUFFIX ".lib.so")

## additional path for headers
#list(APPEND SYSTEM_INCLUDE_DIRS "${BASE_DIR}/.../include")
#include_directories(SYSTEM ${SYSTEM_INCLUDE_DIRS})


