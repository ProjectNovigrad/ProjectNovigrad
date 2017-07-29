#pragma once
#include "GameFunctions.h"

class __declspec(dllexport) CGame
{
public:
	static CGame** Hook()
	{
		return hook::pattern("48 8B 05 ? ? ? 01 C6 44 24 30 01 89 4C 24 28")
			.count(1)
			.get(0)
			.extract<CGame**>(3);
	}

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