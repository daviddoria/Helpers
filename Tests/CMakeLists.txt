# Allow headers in tests to be included like
# #include "Helpers.h" rather than needing
# #include "Helpers/Helpers.h" 
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/..)

add_executable(Tests Tests.cpp)
target_link_libraries(Tests Helpers)
