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

#ifndef TypeTraits_H
#define TypeTraits_H

// STL
#include <vector>

/** For generic types (assume they are scalars). Specializations will have to deal
  * with the cases that are not. */
template <class T>
struct TypeTraits
{
  typedef T LargerType;
  typedef T LargerComponentType;
  typedef T ComponentType;
};

/** For unsigned char, use float as the LargerType. This is an explicit specialization -
  * that is this is no longer a template. */
template <>
struct TypeTraits<unsigned char>
{
  typedef float LargerType;
  typedef float LargerComponentType;
  typedef unsigned char ComponentType;
};

/** For int, use float as the LargerType. This is an explicit specialization -
  * that is this is no longer a template. */
template <>
struct TypeTraits<int>
{
  typedef float LargerType;
  typedef float LargerComponentType;
  typedef int ComponentType;
};

/** For unsigned int, use float as the LargerType. This is an explicit specialization -
  * that is this is no longer a template. */
template <>
struct TypeTraits<unsigned int>
{
  typedef float LargerType;
  typedef float LargerComponentType;
  typedef unsigned int ComponentType;
};

/** For generic std::vector. This is a partial specialization (TypeTraits is still a template here),
  * as we allow the vector template parameter to be specified. */
template <typename T>
struct TypeTraits<std::vector<T> >
{
  typedef std::vector<T> LargerType;
  typedef typename TypeTraits<T>::LargerType LargerComponentType;
  typedef T ComponentType;
};

#endif
