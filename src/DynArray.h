#pragma once
#include <stdint.h>

namespace ProjectNovigrad
{
  namespace TW3
  {
    #pragma pack(push, 1)

    template<class T>
    struct __declspec(dllexport) TDynArray
    {
      T* base_pointer;
      uint32_t count;
      uint64_t max;
      uint64_t begin;
    };
    #pragma pack(pop)

  }
}