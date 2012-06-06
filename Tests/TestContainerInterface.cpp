#include "ContainerInterface.h"

#include <iostream>

int main()
{
  float a = 2.3;
  std::cout << Helpers::index(a, 0) << std::endl;
  std::cout << Helpers::length(a) << std::endl;
  
  const float b = 2.3;
  std::cout << Helpers::index(b, 0) << std::endl;
  std::cout << Helpers::length(b) << std::endl;
  
  std::vector<float> v = {1,2};
  std::cout << Helpers::index(v, 1) << std::endl;
  std::cout << Helpers::length(v) << std::endl;

  const std::vector<float> v2 = {1,2};
  std::cout << Helpers::index(v2, 1) << std::endl;
  std::cout << Helpers::length(v2) << std::endl;

  return 0;
}
