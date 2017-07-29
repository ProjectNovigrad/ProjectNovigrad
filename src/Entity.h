#pragma once

#include "EntityFunctions.h"

namespace ProjectNovigrad
{
	namespace TW3
	{
		class __declspec(dllexport) CEntity
		{
			void Destroy()
			{
				Functions::CEntity_Destroy(this);
			}
		};
	}
}