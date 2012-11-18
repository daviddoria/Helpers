#include "Helpers.h"

// STL
#include <sstream>
#include <limits>

static bool TestFuzzyCompare();

static bool TestGetFileExtension();

static bool TestMin();
static bool TestMax();

static bool TestSortBySecondAccending();
static bool TestSortByFirstAccending();

static bool TestInlineIgnore();

static bool TestWeightedAverage();

static bool TestNormalizeVectorInPlace_Float();
static bool TestNormalizeVectorInPlace_Int();

static bool TestNormalizeVector_Float();
static bool TestNormalizeVector_Int();

static bool TestMinOfIndex();

static bool TestMinOfAllIndices_Vector();
static bool TestMinOfAllIndices_Scalar();

static bool TestMaxOfAllIndices_Vector();
static bool TestMaxOfAllIndices_Scalar();

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

static bool TestSum();

static bool TestVectorSumOfAbsoluteDifferences();

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

static bool TestKeepFrontN();

static bool TestDoesQueueContain();

static bool TestDoesStackContain();

static bool TestForce0to255();

static bool TestHSV_H_Difference();

int main()
{
  bool AllTestsPass = true;

  AllTestsPass &= TestFuzzyCompare();

  AllTestsPass &= TestGetFileExtension();

  AllTestsPass &= TestSortBySecondAccending();
  AllTestsPass &= TestSortByFirstAccending();

  AllTestsPass &= TestInlineIgnore();

  AllTestsPass &= TestWeightedAverage();

  AllTestsPass &= TestNormalizeVectorInPlace_Int();
  AllTestsPass &= TestNormalizeVectorInPlace_Float();

  AllTestsPass &= TestNormalizeVector_Int();
  AllTestsPass &= TestNormalizeVector_Float();

  AllTestsPass &= TestMinOfIndex();

  AllTestsPass &= TestMinOfAllIndices_Vector();
  AllTestsPass &= TestMinOfAllIndices_Scalar();

  AllTestsPass &= TestMaxOfAllIndices_Vector();
  AllTestsPass &= TestMaxOfAllIndices_Scalar();

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

  AllTestsPass &= TestSum();

  AllTestsPass &= TestVectorSumOfAbsoluteDifferences();

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

  AllTestsPass &= TestKeepFrontN();

  AllTestsPass &= TestDoesQueueContain();

  AllTestsPass &= TestDoesStackContain();

  AllTestsPass &= TestForce0to255();

  AllTestsPass &= TestHSV_H_Difference();

  if(AllTestsPass)
  {
    std::cerr << "All tests passed!" << std::endl;
    return EXIT_SUCCESS;
  }
  else
  {
    std::cerr << "Not all tests passed!" << std::endl;
    return EXIT_FAILURE;
  }
}

bool TestNormalizeVector_Int()
{
  std::cout << "TestNormalizeVector_Int()" << std::endl;

  std::vector<int> a = {1,2,3};

  std::vector<float> normalized = Helpers::NormalizeVector(a);
  // Octave: a=[1 2 3]; b=a/norm(a)
  std::vector<float> correctAnswer = {0.26726, 0.53452, 0.80178};
  bool pass = Helpers::FuzzyCompare(normalized, correctAnswer, 1e-4f);

  if(!pass)
  {
    std::cerr << "TestNormalizeVector_Int failed!" << std::endl;
    return false;
  }

  return true;
}

bool TestNormalizeVector_Float()
{
  std::cout << "TestNormalizeVector_Float()" << std::endl;

  std::vector<float> a = {1,2,3};

  std::vector<float> normalized = Helpers::NormalizeVector(a);
  // Octave: a=[1 2 3]; b=a/norm(a)
  std::vector<float> correctAnswer = {0.26726, 0.53452, 0.80178};
  bool pass = Helpers::FuzzyCompare(normalized, correctAnswer, 1e-4f);

  if(!pass)
  {
    std::cerr << "TestNormalizeVector_Float failed!" << std::endl;
    return false;
  }

  return true;
}

