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

#ifndef Statistics_HPP
#define Statistics_HPP

// Custom
#include "Helpers.h"
#include "Statistics.h"
#include "ContainerInterface.h"

// STL
#include <cassert>
#include <iostream>
#include <stdexcept>

namespace Statistics
{

template<typename TVector>
typename TypeTraits<TVector>::LargerComponentType RunningAverage(const TVector& v)
{
  // If T is not a scalar (i.e. convertible to float (i.e. an itk::VariableLengthVector) )
  // We cannot simply sum all of the values and divide by the number of values, because the type may overflow.
  // E.g. if we sum more than 2 or 3 unsigned chars, we will overflow unsigned char.
  // To remedy this, the average is computed during each step so overflow is always prevented.
  // From: http://en.wikipedia.org/wiki/Moving_average#Cumulative_moving_average

  typedef typename TypeTraits<TVector>::LargerComponentType AverageType;
  //typedef typename TypeTraits<TVector>::ComponentType ItemType;
  //std::cout << "Helpers::RunningAverage" << std::endl;
  AverageType vectorRunningAverage = v[0]; // We do this because if the length is not known until runtime (std::vector, itk::VariableLengthVector, etc), we want the output to be the right length.

  for(unsigned int i = 0; i < Helpers::length(v); ++i)
    {
    //ItemType object = v[i];
    vectorRunningAverage = (static_cast<AverageType>(v[i]) +
          static_cast<float>(i)*vectorRunningAverage)/static_cast<float>(i+1);
    }

  return vectorRunningAverage;
}

template<typename TVector>
typename TypeTraits<TVector>::LargerComponentType Average(const TVector& v)
{
  //std::cout << "Helpers::Average" << std::endl;
  typedef typename TypeTraits<TVector>::LargerComponentType AverageType;
  // We do this because if the length is not known until runtime
  // (std::vector, itk::VariableLengthVector, etc), we want the output to be the right length.
  AverageType vectorSum = v[0];

  // Zero the initial vector
  for(unsigned int i = 0; i < Helpers::length(vectorSum); ++i)
    {
    Helpers::index(vectorSum, i) = 0;
    }

  for(unsigned int i = 0; i < Helpers::length(v); ++i)
    {
    typedef typename TypeTraits<TVector>::ComponentType ObjectType;
    ObjectType object = Helpers::index(v,i);
    vectorSum += object;
    }
  // std::cout << "Average: sum " << vectorSum << std::endl;
  //typename T::value_type vectorAverage = vectorSum / static_cast<float>(v.size());
  AverageType vectorAverage = vectorSum / static_cast<float>(Helpers::length(v));

  // std::cout << "Average: average " << vectorAverage << std::endl;

  return vectorAverage;
}

template<typename TVector>
typename TypeTraits<TVector>::LargerComponentType Variance(const TVector& v)
{
  assert(Helpers::length(v) > 0);
  if(Helpers::length(v) <= 0)
  {
    throw std::runtime_error("Must have more than 0 items to compute a variance!");
  }

  typedef typename TypeTraits<TVector>::LargerComponentType VarianceType;

  VarianceType average = Average(v);
  // std::cout << "Variance: average = " << average << std::endl;
  //VarianceType variance = itk::NumericTraits<VarianceType>::Zero; // I don't understand why this doesn't work

  // We do this (assign variance to the 0th component) because if the length is not known until runtime
  // (e.g. std::vector, itk::VariableLengthVector, etc), we want the output to be the right length.
  VarianceType variance = v[0];
  // Variance = 1/NumPixels * sum_i (x_i - u)^2

  for(unsigned int component = 0; component < Helpers::length(variance); ++component)
  {
    float channelVarianceSummation = 0.0f;
    for(unsigned int i = 0; i < Helpers::length(v); ++i)
    {
      channelVarianceSummation += pow(Helpers::index(v[i], component) -
                                      Helpers::index(average, component), 2);
    }
    // This (N-1) term in the denominator is for the "unbiased" sample variance.
    // This is what is used by Matlab, Wolfram alpha, etc.
    float channelVariance = channelVarianceSummation / static_cast<float>(Helpers::length(v) - 1);
    Helpers::index(variance, component) = channelVariance;
  }
  return variance;
}

template<typename TVector>
typename TypeTraits<TVector>::LargerComponentType Correlation(const TVector& v1, const TVector& v2)
{
  // http://docs.opencv.org/doc/tutorials/imgproc/histograms/histogram_comparison/histogram_comparison.html
  // d(H_1, H_2) = \frac{\sum_i(H_1(i) - \bar{H_1})(H_2(i)-\bar{H_2})}{sqrt(var(H_1)var(H_2))}

  assert(Helpers::length(v1) > 0);
  assert(Helpers::length(v1) == Helpers::length(v2));

  float numerator = 0.0f;

  float meanV1 = Average(v1);
  float meanV2 = Average(v2);

  float varianceV1 = Variance(v1);
  float varianceV2 = Variance(v2);

  for(unsigned int i = 0; i < Helpers::length(v1); ++i)
  {
    numerator += (v1[i] - meanV1)*(v2[i] - meanV2);
  }

  float correlation = numerator/(sqrt(varianceV1 * varianceV2));

  return correlation;
}

}

#endif
