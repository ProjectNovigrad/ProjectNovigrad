#pragma once

#include "EntityFunctions.h"
#include "Node.h"
#include "../vtable/vmthooks.h"
#include "TString.h"

namespace ProjectNovigrad
{
  namespace TW3
  {
    class __declspec(dllexport) CEntity
    {
    public:
      TString<wchar_t>* GetUniqueName(TString<wchar_t>* res)
      {
        utils::VtableHook hook(this);
        return hook.GetMethod<TString<wchar_t>* (__thiscall*)(void*, TString<wchar_t>*)>(45)(this, res);
      }

      TString<wchar_t>* GetFriendlyName(TString<wchar_t>* res)
      {
        utils::VtableHook hook(this);
        return hook.GetMethod<TString<wchar_t>* (__thiscall*)(void*, TString<wchar_t>*)>(27)(this, res);
      }

      void* SetPosition(Vector* vec)
      {
        utils::VtableHook hook(this);
        return hook.GetMethod<void* (__thiscall*)(void*, void*)>(63)(this, vec);
      }

      bool Teleport(Vector* vec, EulerAngles* angles)
      {
        utils::VtableHook hook(this);
        return hook.GetMethod<bool(__thiscall*)(void*, void*, void*)>(138)(this, vec, angles);
      }

      Vector GetWorldPosition()
      {
        return *(Vector*)(this + 160);
      }
    };
  }
}