bool TestNormalizeVectorInPlace_Int()
{
  // This should fail to compile because of a static assertion
  // to make sure that the vector being normalized has a floating
  // point component type

//  std::cout << "TestNormalizeVectorInPlace_Int()" << std::endl;

//  std::vector<int> a;
//  a.push_back(1);
//  a.push_back(2);
//  a.push_back(3);

//  Helpers::NormalizeVectorInPlace(a);

//  // Octave: a=[1 2 3]; b=a/norm(a)
//  std::vector<float> correctAnswer = {0.26726, 0.53452, 0.80178};

//  bool pass = Helpers::FuzzyCompare(a, correctAnswer);

//  if(!pass)
//  {
//    std::cerr << "TestNormalizeVectorInPlace_Int failed!" << std::endl;
//  }

//  return pass;

  return true;
}

bool TestNormalizeVectorInPlace_Float()
{
  std::cout << "TestNormalizeVectorInPlace_Float()" << std::endl;

  std::vector<float> a = {1,2,3};

  Helpers::NormalizeVectorInPlace(a);

  // Octave: a=[1 2 3]; b=a/norm(a)
  std::vector<float> correctAnswer = {0.26726, 0.53452, 0.80178};

  bool pass = Helpers::FuzzyCompare(a, correctAnswer, 1e-4f);

  if(!pass)
  {
    std::cerr << "TestNormalizeVectorInPlace_Float failed!"
              << " result was: " << a[0] << " " << a[1] << " " << a[2]
              << " but should have been "
              << correctAnswer[0] << " " << correctAnswer[1] << " " << correctAnswer[2]
              << std::endl;
  }

  return pass;
}

bool TestGetFileExtension()
{
  std::cout << "TestGetFileExtension()" << std::endl;
  std::string filename = "test.txt";
  std::string extension = Helpers::GetFileExtension(filename);

//  std::cout << "extension: " << extension << std::endl;

  if(!Helpers::StringsMatch(extension, "txt"))
  {
    std::cerr << "TestGetFileExtension failed!" << std::endl;
    return false;
  }

  return true;
}

bool TestSortByFirstAccending()
{
  std::cout << "TestSortByFirstAccending()" << std::endl;
  typedef std::pair<int, float> MyType;
  std::vector<MyType> v{
        {3, 6.7}, {1, 4.5}, {9, 7.8}
  };

  std::sort(v.begin(), v.end(), Helpers::SortByFirstAccending<MyType>);

  std::vector<int> correct = {1,3,9};
  for(unsigned int i = 0; i < correct.size(); ++i)
  {
    if(correct[i] != v[i].first)
    {
      std::cerr << "TestSortByFirstAccending failed!" << std::endl;
      return false;
    }
  }

  return true;
}

bool TestSortBySecondAccending()
{
  std::cout << "TestSortBySecondAccending()" << std::endl;
  typedef std::pair<int, int> MyType;
  std::vector<MyType> v{
        {3, 6}, {1, 4}, {9, 7}
  };

  std::sort(v.begin(), v.end(), Helpers::SortBySecondAccending<MyType>);

  std::vector<int> correct = {4,6,7};
  for(unsigned int i = 0; i < correct.size(); ++i)
  {
    if(correct[i] != v[i].second)
    {
      std::cerr << "TestSortBySecondAccending failed!" << std::endl;
      return false;
    }
  }

  return true;
}

bool TestInlineIgnore()
{
  std::cout << "TestInlineIgnore()" << std::endl;
  std::stringstream ss;
  ss << "1 : 2";
  int a,b;

  ss >> a >> Helpers::InlineIgnore >> b;

//  std::cout << a << " " << b << std::endl;
  if((a != 1) || (b != 2) )
  {
    std::cerr << "TestInlineIgnore failed!" << std::endl;
    return false;
  }

  return true;
}

