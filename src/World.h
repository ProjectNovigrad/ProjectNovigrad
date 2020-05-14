#pragma once
#include "WorldFunctions.h"
#include "../vtable/vmthooks.h"


namespace ProjectNovigrad
{
  namespace TW3
  {
    class CLayer;
    class __declspec(dllexport) CWorld
    {
    public:
      void SetWaterVisible(bool a, bool b)
      {
        return Functions::CWorld_SetWaterVisible(this, a, b);
      }

      CName* GetName()
      {
        return (CName*)*(UINT64*)(this + 24);
      }

      void Shutdown()
      {
        utils::VtableHook hook(this);
        hook.GetMethod<void(__thiscall*)(void*)>(56)(this);
      }
    };
  }
}   