#pragma once

#include "EntityFunctions.h"
#include "Node.h"
#include "../vtable/vmthooks.h"

namespace ProjectNovigrad
{
  namespace TW3
  {
    class __declspec(dllexport) CEntity
    {
    public:
      void Destroy()
      {
        Functions::CEntity_Destroy(this);
      }

      char* GetName()
      {
        return Functions::CEntity_GetName(this);
      }

      char* GetDisplayName()
      {
        return Functions::CEntity_GetDisplayName(this);
      }

      char* GetFriendlyName()
      {
        return Functions::CEntity_GetFriendlyName(this);
      }

      char* GetUniqueName(char* res)
      {
        utils::VtableHook hook(this);
        return hook.GetMethod<char* (__thiscall*)(void*, char*)>(45)(this, res);
      }

      void* SetPosition(Vector* vec)
      {
        utils::VtableHook hook(this);
        return hook.GetMethod<void* (__thiscall*)(void*, void*)>(63)(this, vec);
      }

      bool Teleport(Vector* vec, Vector* angles)
      {
        utils::VtableHook hook(this);
        return hook.GetMethod<bool(__thiscall*)(void*, void*, void*)>(138)(this, vec, angles);
      }

      Vector GetWorldPosition()
      {
        Vector v;
        v.x = *(float*)(this + 160);
        v.y = *(float*)(this + 164);
        v.z = *(float*)(this + 168);
        return v;
      }
    };
  }
}