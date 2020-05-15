#pragma once

#include "EntityFunctions.h"
#include "Node.h"
#include "../vtable/vmthooks.h"
#include "TString.h"

namespace ProjectNovigrad
{
  namespace TW3
  {
    struct EntitySpawnParams {
      char v48; // [rsp+A0h] [rbp-60h]
      char v49; // [rsp+ACh] [rbp-54h]
      char v50; // [rsp+B8h] [rbp-48h]
      char v51; // [rsp+C8h] [rbp-38h]
      Vector position; // [rsp+F0h] [rbp-10h]
      EulerAngles direction; // [rsp+100h] [rbp+0h]
      int v54; // [rsp+108h] [rbp+8h]
      Vector v55; // [rsp+120h] [rbp+20h]
      int v56; // [rsp+130h] [rbp+30h]
      char v57; // [rsp+14Ah] [rbp+4Ah]
      char v58; // [rsp+150h] [rbp+50h]
      char v59; // [rsp+1A8h] [rbp+A8h]
      char v60; // [rsp+1B8h] [rbp+B8h]
    };
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