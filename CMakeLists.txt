cmake_minimum_required(VERSION 2.8)

project(Helpers)

# This is needed for shared_ptr and the trick using enable_if and
# if_fundamental to allow scalars
# to be treated as the 0th component of a vector.
if(UNIX)
  SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++0x")
endif(UNIX)

add_library(Helpers Helpers.cpp)

SET(Helpers_BuildTests OFF CACHE BOOL "Build Helpers tests?")
if(Helpers_BuildTests)
  add_subdirectory(Tests)
endif(Helpers_BuildTests)
