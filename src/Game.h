#pragma once
#include "GameFunctions.h"
#include "../vtable/vmthooks.h"


namespace ProjectNovigrad
{
  namespace TW3
  {
    struct __declspec(dllexport) Vector {
      float x;
      float y;
      float z;
    };

    class __declspec(dllexport) CGame
    {
    public:
      
      //typedef int64_t(*GetPlayerEntityFun)(CGame* dis);
      static CGame* Hook()
      {

        return *hook::pattern("48 89 05 0C 22 AA 02 48 85 C0 75")
          .count(1)
          .get(0)
          .extract<CGame**>(3);
      }

      bool ProcessFreeCameraInput(EInputKey key, EInputAction action, float tick)
      {
        return Functions::CGame_ProcessFreeCameraInput(this, key, action, tick);
      }

      bool ShowLoadingScreen()
      {
        return Functions::CGame_ShowLoadingScreen(this);
      }

      void MoveMouseTo(float x, float y)
      {
        return Functions::CGame_MoveMouseTo(this, x, y);
      }

      void EnableFreeCamera(bool enable)
      {
        return Functions::CGame_EnableFreeCamera(this, enable);
      }

      void Stop()
      {
        return Functions::CGame_Stop(this);
      }

      CWorld* GetActiveWorld()
      {
        return Functions::CGame_GetActiveWorld(this);
      }

      bool IsSavedRecently()
      {
        return Functions::CGame_IsSavedRecently(this);
      }

      CEntity* GetPlayerEntity()
      {
        utils::VtableHook hook(this);
        return hook.GetMethod<CEntity* (__thiscall*)(void*)>(62)(this);
      }
    };
  }
}