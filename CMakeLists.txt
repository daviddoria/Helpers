cmake_minimum_required(VERSION 2.8)

project(Helpers)

if(NOT ${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_CURRENT_SOURCE_DIR})
  set(Helpers_includes ${CMAKE_CURRENT_SOURCE_DIR} PARENT_SCOPE)
  message("Helpers submodule used from ${CMAKE_CURRENT_SOURCE_DIR}")
endif()

# This is needed for shared_ptr and the trick using enable_if and
# if_fundamental to allow scalars
# to be treated as the 0th component of a vector.
if(UNIX)
  SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++0x")
endif(UNIX)

add_library(Helpers Helpers.cpp)
add_custom_target(HelpersSources SOURCES ContainerInterface.h
ContainerInterface.hpp
Helpers.hpp
ParallelSort.h
ParallelSort.hpp
Statistics.h
Statistics.hpp
TypeTraits.h)

SET(Helpers_BuildTests OFF CACHE BOOL "Build Helpers tests?")
if(Helpers_BuildTests)
  add_subdirectory(Tests)
endif(Helpers_BuildTests)
