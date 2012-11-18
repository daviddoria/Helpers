#include "Helpers.h"

// STL
#include <sstream>

static bool TestFuzzyCompare();

static bool TestGetFileExtension();

static bool TestMin();
static bool TestMax();

static bool TestSortBySecondAccending();
static bool TestSortByFirstAccending();

static bool TestInlineIgnore();

static bool TestWeightedAverage();

static bool TestNormalizeVectorInPlace();

static bool TestNormalizeVector();

static bool TestMinOfIndex();

static bool TestMinOfAllIndices_Vector();
static bool TestMinOfAllIndices_Scalar();

static bool TestMaxOfAllIndices_Vector();
static bool TestMaxOfAllIndices_Scalar();

static bool TestSphericalToCartesian();
static bool TestCartesianToSpherical();

static bool TestHasBracketOperator();

static bool TestNegativeLog();

static bool TestGetPath();

static bool TestReplaceFileExtension();

static bool TestGetSequentialFileName();

static bool TestSideLengthFromRadius();

static bool TestIsOdd();

static bool TestZeroPad();

static bool TestStringsMatch();

static bool TestRoundAwayFromZero();

static bool TestRandomInt();

static bool TestIsValidRGB();

static bool TestArgmin();

static bool TestArgmax();

static bool TestMaxOfIndex();

static bool TestVectorMedian();

static bool TestConvertFrom();

static bool TestSum();

static bool TestVectorSumOfAbsoluteDifferences();

static bool TestOutputNode();

static bool TestWriteVectorToFile();

static bool TestWriteVectorToFileLines();

static bool TestOutputFirst();

static bool TestExtractFirst();

static bool TestContains();

static bool TestOutput();

static bool TestClosestIndex();

static bool TestIsNaN();

static bool TestContainsNaN();

static bool TestKeepTopN();

static bool TestDoesQueueContain();

static bool TestDoesStackContain();

static bool TestForce0to255();

static bool TestHSV_H_Difference();

int main()
{
  bool AllTestsPass = false;

  AllTestsPass &= TestFuzzyCompare();

  AllTestsPass &= TestGetFileExtension();

  AllTestsPass &= TestSortBySecondAccending();
  AllTestsPass &= TestSortByFirstAccending();

  AllTestsPass &= TestInlineIgnore();

  AllTestsPass &= TestWeightedAverage();

  AllTestsPass &= TestNormalizeVectorInPlace();

  AllTestsPass &= TestNormalizeVector();

  AllTestsPass &= TestMinOfIndex();

  AllTestsPass &= TestMinOfAllIndices_Vector();
  AllTestsPass &= TestMinOfAllIndices_Scalar();

  AllTestsPass &= TestMaxOfAllIndices_Vector();
  AllTestsPass &= TestMaxOfAllIndices_Scalar();

  AllTestsPass &= TestSphericalToCartesian();
  AllTestsPass &= TestCartesianToSpherical();

  AllTestsPass &= TestHasBracketOperator();

  AllTestsPass &= TestNegativeLog();

  AllTestsPass &= TestGetPath();

  AllTestsPass &= TestReplaceFileExtension();

  AllTestsPass &= TestGetSequentialFileName();

  AllTestsPass &= TestSideLengthFromRadius();

  AllTestsPass &= TestIsOdd();

  AllTestsPass &= TestZeroPad();

  AllTestsPass &= TestStringsMatch();

  AllTestsPass &= TestRoundAwayFromZero();

  AllTestsPass &= TestRandomInt();

  AllTestsPass &= TestIsValidRGB();

  AllTestsPass &= TestArgmin();

  AllTestsPass &= TestArgmax();

  AllTestsPass &= TestMaxOfIndex();

  AllTestsPass &= TestMin();
  AllTestsPass &= TestMax();

  AllTestsPass &= TestVectorMedian();

  AllTestsPass &= TestConvertFrom();

  AllTestsPass &= TestSum();

  AllTestsPass &= TestVectorSumOfAbsoluteDifferences();

  AllTestsPass &= TestOutputNode();

  AllTestsPass &= TestWriteVectorToFile();

  AllTestsPass &= TestWriteVectorToFileLines();

  AllTestsPass &= TestOutputFirst();

  AllTestsPass &= TestExtractFirst();

  AllTestsPass &= TestContains();

  AllTestsPass &= TestOutput();

  AllTestsPass &= TestClosestIndex();

  AllTestsPass &= TestIsNaN();

  AllTestsPass &= TestContainsNaN();

  AllTestsPass &= TestKeepTopN();

  AllTestsPass &= TestDoesQueueContain();

  AllTestsPass &= TestDoesStackContain();

  AllTestsPass &= TestForce0to255();

  AllTestsPass &= TestHSV_H_Difference();

  if(AllTestsPass)
  {
    return EXIT_SUCCESS;
  }
  else
  {
    std::cerr << "Not all tests passed!" << std::endl;
    return EXIT_FAILURE;
  }
}

