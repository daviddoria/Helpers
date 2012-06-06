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
#include <vector>
#include <type_traits> // for enable_if and is_fundamental (C++0x)

// Custom
#include "TypeTraits.h"

namespace Helpers
{
//////////////////////////////////////////////////////////////////////////////////////////////////
////////////////// Non-template function declarations (defined in Helpers.cpp) ///////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////

float NegativeLog(const float value);

bool IsValidRGB(const int r, const int g, const int b);

std::string GetFileExtension(const std::string& fileName);
std::string GetPath(const std::string& fileName);

std::string ReplaceFileExtension(const std::string& fileName, const std::string& newExtension);

// Zero pad the 'iteration' and append it to the filePrefix, and add ".[fileExtension]" to the end.
// GetSequentialFileName("test", 2, "png");
// Produces "test_0002.png"
std::string GetSequentialFileName(const std::string& filePrefix, const unsigned int iteration,
                                  const std::string& fileExtension, const unsigned int paddedLength = 4);

// Patch sizes are specified by radius so they always have an odd side length. The side length is (2*radius)+1
unsigned int SideLengthFromRadius(const unsigned int radius);

bool IsOdd(const int value);

// Convert a 'number' into a zero padded string.
// ZeroPad(5, 4); produces "0005"
std::string ZeroPad(const unsigned int number, const unsigned int rep);

// STL's .compare() function returns 0 when strings match, this is unintuitive.
bool StringsMatch(const std::string&, const std::string&);

// "Ceil()", but also for negative numbers.
// RoundAwayFromZero(.2) = 1
// RoundAwayFromZero(-.2) = -1
// (Normally ceil(-.2) = 0
float RoundAwayFromZero(const float number);

void
sphericalToCartesian( double & x, double & y, double & z,
                      double   r, double   theta, double   phi );

void
cartesianToSpherical( double & r, double & theta, double & phi,
                      double   x, double   y, double   z );

void PrintSpherical(double   x, double   y, double   z );

int RandomInt(const int minValue, const int maxValue);

/////////////////////////////////////////////////////////////////////////////////////////////
////////////////// Template function declarations (defined in Helpers.hxx) ///////////////////
/////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
unsigned int argmin(const T& vec);

template<typename T>
void NormalizeVector(T& v);

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

template<typename T>
void WriteVectorToFile(const std::vector<T> &v, const std::string& filename);

template <typename T>
void OutputFirst(const T& vec);

template <typename TPair>
bool SortByFirstAccending(TPair object1, TPair object2);

template <typename TPair>
bool SortBySecondAccending(TPair object1, TPair object2);

template <typename T1, typename T2>
std::vector<T1> ExtractFirst(const std::vector<std::pair<T1, T2> >& vec);

template <typename T>
bool Contains(const std::vector<T>& vec, const T& value);

template <typename T>
void Output(const std::vector<T>& vec);

template <typename T>
unsigned int ClosestIndex(const std::vector<T>& vec, const T& value);

}// end namespace

#include "Helpers.hpp"

#endif
