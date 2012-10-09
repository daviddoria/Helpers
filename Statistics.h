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

#ifndef Statistics_H
#define Statistics_H

// Custom
#include "TypeTraits.h"

namespace Statistics
{

/** Average the values in a vector. */
template<typename TVector>
typename TypeTraits<TVector>::LargerComponentType Average(const TVector& v);

/** Average the values in a vector without summing them all first. */
template<typename TVector>
typename TypeTraits<TVector>::LargerComponentType RunningAverage(const TVector& v);

/** Compute the variance of the values in a vector. */
template<typename TVector>
typename TypeTraits<TVector>::LargerComponentType Variance(const TVector& v);

/** Compute the correlation of two vector. */
template<typename TVector>
typename TypeTraits<TVector>::LargerComponentType Correlation(const TVector& v1, const TVector& v2);

}

#include "Statistics.hpp"

#endif