bool TestWeightedAverage()
{
  std::cout << "TestWeightedAverage()" << std::endl;
  std::vector<int> values = {1,2,3};

  std::vector<float> weights = {1,1,2};

  float weightedAverage = Helpers::WeightedAverage(values, weights);

//octave:1> (1+2+3*2)/4
//ans =  2.2500

//  std::cout << "WeightedAverage: " << weightedAverage << std::endl;

  float correct = 2.25;

  if(weightedAverage != correct)
  {
    std::cerr << "TestWeightedAverage failed: was " << weightedAverage <<
                 " but should have been " << correct << "!" << std::endl;
    return false;
  }

  return true;
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

//  std::cout << "minComponent2: " << minComponent2 << std::endl;

  if(minComponent2 != 4)
  {
    std::cerr << "TestMinOfIndex failed!" << std::endl;
    return false;
  }

  return true;
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

//  std::cout << "maxComponents: ";
//  for(size_t i = 0; i < maxComponents.size(); ++i)
//  {
//    std::cout << maxComponents[i] << std::endl;
//  }

  for(size_t i = 0; i < maxComponents.size(); ++i)
  {
    if(maxComponents[i] != 9)
    {
      std::cerr << "TestMaxOfAllIndices_Vector failed!" << std::endl;
      return false;
    }
  }

  return true;
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

//  std::cout << "maxValue: " << maxValue << std::endl;
  if(maxValue != 9)
  {
    std::cerr << "TestMaxOfAllIndices_Scalar failed!" << std::endl;
    return false;
  }

  return true;
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

//  std::cout << "minComponents: ";
//  for(size_t i = 0; i < minComponents.size(); ++i)
//  {
//    std::cout << minComponents[i] << std::endl;
//  }

  for(size_t i = 0; i < minComponents.size(); ++i)
  {
    if(minComponents[i] != 4)
    {
      std::cerr << "TestMinOfAllIndices_Vector failed!" << std::endl;
      return false;
    }
  }

  return true;
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

//  std::cout << "minValue: " << minValue << std::endl;
  if(minValue != 4)
  {
    std::cerr << "TestMinOfAllIndices_Scalar failed!" << std::endl;
    return false;
  }

  return true;
}

bool TestHasBracketOperator()
{
  static_assert(Helpers::HasBracketOperator<std::vector<float> >::value,
                "std::vector<float> does not have an operator[]!");

  static_assert(Helpers::HasBracketOperator<std::vector<int> >::value,
                "std::vector<int> does not have an operator[]!");

  return true;
}


bool TestNegativeLog()
{
  float negativeLog = Helpers::NegativeLog(1.0f);

  bool pass = Helpers::FuzzyCompare(negativeLog, 0.0f);

  if(!pass)
  {
    std::cerr << "TestMinOfAllIndices_Scalar failed!" << std::endl;
  }

  return pass;
}

bool TestGetPath()
{
  std::string path = Helpers::GetPath("/home/doriad/Test/file.png");
  if(!Helpers::StringsMatch(path, "/home/doriad/Test/"))
  {
    std::cerr << "TestGetPath failed!" << std::endl;
    return false;
  }

  return true;
}

bool TestReplaceFileExtension()
{
  std::string newFile = Helpers::ReplaceFileExtension("/home/doriad/Test/file.png", "jpg");
  if(!Helpers::StringsMatch(newFile, "/home/doriad/Test/file.jpg"))
  {
    std::cerr << "TestReplaceFileExtension failed!" << std::endl;
    return false;
  }

  return true;
}

bool TestGetSequentialFileName()
{
  std::string fileName = Helpers::GetSequentialFileName("Test", 2, "png", 3);
  if(!Helpers::StringsMatch(fileName, "Test_002.png"))
  {
    std::cerr << "TestGetSequentialFileName failed!" << std::endl;
    return false;
  }

  return true;
}

bool TestSideLengthFromRadius()
{
  unsigned int sideLength = Helpers::SideLengthFromRadius(2);
  if(sideLength != 5)
  {
    std::cerr << "TestSideLengthFromRadius failed!" << std::endl;
    return false;
  }

  return true;
}

bool TestIsOdd()
{
  if(!Helpers::IsOdd(3) ||
     Helpers::IsOdd(4))
  {
    std::cerr << "TestIsOdd failed!" << std::endl;
    return false;
  }

  return true;
}

bool TestZeroPad()
{
  std::string padded = Helpers::ZeroPad(3, 4);
  if(!Helpers::StringsMatch("0003", padded))
  {
    std::cerr << "TestZeroPad failed!" << std::endl;
    return false;
  }

  return true;
}

bool TestStringsMatch()
{
  std::string myName = "David";
  std::string myName2 = "David";
  if(!Helpers::StringsMatch(myName, myName2))
  {
    std::cerr << "TestStringsMatch failed!" << std::endl;
    return false;
  }

  return true;
}

bool TestRoundAwayFromZero()
{
  bool allPass = true;

  float roundedPositive = Helpers::RoundAwayFromZero(2.1f);
  float correctPositive = 3.0f;
  if(roundedPositive != correctPositive)
  {
    std::cerr << "TestRoundAwayFromZero roundedPositive was " << roundedPositive
              << " but should have been " << correctPositive << "!" << std::endl;
    allPass = false;
  }

  float roundedNegative = Helpers::RoundAwayFromZero(-2.1f);
  float correctNegative = -3.0f;
  if(roundedNegative != correctNegative)
  {
    std::cerr << "TestRoundAwayFromZero roundedNegative was " << roundedNegative
              << " but should have been " << roundedNegative << "!" << std::endl;
    allPass = false;
  }

  if(!allPass)
  {
    std::cerr << "TestRoundAwayFromZero failed!" << std::endl;
    return false;
  }

  return true;
}

