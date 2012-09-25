#include "Helpers.h"

// STL
#include <sstream>

static void TestGetFileExtension();

static void TestSortBySecondAccending();

static void TestInlineIgnore();

static void TestWeightedAverage();

static void TestNormalizeVectorInPlace();

static void TestNormalizeVector();

static void TestMinOfIndex();

static void TestMinOfAllIndices();

static void TestSphericalToCartesian();
static void TestCartesianToSpherical();

int main()
{
  TestGetFileExtension();

  TestSortBySecondAccending();

  TestInlineIgnore();

  TestWeightedAverage();

  TestNormalizeVectorInPlace();

  TestNormalizeVector();

  TestMinOfIndex();

  TestMinOfAllIndices();

  TestSphericalToCartesian();
  TestCartesianToSpherical();

  return 0;
}

void TestNormalizeVector()
{
  std::cout << "TestNormalizeVector()" << std::endl;
  {
  std::vector<float> a;
  a.push_back(1);
  a.push_back(2);
  a.push_back(3);

  std::vector<float> normalized = Helpers::NormalizeVector(a);
  }

  {
  std::vector<int> a;
  a.push_back(1);
  a.push_back(2);
  a.push_back(3);

  std::vector<float> normalized = Helpers::NormalizeVector(a);
  }
}

void TestNormalizeVectorInPlace()
{
  std::cout << "TestNormalizeVectorInPlace()" << std::endl;
  {
  std::vector<float> a;
  a.push_back(1);
  a.push_back(2);
  a.push_back(3);

  Helpers::NormalizeVectorInPlace(a);
  }

}

void TestGetFileExtension()
{
  std::cout << "TestGetFileExtension()" << std::endl;
  std::string filename = "test.txt";
  std::string extension = Helpers::GetFileExtension(filename);

  std::cout << "extension: " << extension << std::endl;
}

void TestSortBySecondAccending()
{
  std::cout << "TestSortBySecondAccending()" << std::endl;
  typedef std::pair<int, float> MyType;
  std::vector<MyType> v{
        {1, 4.5}, {3, 6.7}, {9, 7.8}
  };

  std::sort(v.begin(), v.end(), Helpers::SortBySecondAccending<MyType>);
}

void TestInlineIgnore()
{
  std::cout << "TestInlineIgnore()" << std::endl;
  std::stringstream ss;
  ss << "1 : 2";
  int a,b;

  ss >> a >> Helpers::InlineIgnore >> b;

  std::cout << a << " " << b << std::endl;
}

void TestWeightedAverage()
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

void TestMinOfIndex()
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

void TestMinOfAllIndices()
{
  std::cout << "TestMinOfAllIndices()" << std::endl;
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

void TestSphericalToCartesian()
{
  std::cout << "TestSphericalToCartesian()" << std::endl;
  double r = 1.0;
  double theta = 0.0;
  double phi = 0.0;

  double x, y, z;

  Helpers::SphericalToCartesian(x, y, z, r, theta, phi);

  std::cout << "Spherical: r=" << r << " theta=" << theta << " phi=" << phi
            << " to Cartesian: x=" << x << " y=" << y << " z=" << z << std::endl;
}

void TestCartesianToSpherical()
{
  std::cout << "TestCartesianToSpherical()" << std::endl;
  double r, theta, phi;

  double x = 0.0;
  double y = 0.0;
  double z = 1.0;

  Helpers::CartesianToSpherical(r, theta, phi, x, y, z);

  std::cout << "Cartesian: x=" << x << " y=" << y << " z=" << z
            << " to Spherical: r=" << r << " theta=" << theta << " phi=" << phi  << std::endl;

}