bool TestNormalizeVector()
{
  std::cout << "TestNormalizeVector()" << std::endl;

  bool allPass = true;

  // Test with same type
  {
  std::vector<float> a;
  a.push_back(1);
  a.push_back(2);
  a.push_back(3);

  std::vector<float> normalized = Helpers::NormalizeVector(a);
  // Octave: a=[1 2 3]; b=a/norm(a)
  std::vector<float> correctAnswer = {0.26726, 0.53452, 0.80178};
  allPass &= Helpers::FuzzyCompare(normalized, correctAnswer);
  }

  // Test with different type
  {
  std::vector<int> a;
  a.push_back(1);
  a.push_back(2);
  a.push_back(3);

  std::vector<float> normalized = Helpers::NormalizeVector(a);
  // Octave: a=[1 2 3]; b=a/norm(a)
  std::vector<float> correctAnswer = {0.26726, 0.53452, 0.80178};
  allPass &= Helpers::FuzzyCompare(normalized, correctAnswer);
  }

  return allPass;
}

bool TestNormalizeVectorInPlace()
{
  std::cout << "TestNormalizeVectorInPlace()" << std::endl;

  std::vector<float> a;
  a.push_back(1);
  a.push_back(2);
  a.push_back(3);

  Helpers::NormalizeVectorInPlace(a);

  // Octave: a=[1 2 3]; b=a/norm(a)
  std::vector<float> correctAnswer = {0.26726, 0.53452, 0.80178};
  return Helpers::FuzzyCompare(a, correctAnswer);
}

bool TestGetFileExtension()
{
  std::cout << "TestGetFileExtension()" << std::endl;
  std::string filename = "test.txt";
  std::string extension = Helpers::GetFileExtension(filename);

  std::cout << "extension: " << extension << std::endl;
}

bool TestSortByFirstAccending()
{
  std::cout << "TestSortByFirstAccending()" << std::endl;
  typedef std::pair<int, float> MyType;
  std::vector<MyType> v{
        {1, 4.5}, {3, 6.7}, {9, 7.8}
  };

  std::sort(v.begin(), v.end(), Helpers::SortByFirstAccending<MyType>);
}

bool TestSortBySecondAccending()
{
  std::cout << "TestSortBySecondAccending()" << std::endl;
  typedef std::pair<int, float> MyType;
  std::vector<MyType> v{
        {1, 4.5}, {3, 6.7}, {9, 7.8}
  };

  std::sort(v.begin(), v.end(), Helpers::SortBySecondAccending<MyType>);
}

bool TestInlineIgnore()
{
  std::cout << "TestInlineIgnore()" << std::endl;
  std::stringstream ss;
  ss << "1 : 2";
  int a,b;

  ss >> a >> Helpers::InlineIgnore >> b;

  std::cout << a << " " << b << std::endl;
}

bool TestWeightedAverage()
{
  std::cout << "TestWeightedAverage()" << std::endl;
  std::vector<int> values;
  values.push_back(1);
  values.push_back(2);
  values.push_back(3);

  std::vector<float> weights;
  weights.push_back(1);
  weights.push_back(1);
  weights.push_back(2);

  int weightedAverage = Helpers::WeightedAverage(values, weights);

  std::cout << "WeightedAverage: " << weightedAverage << std::endl;
}

