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

// STL
#include <algorithm> // nth_element()
#include <fstream>
#include <iostream>
#include <limits>

namespace Helpers
{

template <class T>
bool IsNaN(const T a)
{
  return a != a;
}

template <class T>
bool ContainsNaN(const T a)
{
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
unsigned int argmin(const T& vec)
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
unsigned int argmax(const T& vec)
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

template<typename T>
void NormalizeVectorInPlace(std::vector<T>& v)
{
  T total = static_cast<T>(0);
  for(unsigned int i = 0; i < v.size(); ++i)
    {
    total += v[i];
    }

  for(unsigned int i = 0; i < v.size(); ++i)
    {
    v[i] /= total;
    }
}

template<typename T>
std::vector<T> NormalizeVector(const std::vector<T>& v)
{
  std::vector<T> normalizedVector;
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

template<typename TTo, typename TFrom>
TTo ConvertFrom(const TFrom& object)
{
  TTo t;
  t[0] = object[0];
  t[1] = object[1];
  return t;
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

template<typename TNode>
void OutputNode(const TNode& a)
{
  std::cout << "(" << a[0] << ", " << a[1] << ")" << std::endl;
}

template<typename T>
void WriteVectorToFile(const std::vector<T> &v, const std::string& filename)
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

template <typename T>
void Output(const std::vector<T>& vec)
{
  for(unsigned int i = 0; i < vec.size(); ++i)
  {
    std::cout << vec[i] << " ";
  }
  std::cout << std::endl;
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

  return argmin(distances);
}

template <class T>
typename T::value_type min(const T& v)
{
  auto minmax = std::minmax_element(v.begin(), v.end());

  return *(minmax.first);
}

template <class T>
typename T::value_type max(const T& v)
{
  auto minmax = std::minmax_element(v.begin(), v.end());

  return *(minmax.second);
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
TValue WeightedSum(const std::vector<TValue>& values, const std::vector<float>& weights)
{
  assert(values.size() == weights.size());

  //TValue weightedSum = TypeTraits<TValue>::Zero();

  // Get the component type and length correct by first assigning weightedSum to one of the 'values', then zeroing it.
  TValue weightedSum = values[0];
  weightedSum = 0;

  //float scoreSum = Helpers::Sum(contributingScores.begin(), contributingScores.end());
  float maxScore = *(std::min_element(weights.begin(), weights.end()));
  float weightSum = 0.0f;
  for(unsigned int i = 0; i < weights.size(); ++i)
  {
    //float weight = (scoreSum - contributingScores[i]);
    float weight = (maxScore - weights[i]);
    weightSum += weight;
    weightedSum += weight * values[i];
  }

  weightedSum /= weightSum;

  return weightedSum;
}

}// end namespace
