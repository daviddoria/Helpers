/*=========================================================================
 *
 *  Copyright David Doria 2011 daviddoria@gmail.com
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

#ifndef ContainerInterface_HPP
#define ContainerInterface_HPP

#include "ContainerInterface.h"

namespace Helpers
{

// Index functions
template<typename T>
typename std::enable_if<std::is_fundamental<T>::value, T&>::type
index(T& t, const size_t)
{
  return t;
}

template<typename T>
typename std::enable_if<std::is_fundamental<T>::value, T>::type
index(const T& t, const size_t)
{
  return t;
}

template<typename T>
typename std::enable_if<!std::is_fundamental<T>::value, typename T::value_type&>::type
index(T& v, const size_t i)
{
  return v[i];
}

template<typename T>
typename std::enable_if<!std::is_fundamental<T>::value, typename T::value_type>::type
index(const T& v, const size_t i)
{
  return v[i];
}

// Length functions
template<typename T>
typename std::enable_if<std::is_fundamental<T>::value, unsigned int>::type
length(const T& )
{
  return 1;
}

template<typename T>
unsigned int length(const std::vector<T>& v)
{
  return v.size();
}

} // end namespace

#endif
