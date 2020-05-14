#pragma once

#include "../hooking/Hooking.h"

namespace ProjectNovigrad
{
  namespace TW3
  {
    class CWorld;
    class CName;
    namespace Functions
    {

      static hook::thiscall_stub<void(CWorld*, bool, bool)> CWorld_SetWaterVisible([]() {
        return hook::pattern("48 89 5C 24 08 57 48 83 EC 20 41 0F B6 F8 48 8B D9")
          .count(1)
          .get(0)
          .get<void*>(0);
        });
    }
  }
}
