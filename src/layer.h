#pragma once
#include "LayerFunctions.h"
#include "DynArray.h"

namespace ProjectNovigrad
{
  namespace TW3
  {
    class __declspec(dllexport) CLayer
    {
    public:
      int RemoveShadowsFromLayer()
      {
        return Functions::CLayer_RemoveShadowsFromLayer(this);
      }

      void GetEntities(TDynArray<CEntity*>* output)
      {
        return Functions::CLayer_GetEntities(this, output);
      }
    };
  }
}
