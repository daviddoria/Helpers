cmake_minimum_required(VERSION 2.8)

project(Helpers)
SET(CMAKE_INCLUDE_CURRENT_DIR ON)

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

# Allow this project to be detected and used as a submodule
set(Helpers_include_dirs ${Helpers_include_dirs} ${CMAKE_CURRENT_SOURCE_DIR})
set_property(GLOBAL PROPERTY HelpersIncludeDirs ${Helpers_include_dirs})
set_property(GLOBAL PROPERTY HelpersLibs ${Helpers_libraries})

# Build the tests if requested
option(Helpers_BuildTests "Build Helpers tests?" OFF)
if(Helpers_BuildTests)
  add_subdirectory(Tests)
endif(Helpers_BuildTests)
