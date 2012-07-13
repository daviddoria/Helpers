#ifndef PARALLELSORT_H
#define PARALLELSORT_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

/** This class sorts a vector, taking the origin indices along with it, so you can find out which element ended
  * up in each position.
  */
namespace ParallelSort
{

template <typename T>
struct IndexedValue
{
  unsigned int index;
  T value;
};

template <typename T>
bool operator<(IndexedValue<T> element1, IndexedValue<T> element2);

template <typename T>
std::vector<IndexedValue<T> > ParallelSortAscending(const std::vector<T>& v);

template <typename T>
std::vector<IndexedValue<T> > ParallelSortDescending(const std::vector<T>& v);

template <typename T>
std::vector<IndexedValue<T> > CreateInternalData(const std::vector<T>& v);

} // end namespace

#include "ParallelSort.hpp"

#endif
