project(Helpers)

add_library(Helpers Helpers.cpp)

message("Helpers is adding " ${CMAKE_CURRENT_SOURCE_DIR}/.. " to the include path.")
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/..)

# This is needed for shared_ptr and the trick using enable_if and if_fundamental to allow scalars
# to be treated as the 0th component of a vector.
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=gnu++0x")

if(Helpers_BuildTests)
  add_subdirectory(Tests)
endif(Helpers_BuildTests)
