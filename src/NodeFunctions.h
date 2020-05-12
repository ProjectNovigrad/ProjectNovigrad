#pragma once
// 48 89 5C 24 10 57 48 81  EC B0 00 00 00 48 8B 01

#include "../hooking/Hooking.h"

namespace ProjectNovigrad
{
  namespace TW3
  {
    class CNode;
    namespace Functions
    {

      static hook::thiscall_stub<char* (CNode*)> CNode_GetFriendlyName([]() {
        return hook::pattern("48 89 5C 24 10 57 48 81 EC B0 00 00 00 48 8B 01")
          .count(1)
          .get(0)
          .get<void*>(0);
        });
    }
  }
}
