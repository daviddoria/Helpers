# Allow headers in tests to be included like
# #include "Helpers.h" rather than needing
# #include "Helpers/Helpers.h"
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/..)

add_executable(TestHelpers TestHelpers.cpp)
target_link_libraries(TestHelpers ${Helpers_libraries})

add_executable(TestContainerInterface TestContainerInterface.cpp)
target_link_libraries(TestContainerInterface ${Helpers_libraries})

add_executable(TestStatistics TestStatistics.cpp)
target_link_libraries(TestStatistics ${Helpers_libraries})
