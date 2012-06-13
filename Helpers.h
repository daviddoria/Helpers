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

#ifndef HELPERS_H
#define HELPERS_H

// STL
#include <string>
#include <queue>
#include <stack>
#include <type_traits> // for enable_if and is_fundamental (C++0x)
#include <vector>

// Custom
#include "TypeTraits.h"

namespace Helpers
{
//////////////////////////////////////////////////////////////////////////////////////////////////
////////////////// Non-template function declarations (defined in Helpers.cpp) ///////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////

/** Compute -log(value). */
float NegativeLog(const float value);

/** Determine if 'r', 'g', and 'b' are all in the range [0, 255]. */
bool IsValidRGB(const int r, const int g, const int b);

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

/** Convert spherical coordinates to cartesian coordinates. */
void
sphericalToCartesian( double & x, double & y, double & z,
                      double   r, double   theta, double   phi );

/** Convert cartesian coordinates to spherical coordinates. */
void
cartesianToSpherical( double & r, double & theta, double & phi,
                      double   x, double   y, double   z );

/** Print (to the screen) the sphereical coordinates corresponding to a cartesian point. */
void PrintSpherical(double   x, double   y, double   z );

/** Generate a random integer between 'minValue' and 'maxValue' */
int RandomInt(const int minValue, const int maxValue);

/////////////////////////////////////////////////////////////////////////////////////////////
////////////////// Template function declarations (defined in Helpers.hpp) ///////////////////
/////////////////////////////////////////////////////////////////////////////////////////////

/** Determine the inex at which the container has the smallest element. */
template <class T>
unsigned int argmin(const T& vec);

/** Divide every element of a vector by the sum of the vector. */
template<typename T>
void NormalizeVector(T& v);

/** Compute the median of the elements in 'v'. */
template<typename T>
typename T::value_type VectorMedian(T v);

/** Convert any type with operator[] to any other type with operator[] */
template<typename TTo, typename TFrom>
TTo ConvertFrom(const TFrom& object);

/** Sum the scalar elements in a container. */
template<typename TForwardIterator>
float Sum(const TForwardIterator first, const TForwardIterator last);

/** Sum the corresponding differences of elements in two containers. */
template<typename TVector>
float VectorSumOfAbsoluteDifferences(const TVector& a, const TVector& b);

/** Output a node. */
template<typename TNode>
void OutputNode(const TNode& a);

/** Write the elements of 'v' to a space delimited text file called 'filename'. */
template<typename T>
void WriteVectorToFile(const std::vector<T> &v, const std::string& filename);

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
template <typename T>
void Output(const std::vector<T>& vec);

/** Compare all of the elements of 'vec' to 'value' and determine which one has the smallest distance. */
template <typename T>
unsigned int ClosestIndex(const std::vector<T>& vec, const T& value);

/** Determine if a value is NaN. */
template <class T>
bool IsNaN(const T a);

/** Determine if a container contains any NaN values. */
template <class T>
bool ContainsNaN(const T a);

/** Check if a 'value' is present in a queue. Pass 'q' by value so we can pop through it without affecting original data.*/
template <class T>
bool DoesQueueContain(std::queue<T> q, const T& value);

/** Check if a 'value' is present in a stack. Pass 's' by value so we can pop through it without affecting original data.*/
template <class T>
bool DoesStackContain(std::stack<T> s, const T& value);

}// end namespace

#include "Helpers.hpp"

#endif