bool TestMinOfIndex()
{
  std::cout << "TestMinOfIndex()" << std::endl;
  std::vector<std::vector<int> > vectorOfVectors;
  for(unsigned int i = 4; i < 10; ++i)
  {
    std::vector<int> v(3);
    v[0] = i;
    v[1] = i;
    v[2] = i;
    vectorOfVectors.push_back(v);
  }

  int minComponent2 = Helpers::MinOfIndex(vectorOfVectors, 2);

  std::cout << "minComponent2: " << minComponent2 << std::endl;
}


bool TestMaxOfAllIndices_Vector()
{
  std::cout << "TestMaxOfAllIndices_Vector()" << std::endl;
  const unsigned int numberOfComponents = 3;
  typedef std::vector<int> VectorType;
  std::vector<VectorType> vectorOfVectors;
  for(unsigned int i = 4; i < 10; ++i)
  {
    VectorType v(numberOfComponents);
    v[0] = i;
    v[1] = i;
    v[2] = i;
    vectorOfVectors.push_back(v);
  }

  VectorType maxComponents(numberOfComponents);

  Helpers::MaxOfAllIndices(vectorOfVectors, maxComponents);

  std::cout << "maxComponents: ";
  for(size_t i = 0; i < maxComponents.size(); ++i)
  {
    std::cout << maxComponents[i] << std::endl;
  }
}

bool TestMaxOfAllIndices_Scalar()
{
  std::cout << "TestMaxOfAllIndices_Scalar()" << std::endl;

  typedef std::vector<int> VectorType;

  VectorType v;

  for(unsigned int i = 4; i < 10; ++i)
  {
    v.push_back(i);
  }

  VectorType::value_type maxValue;
  Helpers::MaxOfAllIndices(v, maxValue);

  std::cout << "maxValue: " << maxValue << std::endl;
}

bool TestMinOfAllIndices_Vector()
{
  std::cout << "TestMinOfAllIndices_Vector()" << std::endl;
  const unsigned int numberOfComponents = 3;
  typedef std::vector<int> VectorType;
  std::vector<VectorType> vectorOfVectors;
  for(unsigned int i = 4; i < 10; ++i)
  {
    VectorType v(numberOfComponents);
    v[0] = i;
    v[1] = i;
    v[2] = i;
    vectorOfVectors.push_back(v);
  }

  VectorType minComponents(numberOfComponents);

  Helpers::MinOfAllIndices(vectorOfVectors, minComponents);

  std::cout << "minComponents: ";
  for(size_t i = 0; i < minComponents.size(); ++i)
  {
    std::cout << minComponents[i] << std::endl;
  }
}

bool TestMinOfAllIndices_Scalar()
{
  std::cout << "TestMinOfAllIndices_Scalar()" << std::endl;

  typedef std::vector<int> VectorType;

  VectorType v;

  for(unsigned int i = 4; i < 10; ++i)
  {
    v.push_back(i);
  }

  VectorType::value_type minValue;
  Helpers::MinOfAllIndices(v, minValue);

  std::cout << "minValue: " << minValue << std::endl;
}

bool TestSphericalToCartesian()
{
//  std::cout << "TestSphericalToCartesian()" << std::endl;
//  double r = 1.0;
//  double theta = 0.0;
//  double phi = 0.0;

//  double x, y, z;

//  Helpers::SphericalToCartesian(x, y, z, r, theta, phi);

//  std::cout << "Spherical: r=" << r << " theta=" << theta << " phi=" << phi
//            << " to Cartesian: x=" << x << " y=" << y << " z=" << z << std::endl;
}

bool TestCartesianToSpherical()
{
//  std::cout << "TestCartesianToSpherical()" << std::endl;
//  double r, theta, phi;

//  double x = 0.0;
//  double y = 0.0;
//  double z = 1.0;

//  Helpers::CartesianToSpherical(r, theta, phi, x, y, z);

//  std::cout << "Cartesian: x=" << x << " y=" << y << " z=" << z
//            << " to Spherical: r=" << r << " theta=" << theta << " phi=" << phi  << std::endl;

}

bool TestHasBracketOperator()
{
//  typedef std::vector<float> VectorType;
//  static_assert(Helpers::HasBracketOperator<VectorType>::value,
//                "VectorType does not have an operator[]!");

//  typedef std::vector<int> VectorType;
//  static_assert(Helpers::HasBracketOperator<VectorType>::value,
//                "VectorType does not have an operator[]!");
}


