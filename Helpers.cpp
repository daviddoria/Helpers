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

#include "Helpers.h"

// STL
#include <cassert>
#include <iomanip> // setfill and setw
#include <sstream>

namespace Helpers
{

std::string GetFileExtension(const std::string& fileName)
{
  return fileName.substr(fileName.find_last_of(".") + 1); // single parameter substr returns from argument to end
}

std::string GetPath(const std::string& fileName)
{
  return fileName.substr( 0, fileName.find_last_of('/') + 1);
}

float NegativeLog(const float value)
{
  return -1.0f * log(value);
}

std::string GetSequentialFileName(const std::string& filePrefix, const unsigned int iteration,
                                  const std::string& fileExtension, const unsigned int paddedLength)
{
  std::stringstream padded;
  padded << filePrefix << "_" << ZeroPad(iteration, paddedLength) << "." << fileExtension;
  return padded.str();
}

float RoundAwayFromZero(const float number)
{
  float signMultiplier = 0;
  if(number >= 0)
    {
    signMultiplier = 1.0;
    }
  else
    {
    signMultiplier = -1.0;
    }
  float absNumber = fabs(number);
  float rounded = ceil(absNumber) * signMultiplier;

  return rounded;
}


unsigned int SideLengthFromRadius(const unsigned int radius)
{
  return radius*2 + 1;
}

std::string ZeroPad(const unsigned int number, const unsigned int paddedLength)
{
  std::stringstream padded;
  padded << std::setfill('0') << std::setw(paddedLength) << number;

  return padded.str();
}


std::string ReplaceFileExtension(const std::string& fileName, const std::string& newExtension)
{
  // This should be called like:
  // std::string newFilenName = ReplaceFileExtension("oldfile.png", "jpg");
  // To produce "oldfile.jpg"

  std::string newFileName = fileName;
  const unsigned int fileExtensionLength = 3;
  newFileName.replace(newFileName.size() - fileExtensionLength, fileExtensionLength, newExtension);
  return newFileName;
}

bool StringsMatch(const std::string& a, const std::string& b)
{
  // STL compare returns 0 if strings match. This is unintuitive, so this function returns the expected value.
  if(a.compare(b) == 0)
  {
    return true;
  }
  else
  {
    return false;
  }
}

int RandomInt(const int minValue, const int maxValue)
{
  assert(maxValue >= minValue);

  if(maxValue == minValue)
  {
    return minValue; // could equivalently return maxValue
  }

  // Produce a number between 0 and (max - min)
  int temp = rand() % (maxValue - minValue);
  return temp + minValue;
}

bool IsOdd(const int value)
{
  if(value % 2 == 1)
  {
    return true;
  }

  return false;
}

std::istream& InlineIgnore(std::istream& ss)
{
  ss.ignore(std::numeric_limits<std::streamsize>::max(),':');
  return ss;
}

} // end namespace