bool TestRandomInt()
{
  // Generate 100 random numbers and make sure they are all in the correct range
  int min = 1;
  int max = 5;
  for(unsigned int i = 0; i < 100; ++i)
  {
    int randomInt = Helpers::RandomInt(min,max);
    if(randomInt < min || randomInt > max)
    {
      std::cerr << "TestRandomInt failed!" << std::endl;
      return false;
    }
  }

  return true;
}


bool TestIsValidRGB()
{
  if(!Helpers::IsValidRGB(2,3,4) ||
     Helpers::IsValidRGB(-1,3,4) ||
     Helpers::IsValidRGB(256,3,4) )
  {
    std::cerr << "TestIsValidRGB failed!" << std::endl;
    return false;
  }

  return true;
}

bool TestArgmin()
{
  std::vector<int> v = {4,2,0,1,6};

  unsigned int minPosition = Helpers::Argmin(v);
  if(minPosition != 2)
  {
    std::cerr << "TestArgmin failed!" << std::endl;
    return false;
  }
  return true;
}


bool TestArgmax()
{
  std::vector<int> v = {4,2,0,1,7,5,1};

  unsigned int maxPosition = Helpers::Argmax(v);
  if(maxPosition != 4)
  {
    std::cerr << "TestArgmax failed!" << std::endl;
    return false;
  }
  return true;
}

bool TestMaxOfIndex()
{
  std::cout << "TestMaxOfIndex()" << std::endl;
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

  VectorType::value_type maxOfIndex2 = Helpers::MaxOfIndex(vectorOfVectors, 2);

  if(maxOfIndex2 != 9)
  {
    std::cerr << "TestMaxOfIndex failed!" << std::endl;
    return false;
  }

  return true;
}

bool TestMin()
{
  std::vector<int> v = {4,3,2};

  if(Helpers::Min(v) != 2)
  {
    std::cerr << "TestMin failed!" << std::endl;
    return false;
  }

  return true;
}

bool TestMax()
{
  std::vector<int> v = {4,3,2};

  if(Helpers::Max(v) != 4)
  {
    std::cerr << "TestMax failed!" << std::endl;
    return false;
  }

  return true;
}

bool TestVectorMedian()
{
  std::vector<int> v = {4,3,2};

  if(Helpers::VectorMedian(v) != 3)
  {
    std::cerr << "TestVectorMedian failed!" << std::endl;
    return false;
  }

  return true;
}


bool TestSum()
{
  std::vector<int> v = {4,3,2};

  if(Helpers::Sum(v.begin(), v.end()) != 9)
  {
    std::cerr << "TestSum failed!" << std::endl;
    return false;
  }

  return true;
}

bool TestVectorSumOfAbsoluteDifferences()
{
  std::vector<int> a = {1,2,3};
  std::vector<int> b = {1,3,4};
  if(Helpers::VectorSumOfAbsoluteDifferences(a,b) != 2)
  {
    std::cerr << "TestVectorSumOfAbsoluteDifferences failed!" << std::endl;
    return false;
  }
  return true;
}

bool TestWriteVectorToFile()
{
  std::vector<int> v = {1,2,3};
  Helpers::WriteVectorToFile(v, "file.txt");
  return true;
}

bool TestWriteVectorToFileLines()
{
  std::vector<int> v = {1,2,3};
  Helpers::WriteVectorToFileLines(v, "file.txt");
  return true;
}

bool TestOutputFirst()
{
  std::vector<std::pair<int, int> > v = {{1,2}, {3,4}};
  Helpers::OutputFirst(v);
  return true;
}

bool TestExtractFirst()
{
  std::vector<std::pair<int, int> > v = {{1,2}, {3,4}};
  std::vector<int> firsts = Helpers::ExtractFirst(v);
  for(unsigned int i = 0; i < firsts.size(); ++i)
  {
    if(firsts[i] != v[i].first)
    {
      std::cerr << "TestExtractFirst failed!" << std::endl;
      return false;
    }
  }
  return true;
}

