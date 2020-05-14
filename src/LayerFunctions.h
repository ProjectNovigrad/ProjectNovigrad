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

      static hook::thiscall_stub<void(CLayer*, TDynArray<CEntity*>*)> CLayer_GetEntities([]() {
        return hook::pattern("40 53 55 57 48 83 EC 20 44 8B 4A 08 4C 8B 02 48 8B DA")
          .count(1)
          .get(0)
          .get<void*>(0);
        });

    }
  }
}