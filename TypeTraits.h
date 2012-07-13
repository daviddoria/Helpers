#ifndef TypeTraits_H
#define TypeTraits_H

// STL
#include <vector>

/** For generic types (assume they are scalars). Specializations will have to deal
  * with the cases that are not. */
template <class T>
struct TypeTraits
{
  typedef T LargerType;
  typedef T LargerComponentType;
  typedef T ComponentType;
};

/** For unsigned char, use float as the LargerType. This is an explicit specialization -
  * that is this is no longer a template. */
template <>
struct TypeTraits<unsigned char>
{
  typedef float LargerType;
  typedef float LargerComponentType;
  typedef unsigned char ComponentType;
};

/** For generic std::vector. This is a partial specialization (TypeTraits is still a template here),
  * as we allow the vector template parameter to be specified. */
template <typename T>
struct TypeTraits<std::vector<T> >
{
  typedef std::vector<T> LargerType;
  typedef typename TypeTraits<T>::LargerType LargerComponentType;
  typedef T ComponentType;
};

#endif
