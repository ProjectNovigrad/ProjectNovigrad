#pragma once

#include "../hooking/Hooking.h"

class CEntity;

static hook::thiscall_stub<void(CEntity*)> CEntity_Destroy([]() {
	return hook::pattern("40 53 48 83 EC 20 48 8B 01 48 8B D9 FF 90 60 01")
		.count(1)
		.get(0)
		.get<void*>(0);
});
