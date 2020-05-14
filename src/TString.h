#pragma once

namespace ProjectNovigrad
{
  namespace TW3
  {
    template<class T>
    struct __declspec(dllexport) TString {
      T* ptr;
      uint32_t len;
    };
  }
}

