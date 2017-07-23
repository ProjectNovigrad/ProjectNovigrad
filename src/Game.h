#pragma once
#include "GameFunctions.h"

class CGame
{
public:
	bool ProcessFreeCameraInput(EInputKey key, EInputAction action, float tick)
	{
		return CGame_ProcessFreeCameraInput(this, key, action, tick);
	}

	bool ShowLoadingScreen()
	{
		return CGame_ShowLoadingScreen(this);
	}

	void MoveMouseTo(float x, float y)
	{
		return CGame_MoveMouseTo(this, x, y);
	}

	void EnableFreeCamera(bool enable)
	{
		return CGame_EnableFreeCamera(this, enable);
	}

	void Stop()
	{
		return CGame_Stop(this);
	}
};