#include "Statistics.h"

static bool TestAverage();
static bool TestRunningAverage();
static bool TestVariance();
static bool TestCorrelation();

int main()
{
  bool allPass = true;

  allPass &= TestAverage();
  allPass &= TestRunningAverage();
  allPass &= TestVariance();
  allPass &= TestCorrelation();

  if(allPass)
  {
    return EXIT_SUCCESS;
  }
  else
  {
    return EXIT_FAILURE;
  }
}

bool TestAverage()
{
//  octave:9> mean([1,10])
//  ans =  5.5000

  std::vector<float> v = {1,10};
  float average = Statistics::Average(v);
  float correct = 5.5f;
  if(average != correct)
  {
    return false;
  }
  return true;
}

bool TestRunningAverage()
{
  std::vector<float> v = {1,10};
  float average = Statistics::RunningAverage(v);
  float correct = 5.5f;
  if(average != correct)
  {
    return false;
  }
  return true;
}

bool TestVariance()
{
//octave:10> var([1,10])
//ans =  40.500

  std::vector<float> v = {1,10};
  float variance = Statistics::Variance(v);
  float correct = 40.5f;
  if(variance != correct)
  {
    return false;
  }
  return true;
}

bool TestCorrelation()
{
  std::vector<float> a = {1,10};
  std::vector<float> b = {1,10};
  float correlation = Statistics::Correlation(a,b);
  float correct = 1.0f;

//  std::cout << "Correlation: " << correlation << std::endl;

  if(correlation != correct)
  {
    return false;
  }

  return true;
}
