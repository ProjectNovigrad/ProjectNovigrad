#pragma once

#include "../hooking/Hooking.h"

namespace ProjectNovigrad
{
  namespace TW3
  {
    class CWorld;
    class CName;
    class CLayer;
    namespace Functions
    {

      static hook::thiscall_stub<void(CWorld*, bool, bool)> CWorld_SetWaterVisible([]() {
        return hook::pattern("48 89 5C 24 08 57 48 83 EC 20 41 0F B6 F8 48 8B")
          .count(1)
          .get(0)
          .get<void*>(0);
        });

      static hook::thiscall_stub<CLayer* (CWorld*, const CName* tag)> CWorld_FindLayerByTag([]() {
        return hook::pattern("48 89 5C 24 08 48 89 74 24 10 48 89 7C 24 18 41")
          .count(1)
          .get(0)
          .get<void*>(0);
        });
    }
  }
}
