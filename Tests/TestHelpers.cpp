#include "Helpers.h"

void TestGetFileExtension();

int main()
{
  TestGetFileExtension();
  
  return 0;
}

void TestGetFileExtension()
{
  std::string filename = "test.txt";
  std::string extension = Helpers::GetFileExtension(filename);

  std::cout << "extension: " << extension << std::endl;
}
