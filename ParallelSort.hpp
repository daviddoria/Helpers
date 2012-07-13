#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

namespace ParallelSort
{

template <typename T>
bool operator<(IndexedValue<T> element1, IndexedValue<T> element2)
{
  return element1.value < element2.value;
}

template <typename T>
std::vector<IndexedValue<T> > CreateInternalData(const std::vector<T>& v)
{
  std::vector<IndexedValue<T> > pairs(v.size());
  for(unsigned int i = 0; i < v.size(); i++)
    {
    pairs[i].index = i;
    pairs[i].value = v[i];
    }
  return pairs;
}

template <typename T>
std::vector<IndexedValue<T> > ParallelSortAscending(const std::vector<T>& v)
{
  std::vector<IndexedValue<T> > internalData = CreateInternalData(v);

  std::sort(internalData.begin(), internalData.end());

  return internalData;
}

template <typename T>
std::vector<IndexedValue<T> > ParallelSortDescending(const std::vector<T>& v)
{
  std::vector<IndexedValue<T> > internalData = CreateInternalData(v);

  std::sort(internalData.rbegin(), internalData.rend());

  return internalData;
}

} // end namespace
