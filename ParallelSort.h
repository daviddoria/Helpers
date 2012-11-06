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

#ifndef ParallelSort_H
#define ParallelSort_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

/** This class sorts a vector, taking the origin indices along with it, so you can find out which element ended
  * up in each position.
  */
template <typename T>
class ParallelSort
{
public:

  typedef std::vector<T> VectorType;

  struct IndexedValue
  {
    unsigned int index;
    T value;

    bool operator<(IndexedValue elementToCompare) const
    {
      return this->value < elementToCompare.value;
    }
  };

  typedef std::vector<IndexedValue> IndexedVector;

  static IndexedVector ParallelSortAscending(const VectorType& v);

  static IndexedVector ParallelSortDescending(const VectorType& v);

  static IndexedVector CreateInternalData(const VectorType& v);

};

#include "ParallelSort.hpp"

#endif
