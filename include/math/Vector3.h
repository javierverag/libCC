//---------------------------------------------------------------------------
// Vector3.h
//---------------------------------------------------------------------------

#pragma once

namespace CC
{
  template <typename T>
    struct Vector3
    {
      Vector3(T x, T y, T z) : x(x), y(y), z(z) {}

      T x;
      T y;
      T z;
    };
}
