#pragma once
#include "../hooking/Hooking.h"

namespace ProjectNovigrad
{
  namespace TW3
  {
    class CLayer;
    class CEntity;
    template <class T>
    struct TDynArray;
    namespace Functions
    {
      static hook::thiscall_stub<int(CLayer*)> CLayer_RemoveShadowsFromLayer([]() {
        return hook::pattern("40 56 48 83 EC 60 48 8B 01 48 8B F1 FF 90 18 01")
          .count(1)
          .get(0)
          .get<void*>(0);
        });

      static hook::thiscall_stub<void(CLayer*, TDynArray<CEntity*>&)> CLayer_GetEntities([]() {
        return hook::pattern("40 53 57 41 56 48 83 EC 30 8B 42 0C 4C 8B F1 8B 4A 08 41 03 4E 70 48 8B DA 48 3B C1 73 1F 33 D2")
          .count(1)
          .get(0)
          .get<void*>(0);
        });

    }
  }
}