bool TestContains()
{
  std::vector<int> v = {1,2,3};
  if(!Helpers::Contains(v, 1) ||
     Helpers::Contains(v, 4))
  {
    std::cerr << "TestContains failed!" << std::endl;
    return false;
  }

  return true;
}

bool TestOutput()
{
  std::vector<int> v = {1,2,3};
  Helpers::Output(v);
  return true;
}

bool TestClosestIndex()
{
  std::vector<float> v = {3.1f, 4.1f, 5.1f};
  unsigned int closestIndex = Helpers::ClosestIndex(v, 4.0f);
  if(closestIndex != 1)
  {
    std::cerr << "TestClosestIndex failed!" << std::endl;
    return false;
  }

  return true;
}

bool TestIsNaN()
{
  if(Helpers::IsNaN(1.0f) ||
     !Helpers::IsNaN(std::numeric_limits<float>::quiet_NaN()))
  {
    std::cerr << "TestIsNaN failed!" << std::endl;
    return false;
  }

  return true;
}

bool TestContainsNaN()
{
  // This intentionally fails - we cannot use NaN with 'int' values.
//  std::vector<int> v_noNaN = {1,2,3};
//  bool containsNaN = Helpers::ContainsNaN(v_noNaN);

  bool pass = true;

  // Check correctly contains NaN
  std::vector<float> v_NaN = {1,std::numeric_limits<float>::quiet_NaN(),3};

  if(!Helpers::ContainsNaN(v_NaN))
  {
    std::cerr << "TestContainsNaN failed: v_NaN was said to not contain a NaN but it does!" << std::endl;
    pass = false;
  }

  // Check correctly does not contain NaN
  std::vector<float> v_noNaN = {1,2,3};

  if(Helpers::ContainsNaN(v_noNaN))
  {
    std::cerr << "TestContainsNaN failed: v_NaN was said to not contain a NaN but it does!" << std::endl;
    pass = false;
  }

  return pass;
}

bool TestKeepFrontN()
{
  std::queue<int> q;
  q.push(0);
  q.push(1);
  q.push(2);

  Helpers::KeepFrontN(q, 2);

  unsigned int counter = 0;
  while(!q.empty())
  {
    q.pop();
    counter++;
  }

  if(counter != 2)
  {
    std::cerr << "TestKeepFrontN failed!" << std::endl;
    return false;
  }

  return true;
}

bool TestKeepTopN()
{
  std::priority_queue<int> q;
  q.push(0);
  q.push(1);
  q.push(2);

  Helpers::KeepTopN(q, 2);

  unsigned int counter = 0;
  while(!q.empty())
  {
    q.pop();
    counter++;
  }

  if(counter != 2)
  {
    std::cerr << "TestKeepTopN failed!" << std::endl;
    return false;
  }

  return true;
}

bool TestDoesQueueContain()
{
  std::queue<int> q;
  q.push(0);
  q.push(1);
  q.push(2);

  if(!Helpers::DoesQueueContain(q, 1) ||
     Helpers::DoesQueueContain(q, 3))
  {
    std::cerr << "TestDoesQueueContain failed!" << std::endl;
    return false;
  }

  return true;
}

bool TestDoesStackContain()
{
  std::stack<int> s;
  s.push(0);
  s.push(1);
  s.push(2);

  if(Helpers::DoesStackContain(s, 3) ||
     !Helpers::DoesStackContain(s, 0))
  {
    std::cerr << "TestDoesStackContain failed!" << std::endl;
    return false;
  }

  return true;
}

bool TestForce0to255()
{
  if(Helpers::Force0to255(-1) != 0 ||
     Helpers::Force0to255(257) != 255 ||
     Helpers::Force0to255(4) != 4)
  {
    std::cerr << "TestForce0to255 failed!" << std::endl;
    return false;
  }

  return true;
}

bool TestHSV_H_Difference()
{
  Helpers::HSV_H_Difference hDifferenceFunctor;
  float hDifference = hDifferenceFunctor(.9, .1);

  if(hDifference != .2f)
  {
    std::cerr << "TestHSV_H_Difference failed!" << std::endl;
    return false;
  }

  return true;
}

bool TestFuzzyCompare()
{
  if(!Helpers::FuzzyCompare(1.0, 1.0) ||
     Helpers::FuzzyCompare(1.0, 2.0))
  {
    std::cerr << "TestFuzzyCompare failed!" << std::endl;
    return false;
  }

  return true;
}
