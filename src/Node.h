#pragma once
#include "NodeFunctions.h"
#include "../vtable/vmthooks.h"

namespace ProjectNovigrad
{
  namespace TW3
  {
    class __declspec(dllexport) CNode
    {
    public:
      char* GetFriendlyName()
      {
        return Functions::CNode_GetFriendlyName(this);
      }
    };
  };
};