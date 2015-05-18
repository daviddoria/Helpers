# Allow headers in tests to be included like
# #include "Helpers.h" rather than needing
# #include "Helpers/Helpers.h"
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/..)

add_executable(TestHelpers TestHelpers.cpp)
target_link_libraries(TestHelpers ${Helpers_libraries})
add_test(TestHelpers TestHelpers)

add_executable(TestContainerInterface TestContainerInterface.cpp)
target_link_libraries(TestContainerInterface ${Helpers_libraries})
add_test(TestContainerInterface TestContainerInterface)

add_executable(TestParallelSort TestParallelSort.cpp)
target_link_libraries(TestParallelSort ${Helpers_libraries})
add_test(TestParallelSort TestParallelSort)

add_executable(TestStatistics TestStatistics.cpp)
target_link_libraries(TestStatistics ${Helpers_libraries})
add_test(TestStatistics TestStatistics)
