#include "ContainerInterface.h"

#include <iostream>

static bool TestScalar();
static bool TestSTLVector();

int main()
{
  bool allPass = true;

  allPass &= TestScalar();
  allPass &= TestSTLVector();
  
  if(allPass)
  {
    return EXIT_SUCCESS;
  }
  else
  {
    return EXIT_FAILURE;
  }
}

bool TestScalar()
{
  bool pass = true;

  // Non-const version
  float a = 2.3;
//  std::cout << Helpers::index(a, 0) << std::endl;
//  std::cout << Helpers::length(a) << std::endl;
  if(Helpers::index(a, 0) != a ||
     Helpers::length(a) != 1)
  {
    pass = false;
  }

  // Const version
  const float b = 2.3;
  if(Helpers::index(b, 0) != b ||
     Helpers::length(b) != 1)
  {
    pass = false;
  }
//  std::cout << Helpers::index(b, 0) << std::endl;
//  std::cout << Helpers::length(b) << std::endl;

  return pass;
}

bool TestSTLVector()
{
  bool pass = true;

  // Non-const version
  std::vector<float> v = {1,2};
  if(Helpers::index(v, 0) != v[0] ||
     Helpers::index(v, 1) != v[1] ||
     Helpers::length(v) != 2)
  {
    pass = false;
  }
//  std::cout << Helpers::index(v, 1) << std::endl;
//  std::cout << Helpers::length(v) << std::endl;

  // Const version
  const std::vector<float> vConst = {1,2};
  if(Helpers::index(vConst, 0) != vConst[0] ||
     Helpers::index(vConst, 1) != vConst[1] ||
     Helpers::length(vConst) != 2)
  {
    pass = false;
  }
//  std::cout << Helpers::index(v2, 1) << std::endl;
//  std::cout << Helpers::length(v2) << std::endl;

  return pass;
}
