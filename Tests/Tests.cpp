#include "Helpers.h"

static void TestGetFileExtension();

static void TestSortBySecondAccending();

int main()
{
  //TestGetFileExtension();

  TestSortBySecondAccending();
  
  return 0;
}

void TestGetFileExtension()
{
  std::string filename = "test.txt";
  std::string extension = Helpers::GetFileExtension(filename);

  std::cout << "extension: " << extension << std::endl;
}

void TestSortBySecondAccending()
{
  typedef std::pair<int, float> MyType;
  std::vector<MyType> v{
        {1, 4.5}, {3, 6.7}, {9, 7.8}
  };

  std::sort(v.begin(), v.end(), Helpers::SortBySecondAccending<MyType>);
}