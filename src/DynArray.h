#pragma once
#include <stdint.h>

namespace ProjectNovigrad
{
  namespace TW3
  {
    template<class T>
    struct __declspec(dllexport) TDynArray
    {
      T* base_pointer;
      uint32_t count;
      uint32_t max;
      uint64_t begin;
    };
  }
}