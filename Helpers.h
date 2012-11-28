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

#ifndef HELPERS_H
#define HELPERS_H

// STL
#include <cmath>
#include <limits> // for epsilon()
#include <queue>
#include <string>
#include <stack>
#include <type_traits> // for enable_if, is_fundamental, and decltype (C++11)
#include <vector>

// Custom
#include "TypeTraits.h"

namespace Helpers
{
//////////////////////////////////////////////////////////////////////////////////////////////////
////////////////// Non-template function declarations (defined in Helpers.cpp) ///////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////

/** Compare two objects. If their difference is less than the epsilon() defined for their type, return true.
  * To do this, we must check (SFINAE) if the types given actually have an epsilon() defined (by checking if they are is_specialized)
  */
template<typename TA, typename TB>
typename std::enable_if<std::numeric_limits<TA>::is_specialized && std::numeric_limits<TB>::is_specialized, bool>::type
FuzzyCompare(const TA& a, const TB& b,
             const TA& epsilon = std::numeric_limits<TA>::epsilon());

/** Compare vectors. If their difference is less than the epsilon() defined for their type, return true.
  * To do this, we must check (SFINAE) if the types given actually have an epsilon() defined (by checking if they are is_specialized)
  */
template<typename TA, typename TB>
typename std::enable_if<std::numeric_limits<TA>::is_specialized && std::numeric_limits<TB>::is_specialized, bool>::type
FuzzyCompare(const std::vector<TA>& a, const std::vector<TB>& b,
             const TA& epsilon = std::numeric_limits<TA>::epsilon());

/** Compare non numeric objects (like enums). This specialization ignores the epsilon parameter.
  */
template<typename TA, typename TB>
typename std::enable_if<!(std::numeric_limits<TA>::is_specialized && std::numeric_limits<TB>::is_specialized), bool>::type
FuzzyCompare(const TA& a, const TB& b);

/** Ignore a piece of a stream. */
std::istream& InlineIgnore(std::istream& ss);

/** Compute -log(value). */
float NegativeLog(const float value);

/** Get the characters after the last '.' in a string (the file extension). */
std::string GetFileExtension(const std::string& fileName);

/** Get the characters before the last '/' in a string (the path). Note this is Linux specific as
  * it looks for '/' instead of '\'. */
std::string GetPath(const std::string& fileName);

/** Replace the file extension in 'fileName' with 'newExtension'. */
std::string ReplaceFileExtension(const std::string& fileName, const std::string& newExtension);

/** Zero pad the 'iteration' and append it to the filePrefix, and add ".[fileExtension]" to the end.
  * GetSequentialFileName("test", 2, "png");
  * Produces "test_0002.png" */
std::string GetSequentialFileName(const std::string& filePrefix, const unsigned int iteration,
                                  const std::string& fileExtension, const unsigned int paddedLength = 4);

/** Patch sizes are specified by radius so they always have an odd side length.
 * The side length is (2*radius)+1 */
unsigned int SideLengthFromRadius(const unsigned int radius);

/** Determine if 'value' is odd. */
bool IsOdd(const int value);

/** Convert a 'number' into a zero padded string.
  * ZeroPad(5, 4); produces "0005" */
std::string ZeroPad(const unsigned int number, const unsigned int rep);

/** STL's .compare() function returns 0 when strings match, this is unintuitive. */
bool StringsMatch(const std::string&, const std::string&);

/** "Ceil()", but also for negative numbers.
  * RoundAwayFromZero(.2) = 1
  * RoundAwayFromZero(-.2) = -1
  * (Normally ceil(-.2) = 0 */
float RoundAwayFromZero(const float number);

/** Generate a random integer between 'minValue' and 'maxValue' */
int RandomInt(const int minValue, const int maxValue);

/////////////////////////////////////////////////////////////////////////////////////////////
////////////////// Template function declarations (defined in Helpers.hpp) ///////////////////
/////////////////////////////////////////////////////////////////////////////////////////////

/** Determine if 'r', 'g', and 'b' are all in the range [0, 255]. */
template <class T>
bool IsValidRGB(const T r, const T g, const T b);

/** Determine the index at which the container has the smallest element. */
template <class T>
unsigned int Argmin(const T& vec);

/** Determine the index at which the container has the largest element. */
template <class T>
unsigned int Argmax(const T& vec);

/** Determine the value of the smallest element of a specified 'index' of a collection of multicomponent objects. */
template <class TContainer>
typename TypeTraits<typename TContainer::value_type>::ComponentType
MinOfIndex(const TContainer& container, const unsigned int index);

/** Determine the value of the largest element of a specified 'index' of a collection of multicomponent objects. */
template <class TContainer>
typename TypeTraits<typename TContainer::value_type>::ComponentType
MaxOfIndex(const TContainer& container, const unsigned int index);

/** Determine the value of the smallest element of each index of a collection of multicomponent objects.
  * We cannot return the 'output' (so instead, we return it by reference) because it must be pre-sized and passed in because the
  * sizing procedure is very different for different containers (std::vector, itk::CovariantVector, etc).
  * This is the generic version (that requires TOutput to have an operator[]() (i.e. it is multi-component).
  */
template <class TContainer, typename TOutput>
void MinOfAllIndices(const TContainer& container, TOutput& output,
                     typename std::enable_if<!std::is_pod<TOutput>::value >::type* = 0);

/**
* This is the special version for scalar TOutput.
*/
template <class TContainer, typename TOutput>
void MinOfAllIndices(const TContainer& container, TOutput& output,
                     typename std::enable_if<std::is_pod<TOutput>::value >::type* = 0);

/** Determine the value of the largest element of each index of a collection of multicomponent objects. */
template <class TContainer, typename TOutput>
void MaxOfAllIndices(const TContainer& container, TOutput& output,
                     typename std::enable_if<!std::is_pod<TOutput>::value >::type* = 0);

/** Determine the value of the largest element of each index of a collection of multicomponent objects. This is a special version for scalar TOutput.*/
template <class TContainer, typename TOutput>
void MaxOfAllIndices(const TContainer& container, TOutput& output,
                     typename std::enable_if<std::is_pod<TOutput>::value >::type* = 0);

/** Determine the value of the smallest element. */
template <class T>
typename T::value_type Min(const T& vec);

/** Determine the value of the largest element. */
template <class T>
typename T::value_type Max(const T& vec);

/** Divide every element of a vector by the sum of the vector. TVector must model std::vector. */
template<typename TVector>
void NormalizeVectorInPlace(TVector& v);

/** Divide every element of a vector by the sum of the vector. */
template<typename T>
std::vector<typename TypeTraits<T>::LargerType>
NormalizeVector(const std::vector<T>& v);

/** Compute the median of the elements in 'v'. */
template<typename T>
typename T::value_type VectorMedian(T v);

/** Sum the scalar elements in a container. */
template<typename TForwardIterator>
float Sum(const TForwardIterator first, const TForwardIterator last);

/** Sum the corresponding differences of elements in two containers. */
template<typename TVector>
float VectorSumOfAbsoluteDifferences(const TVector& a, const TVector& b);

/** Write the elements of 'v' to a space delimited text file called 'filename'. */
template<typename T>
void WriteVectorToFile(const std::vector<T> &v, const std::string& filename);

/** Write the elements of 'v' to separate lines of a text file called 'filename'. */
template<typename T>
void WriteVectorToFileLines(const std::vector<T> &v, const std::string& filename);

/** Output all of the .first values. */
template <typename T>
void OutputFirst(const T& vec);

/** Compare two objects by their .first values. */
template <typename TPair>
bool SortByFirstAccending(TPair object1, TPair object2);

/** Compare two objects by their .second values. */
template <typename TPair>
bool SortBySecondAccending(TPair object1, TPair object2);

/** Extract all of the .first values into a vector. */
template <typename T1, typename T2>
std::vector<T1> ExtractFirst(const std::vector<std::pair<T1, T2> >& vec);

/** Determine if 'vec' contains 'value'. */
template <typename T>
bool Contains(const std::vector<T>& vec, const T& value);

/** Output all of the elements in the vector. */
template <typename TVector>
void Output(const TVector& vec);

/** Compare all of the elements of 'vec' to 'value' and determine
  * which one has the smallest distance. */
template <typename T>
unsigned int ClosestIndex(const std::vector<T>& vec, const T& value);

/** Determine if a value is NaN. */
template <class T>
bool IsNaN(const T a);

/** Determine if a container contains any NaN values. */
template <class T>
bool ContainsNaN(const T a);

/** Keep the top N elements of a priority queue.*/
template <class TPriorityQueue>
void KeepTopN(TPriorityQueue& q, const unsigned int numberToKeep);

/** Keep the top N elements of a priority queue.*/
template <class TQueue>
void KeepFrontN(TQueue& q, const unsigned int numberToKeep);

/** Check if a 'value' is present in a queue. Pass 'q' by value so we can pop
  * through it without affecting original data.*/
template <class T>
bool DoesQueueContain(std::queue<T> q, const T& value);

/** Check if a 'value' is present in a stack. Pass 's' by value so we can pop
  * through it without affecting original data.*/
template <class T>
bool DoesStackContain(std::stack<T> s, const T& value);

/** Force a value to be in this range.*/
template <class T>
T Force0to255(const T& value);

/** Computed a weighted sum of 'values' using the associated 'weights'.*/
template <class TValue>
typename TypeTraits<TValue>::LargerType WeightedAverage(const std::vector<TValue>& values,
                                                        const std::vector<float>& weights);

/** When comparing H values, you cannot simply subtract them,
  * because they wrap. That is, 0.99 is very very close in
  * hue to 0.01, but their standard difference is very large.*/
struct HSV_H_Difference
{
  template <class TValue>
  TValue operator()(const TValue& a, const TValue& b) const
  {
    TValue minValue = std::min(a,b);
    TValue maxValue = std::max(a,b);

    TValue standardDifference = fabs(a - b);

    TValue wrapDifference = (minValue - 0) + (1 - maxValue);

    return std::min(standardDifference, wrapDifference);
  }
};

template<typename T>
struct HasBracketOperator
{
private:

  // This version works for std::vector<T>
  template <typename X>
  static std::true_type
  check(X*, typename std::enable_if<std::is_same<
        decltype(std::declval<X const>().operator[](std::declval<typename X::size_type const &>())),
                typename X::value_type const&>::value, void>::type * = 0);

  // Check for a specific const version of the operator[const int] overload
  template <typename X>
  static std::true_type
  check(X*, typename std::enable_if<
        std::is_same<decltype(std::declval<X const>().operator[](std::declval<int const &>())),
                    typename X::ValueType const&>
        ::value, void>::type * = 0);

  template<typename>
  static std::false_type check(...);

  typedef decltype(check<T>((T*)(0))) type_;

public:
  static bool const value = type_::value;
};

}// end namespace

#include "Helpers.hpp"

#endif
