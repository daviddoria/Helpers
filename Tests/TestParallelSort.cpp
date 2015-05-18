#include "ParallelSort.h"

int main()
{
  std::vector<float> vec;
  vec.push_back(2);
  vec.push_back(1);
  vec.push_back(3);

  ParallelSort<float>::IndexedVectorType sorted = ParallelSort<float>::ParallelSortAscending(vec);

  return 0;
}
