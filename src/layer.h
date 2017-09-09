#pragma once
#include "LayerFunctions.h"

namespace ProjectNovigrad
{
	namespace TW3
	{
		class __declspec(dllexport) CLayer
		{
		public:
			int RemoveShadowsFromLayer()
			{
				return ProjectNovigrad::TW3::Functions::CLayer_RemoveShadowsFromLayer(this);
			}

			void GetEntities(TDynArray<CEntity*>& array)
			{
				return ProjectNovigrad::TW3::Functions::CLayer_GetEntities(this, array);
			}
		};
	}
}
