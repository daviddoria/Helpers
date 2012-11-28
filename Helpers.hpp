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

#ifndef HELPERS_HPP
#define HELPERS_HPP

// STL
#include <algorithm> // nth_element()
#include <cassert>
#include <fstream>
#include <iostream>
#include <limits>
#include <stdexcept>

#include "TypeTraits.h"
#include "ContainerInterface.h"

namespace Helpers
{

template<typename TA, typename TB>
typename std::enable_if<std::numeric_limits<TA>::is_specialized && std::numeric_limits<TB>::is_specialized, bool>::type
FuzzyCompare(const TA& a, const TB& b, const TA& epsilon)
{
  return std::abs(a - b) < epsilon;
}

template<typename TA, typename TB>
typename std::enable_if<std::numeric_limits<TA>::is_specialized && std::numeric_limits<TB>::is_specialized, bool>::type
FuzzyCompare(const std::vector<TA>& a, const std::vector<TB>& b, const TA& epsilon)
{
  if(a.size() != b.size())
  {
    return false;
  }

  for(unsigned int i = 0; i < a.size(); ++i)
  {
    if(!FuzzyCompare(a[i], b[i], epsilon))
    {
      return false;
    }
  }

  return true;
}

template<typename TA, typename TB>
typename std::enable_if<!(std::numeric_limits<TA>::is_specialized && std::numeric_limits<TB>::is_specialized), bool>::type
FuzzyCompare(const TA& a, const TB& b)
{
  return a == b;
}

template <class T>
bool IsNaN(const T a)
{
  static_assert(std::numeric_limits<T>::has_quiet_NaN,
                "IsNaN can only be used with objects that have a NaN value defined!");

  return a != a;
}

template <class T>
bool ContainsNaN(const T a)
{
  static_assert(std::numeric_limits<typename T::value_type>::has_quiet_NaN,
                "ContainsNaN can only be used with containers whose element type has a NaN value defined!");

  for(unsigned int i = 0; i < a.size(); ++i)
  {
    if(IsNaN(a[i]))
    {
      return true;
    }
  }
  return false;
}

template <class T>
unsigned int Argmin(const T& vec)
{
  typename T::value_type minValue = std::numeric_limits<typename T::value_type>::max();
  unsigned int minLocation = 0;
  for(unsigned int i = 0; i < vec.size(); ++i)
    {
    if(vec[i] < minValue)
      {
      minValue = vec[i];
      minLocation = i;
      }
    }

  return minLocation;
}

template <class T>
unsigned int Argmax(const T& vec)
{
  typename T::value_type maxValue = std::numeric_limits<typename T::value_type>::min();
  unsigned int maxLocation = 0;
  for(unsigned int i = 0; i < vec.size(); ++i)
    {
    if(vec[i] > maxValue)
      {
      maxValue = vec[i];
      maxLocation = i;
      }
    }

  return maxLocation;
}

template<typename TVector>
void NormalizeVectorInPlace(TVector& v)
{
  typedef typename TVector::value_type TComponent;

  static_assert(std::is_floating_point<TComponent>::value,
                "In NormalizeVectorInPlace, TComponent must be floating_point!");

  // Compute the sum of the elements
  TComponent total = static_cast<TComponent>(0);
  for(unsigned int i = 0; i < v.size(); ++i)
  {
    total += v[i] * v[i];
  }

  total = sqrt(total);

  // Divide each element by the sum
  for(unsigned int i = 0; i < v.size(); ++i)
  {
    v[i] /= total;
  }
}

template<typename T>
std::vector<typename TypeTraits<T>::LargerType> NormalizeVector(const std::vector<T>& v)
{
  std::vector<typename TypeTraits<T>::LargerType> normalizedVector(v.size());
  std::copy(v.begin(), v.end(), normalizedVector.begin());
  NormalizeVectorInPlace(normalizedVector);
  return normalizedVector;
}

template<typename T>
typename T::value_type VectorMedian(T v)
{
  // Don't want to pass by reference because the elements are shuffled around.

  int n = v.size() / 2;
  std::nth_element(v.begin(), v.begin()+n, v.end());
  return v[n];
}

template<typename TForwardIterator>
float Sum(const TForwardIterator first, const TForwardIterator last)
{
  float sum = 0.0f;
  for(TForwardIterator iter = first; iter != last; ++iter)
  {
    sum += *iter;
  }

  return sum;
}

template<typename TVector>
float VectorSumOfAbsoluteDifferences(const TVector& a, const TVector& b)
{
  assert(a.size() == b.size());

  float sum = 0.0f;
  for(unsigned int i = 0; i < a.size(); ++i)
  {
    sum += fabs(a[i] - b[i]);
  }

  return sum;
}

template<typename T>
void WriteVectorToFile(const std::vector<T> &v, const std::string& filename)
{
  std::ofstream fout(filename.c_str());

  for(unsigned int i = 0; i < v.size(); ++i)
  {
    fout << v[i] << " ";
  }

  fout.close();
}

template<typename T>
void WriteVectorToFileLines(const std::vector<T> &v, const std::string& filename)
{
  std::ofstream fout(filename.c_str());

  for(unsigned int i = 0; i < v.size(); ++i)
  {
    fout << v[i] << std::endl;
  }

  fout.close();
}

template <typename T>
void OutputFirst(const T& vec)
{
  for(unsigned int i = 0; i < vec.size(); ++i)
  {
    std::cout << vec[i].first << " ";
  }
  std::cout << std::endl;
}

template <typename TPair>
bool SortByFirstAccending(TPair object1, TPair object2)
{
  return object1.first < object2.first;
}

template <typename TPair>
bool SortBySecondAccending(TPair object1, TPair object2)
{
  return object1.second < object2.second;
}

template <typename T>
bool Contains(const std::vector<T>& vec, const T& value)
{
  for(unsigned int i = 0; i < vec.size(); ++i)
  {
    if(vec[i] == value)
    {
      return true;
    }
  }
  return false;
}

template <typename TVector>
void Output(const TVector& vec)
{
  for(unsigned int i = 0; i < vec.size(); ++i)
  {
    std::cout << vec[i] << " ";
  }
  std::cout << std::endl;
}

template <typename TVector>
void Output(const TVector& vec, const std::string& vectorName)
{
  std::cout << vectorName << ":" << std::endl;
  for(unsigned int i = 0; i < vec.size(); ++i)
  {
    std::cout << vec[i] << " ";
  }
  std::cout << std::endl;
}

template <typename TVector>
void OutputInline(const TVector& vec)
{
  for(unsigned int i = 0; i < vec.size(); ++i)
  {
    std::cout << vec[i] << " ";
  }
}

template <typename T1, typename T2>
std::vector<T1> ExtractFirst(const std::vector<std::pair<T1, T2> >& vec)
{
  std::vector<T1> firsts(vec.size());
  for(size_t i = 0; i < vec.size(); ++i)
  {
    firsts[i] = vec[i].first;
  }
  return firsts;
}

template <typename T>
unsigned int ClosestIndex(const std::vector<T>& vec, const T& value)
{
  std::vector<float> distances(vec.size());
  for(size_t i = 0; i < vec.size(); ++i)
  {
    distances[i] = fabs(vec[i] - value);
  }

  return Argmin(distances);
}

template <class T>
typename T::value_type Min(const T& v)
{
  auto minmax = std::minmax_element(v.begin(), v.end());

  return *(minmax.first);
}

template <class T>
typename T::value_type Max(const T& v)
{
  auto minmax = std::minmax_element(v.begin(), v.end());

  return *(minmax.second);
}

template <class TContainer>
typename TypeTraits<typename TContainer::value_type>::ComponentType MinOfIndex(const TContainer& container, const unsigned int index)
{
  // Create a container for the single component
  std::vector<typename TypeTraits<typename TContainer::value_type>::ComponentType> componentContainer(container.size());

  for(size_t i = 0; i < container.size(); ++i)
  {
    componentContainer[i] = container[i][index];
  }

  return Min(componentContainer);
}

template <class TContainer>
typename TypeTraits<typename TContainer::value_type>::ComponentType MaxOfIndex(const TContainer& container, const unsigned int index)
{
  // Create a container for the single component
  std::vector<typename TypeTraits<typename TContainer::value_type>::ComponentType> componentContainer(container.size());

  for(size_t i = 0; i < container.size(); ++i)
  {
    componentContainer[i] = container[i][index];
  }

  return Max(componentContainer);
}

template <class TPriorityQueue>
void KeepTopN(TPriorityQueue& q, const unsigned int numberToKeep)
{
  if(numberToKeep > q.size())
  {
    std::cerr << "Warning: Helpers::KeepTopN requested to keep " << numberToKeep
              << ", but there are only " << q.size() << " nodes." << std::endl;
  }

  TPriorityQueue newQueue;

  unsigned int originalQueueSize = q.size();
  for(unsigned int i = 0; i < std::min(numberToKeep, originalQueueSize); ++i)
  {
    newQueue.push(q.top());
    q.pop();
  }

  q = newQueue;
}

template <class TQueue>
void KeepFrontN(TQueue& q, const unsigned int numberToKeep)
{
  if(numberToKeep > q.size())
  {
    std::cerr << "Warning: Helpers::KeepTopN requested to keep " << numberToKeep
              << ", but there are only " << q.size() << " nodes." << std::endl;
  }

  TQueue newQueue;

  unsigned int originalQueueSize = q.size();
  for(unsigned int i = 0; i < std::min(numberToKeep, originalQueueSize); ++i)
  {
    newQueue.push(q.front());
    q.pop();
  }

  q = newQueue;
}

template <class T>
bool DoesQueueContain(std::queue<T> q, const T& value)
{
  while(!q.empty())
  {
    T element = q.front();
    if(element == value)
    {
      return true;
    }
    q.pop();
  }

  return false;
}

template <class T>
bool DoesStackContain(std::stack<T> s, const T& value)
{
  while(!s.empty())
  {
    T element = s.top();
    if(element == value)
    {
      return true;
    }
    s.pop();
  }

  return false;
}

template <class T>
bool IsValidRGB(const T r, const T g, const T b)
{
  if(r > 255.0f || r < 0.0f || g > 255.0f || g < 0.0f || b > 255.0f || b < 0.0f)
  {
    return false;
  }
  return true;
}

template <class T>
T Force0to255(const T& value)
{
  T returnValue = value;

  if(value < 0)
  {
    returnValue = 0;
  }
  else if(value > 255)
  {
    returnValue = 255;
  }

  return returnValue;
}

template <class TValue>
typename TypeTraits<TValue>::LargerType WeightedAverage(const std::vector<TValue>& values,
                                                        const std::vector<float>& weights)
{
  assert(values.size() == weights.size());

  //TValue weightedSum = TypeTraits<TValue>::Zero();

  // Get the component type and length correct by first assigning weightedSum to one of the 'values',
  // then zeroing it.
  typename TypeTraits<TValue>::LargerType weightedSum = values[0];
  weightedSum = 0;

  typename TypeTraits<TValue>::LargerType weightSum = 0.0f;
  for(unsigned int i = 0; i < weights.size(); ++i)
  {
    weightSum += weights[i];
    //weightedSum += weight * values[i];
    // itk::CovariantVector requires this direction of multiplication
    weightedSum += static_cast<typename TypeTraits<TValue>::LargerType>(values[i]) * weights[i]; 
  }

  typename TypeTraits<TValue>::LargerType weightedAverage = weightedSum / weightSum;

  return weightedAverage;
}

template <typename TContainer, typename TOutput>
void MinOfAllIndices(const TContainer& container, TOutput& output,
                     typename std::enable_if<!std::is_pod<TOutput>::value >::type*)
{
  // Create a container for a single component
  for(unsigned int component = 0; component < length(container[0]); ++component)
  {
    output[component] = MinOfIndex(container, component);
  }
}

template <typename TContainer, typename TOutput>
void MinOfAllIndices(const TContainer& container, TOutput& output,
                     typename std::enable_if<std::is_pod<TOutput>::value >::type*)
{
  output = Min(container);
}

template <typename TContainer, typename TOutput>
void MaxOfAllIndices(const TContainer& container, TOutput& output,
                     typename std::enable_if<!std::is_pod<TOutput>::value >::type*)
{
  // We cannot return the 'output' because it must be pre-sized and passed in because the
  // sizing procedure is very different for different containers (std::vector, itk::CovariantVector, etc)

  // Create a container for a single component
  for(unsigned int component = 0; component < length(container[0]); ++component)
  {
    output[component] = MaxOfIndex(container, component);
  }
}

template <typename TContainer, typename TOutput>
void MaxOfAllIndices(const TContainer& container, TOutput& output,
                     typename std::enable_if<std::is_pod<TOutput>::value >::type*)
{
  output = Max(container);
}

}// end Helpers namespace

template <typename TComponent>
std::ostream& operator<<(std::ostream& output, const std::vector<TComponent>& vec)
{
  for(unsigned int i = 0; i < vec.size(); ++i)
  {
    output << vec[i] << " ";
  }

  return output;
}

#endif
