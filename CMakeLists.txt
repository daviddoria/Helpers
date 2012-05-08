project(Helpers)

add_library(libHelpers Helpers.cpp)
target_link_libraries(libHelpers ${VTK_LIBRARIES})

# This is needed for shared_ptr and the trick using enable_if and if_fundamental to allow scalars
# to be treated as the 0th component of a vector.
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=gnu++0x")

if(BuildTests)
  add_subdirectory(Tests)
endif(BuildTests)
