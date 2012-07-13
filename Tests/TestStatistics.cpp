#include "Statistics.h"

int main()
{
  std::vector<float> v = {1,10};
  std::cout << Statistics::Average(v);
  std::cout << Statistics::RunningAverage(v);
  std::cout << Statistics::Variance(v);

  return 0;
}
