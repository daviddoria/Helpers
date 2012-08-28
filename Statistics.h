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
