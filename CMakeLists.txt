cmake_minimum_required(VERSION 2.8)

project(Helpers)
SET(CMAKE_INCLUDE_CURRENT_DIR ON)

add_subdirectory(CMakeHelpers)

# This is needed for shared_ptr and the trick using enable_if and
# if_fundamental to allow scalars
# to be treated as the 0th component of a vector.
if(UNIX)
  SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")
endif(UNIX)

# Give the compiler all of the required include directories
include_directories(${Helpers_include_dirs})

# Create the library
add_library(Helpers Helpers.cpp)
set(Helpers_libraries ${Helpers_libraries} Helpers)

# Add non-compiled files to the project
add_custom_target(HelpersSources SOURCES ContainerInterface.h
ContainerInterface.hpp
Helpers.hpp
ParallelSort.h
ParallelSort.hpp
Statistics.h
Statistics.hpp
TypeTraits.h)

CreateSubmodule(Helpers)

# Build the tests if requested
option(Helpers_BuildTests "Build Helpers tests?" OFF)
if(Helpers_BuildTests)
  ENABLE_TESTING()
  add_subdirectory(Tests)
endif(Helpers_BuildTests)
