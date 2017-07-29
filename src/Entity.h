#pragma once

#include "EntityFunctions.h"

class __declspec(dllexport) CEntity
{
	void Destroy()
	{
		CEntity_Destroy(this);
	}
};