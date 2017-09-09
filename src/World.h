#pragma once

#include "WorldFunctions.h"

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

			CLayer* FindLayerByTag(CName* tag)
			{
				return Functions::CWorld_FindLayerByTag(this, tag);
			}

		};
	}
}