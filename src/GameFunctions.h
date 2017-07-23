#pragma once
#include "../hooking/Hooking.h"

class CGame;

static hook::thiscall_stub<bool(CGame*, EInputKey, EInputAction, float)> CGame_ProcessFreeCameraInput([]() {
	return hook::pattern("48 89 5C 24 ? 48 89 74 24 ? 57 48 83 EC 40 80 3D")
		.count(1)
		.get(0)
		.get<void*>(0);
});

static hook::thiscall_stub<bool(CGame*)> CGame_ShowLoadingScreen([]() {
	return hook::pattern("48 89 5C 24 08 48 89 74 24 10 57 48 83 EC 50 8B")
		.count(1)
		.get(0)
		.get<void*>(0);
});


static hook::thiscall_stub<void(CGame*, float, float)> CGame_MoveMouseTo([]() {
	return hook::pattern("48 8B 89 88 01 00 00 48 85 C9 74 07 48 8B 01 48")
		.count(1)
		.get(0)
		.get<void*>(0);
});

static hook::thiscall_stub<void(CGame*, bool)> CGame_EnableFreeCamera([]() {
	return hook::pattern("48 89 5C 24 08 57 48 83 EC 40 0F B6 81 1F 01 00")
		.count(1)
		.get(0)
		.get<void*>(0);
});

static hook::thiscall_stub<void(CGame*)> CGame_Stop([]() {
	return hook::pattern("40 53 48 83 EC 30 80 B9 10 01 00 00 00 48 8B D9")
		.count(1)
		.get(0)
		.get<void*>(0);
});
