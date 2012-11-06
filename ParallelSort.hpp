/*=========================================================================
 *
 *  Copyright David Doria 2012 daviddoria@gmail.com
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *         http://www.apache.org/licenses/LICENSE-2.0.txt
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *=========================================================================*/

#ifndef ParallelSort_HPP
#define ParallelSort_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

template <typename T>
typename ParallelSort<T>::IndexedVector ParallelSort<T>::CreateInternalData(const VectorType& v)
{
  IndexedVector pairs(v.size());
  for(unsigned int i = 0; i < v.size(); i++)
    {
    pairs[i].index = i;
    pairs[i].value = v[i];
    }
  return pairs;
}

template <typename T>
typename ParallelSort<T>::IndexedVector ParallelSort<T>::ParallelSortAscending(const VectorType& v)
{
  IndexedVector internalData = CreateInternalData(v);

  std::sort(internalData.begin(), internalData.end());

  return internalData;
}

template <typename T>
typename ParallelSort<T>::IndexedVector ParallelSort<T>::ParallelSortDescending(const VectorType& v)
{
  IndexedVector internalData = CreateInternalData(v);

  std::sort(internalData.rbegin(), internalData.rend());

  return internalData;
}

#endif
