#pragma once
#include "../hooking/Hooking.h"
#include "WitcherEnums.h"

namespace ProjectNovigrad
{
  namespace TW3
  {
    class CGame;
    class CWorld;
    class CEntity;
    namespace Functions
    {
      static hook::thiscall_stub<bool(CGame*, EInputKey, EInputAction, float)> CGame_ProcessFreeCameraInput([]() {
        return hook::pattern("48 89 5C 24 ? 48 89 74 24 ? 57 48 83 EC 40 80 3D")
          .count(1)
          .get(0)
          .get<void*>(0);
        });

      static hook::thiscall_stub<bool(CGame*)> CGame_ShowLoadingScreen([]() {
        return hook::pattern("48 89 5C 24 08 48 89 74 24 10 57 48 83 EC 50 8B")
          .count(1)
          .get(0)
          .get<void*>(0);
        });


      static hook::thiscall_stub<void(CGame*, float, float)> CGame_MoveMouseTo([]() {
        return hook::pattern("48 8B 89 88 01 00 00 48 85 C9 74 07 48 8B 01 48")
          .count(1)
          .get(0)
          .get<void*>(0);
        });

      static hook::thiscall_stub<void(CGame*, bool)> CGame_EnableFreeCamera([]() {
        return hook::pattern("48 89 5C 24 08 57 48 83 EC 40 0F B6 81 1F 01 00 00 0F B6 FA 48 8B D9 84")
          .count(1)
          .get(0)
          .get<void*>(0);
        });

      static hook::thiscall_stub<void(CGame*)> CGame_Stop([]() {
        return hook::pattern("40 53 48 83 EC 30 80 B9 10 01 00 00 00 48 8B D9")
          .count(1)
          .get(0)
          .get<void*>(0);
        });

      static hook::thiscall_stub<CWorld* (CGame*)> CGame_GetActiveWorld([]() {
        return hook::pattern("48 8D 81 F0 00 00 00 C3")
          .count(1)
          .get(0)
          .get<void*>(0);
        });

      static hook::thiscall_stub<bool(CGame*)> CGame_IsSavedRecently([]() {
        return hook::pattern("40 57 48 83 EC 20 48 8B F9 84 D2 74 0D 48 8B 81")
          .count(1)
          .get(0)
          .get<void*>(0);
        });


      static hook::thiscall_stub<CEntity* (CGame*)> CGame_GetPlayerEntity([]() {
        // 48 8B 81 00 BA 00 00 48  85 C0 74 05 48 8B 40 10
        return hook::pattern("48 8B 81 00 BA 00 00 48 85 C0 74 05 48 8B 40 10 C3 F3 C3")
          .count(1)
          .get(0)
          .get<void*>(0);
        });

    }
  }
}
