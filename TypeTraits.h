#ifndef TypeTraits_H
#define TypeTraits_H

// STL
#include <vector>

/** For generic types (assume they are scalars). */
template <class T>
struct TypeTraits
{
  typedef T LargerType;
  typedef T LargerComponentType;
  typedef T ComponentType;
};

/** For unsigned char, use float as the LargerType */
template <>
struct TypeTraits<unsigned char>
{
  typedef float LargerType;
  typedef float LargerComponentType;
  typedef unsigned char ComponentType;
};

/** For generic std::vector. */
template <typename T>
struct TypeTraits<std::vector<T> >
{
  typedef std::vector<T> LargerType;
  typedef typename TypeTraits<T>::LargerType LargerComponentType;
  typedef T ComponentType;
};

#endif