bool TestNegativeLog()
{
  float negativeLog = Helpers::NegativeLog(1.0f);
}

bool TestGetPath()
{

}

bool TestReplaceFileExtension()
{

}

bool TestGetSequentialFileName()
{

}

bool TestSideLengthFromRadius()
{

}

bool TestIsOdd()
{

}

bool TestZeroPad()
{

}

bool TestStringsMatch()
{
  std::string myName = "David";
  std::string myName2 = "David";
  if(!Helpers::StringsMatch(myName, myName2))
  {
    throw std::runtime_error("StringsMatch failed!");
  }
}

bool TestRoundAwayFromZero()
{

}

bool TestRandomInt()
{
  int randomInt = Helpers::RandomInt(1,5);
}


bool TestIsValidRGB()
{
  throw std::runtime_error("TestIsValidRGB() Not yet implemented!");
  return false;
}

bool TestArgmin()
{
  throw std::runtime_error("TestArgmin() Not yet implemented!");
  return false;
}


bool TestArgmax()
{
  throw std::runtime_error("TestArgmax() Not yet implemented!");
  return false;
}

bool TestMaxOfIndex()
{
  throw std::runtime_error("TestMaxOfIndex() Not yet implemented!");
  return false;
}

bool TestMin()
{
  throw std::runtime_error("TestMin() Not yet implemented!");
  return false;
}

bool TestMax()
{
  throw std::runtime_error("TestMax() Not yet implemented!");
  return false;
}

bool TestVectorMedian()
{
  throw std::runtime_error("TestVectorMedian() Not yet implemented!");
  return false;
}

bool TestConvertFrom()
{
  throw std::runtime_error("TestConvertFrom() Not yet implemented!");
  return false;
}

bool TestSum()
{
  throw std::runtime_error("TestSum() Not yet implemented!");
  return false;
}

bool TestVectorSumOfAbsoluteDifferences()
{
  throw std::runtime_error("TestVectorSumOfAbsoluteDifferences() Not yet implemented!");
  return false;
}

bool TestOutputNode()
{
  throw std::runtime_error("TestOutputNode() Not yet implemented!");
  return false;
}

bool TestWriteVectorToFile()
{
  throw std::runtime_error("TestWriteVectorToFile() Not yet implemented!");
  return false;
}

bool TestWriteVectorToFileLines()
{
  throw std::runtime_error("TestWriteVectorToFileLines() Not yet implemented!");
  return false;
}

bool TestOutputFirst()
{
  throw std::runtime_error("TestOutputFirst() Not yet implemented!");
  return false;
}

bool TestExtractFirst()
{
  throw std::runtime_error("TestExtractFirst() Not yet implemented!");
  return false;
}

bool TestContains()
{
  throw std::runtime_error("TestContains() Not yet implemented!");
  return false;
}

bool TestOutput()
{
  throw std::runtime_error("TestOutput() Not yet implemented!");
  return false;
}

bool TestClosestIndex()
{
  throw std::runtime_error("TestClosestIndex() Not yet implemented!");
  return false;
}

bool TestIsNaN()
{
  throw std::runtime_error("TestIsNaN() Not yet implemented!");
  return false;
}

bool TestContainsNaN()
{
  throw std::runtime_error("TestContainsNaN() Not yet implemented!");
  return false;
}

bool TestKeepTopN()
{
  throw std::runtime_error("TestKeepTopN() Not yet implemented!");
  return false;
}

bool TestDoesQueueContain()
{
  throw std::runtime_error("TestDoesQueueContain() Not yet implemented!");
  return false;
}

bool TestDoesStackContain()
{
  throw std::runtime_error("TestDoesStackContain() Not yet implemented!");
  return false;
}

bool TestForce0to255()
{
  throw std::runtime_error("TestForce0to255() Not yet implemented!");
  return false;
}

bool TestHSV_H_Difference()
{
  throw std::runtime_error("TestHSV_H_Difference() Not yet implemented!");
  return false;
}

bool TestFuzzyCompare()
{
  if(!Helpers::FuzzyCompare(1.0, 1.0))
  {
    return false;
  }

  return true;
}
