#pragma once
#include "../hooking/Hooking.h"

namespace ProjectNovigrad
{
	namespace TW3
	{
		class CName;
		namespace Functions
		{
			static hook::thiscall_stub<void(CName*, const wchar_t*)> CName_Set([]() {
				return hook::pattern("48 89 5C 24 08 57 48 83 EC 20 48 8B DA 48 8B F9 48 85 D2 74 31 66 83 3A 00 74 2B 45 33 C0 48 8D")
					.count(1)
					.get(0)
					.get<void*>(0);
			});

			static hook::thiscall_stub<const wchar_t*(CName*)> CName_AsChar([]() {
				return hook::pattern("40 53 48 83 EC 20 48 8B 05 ? ? ? ? 48 8B D9 48 85 C0 75 05 E8 ? ? ? ? 8B 13 48 8B 0D ? ? ? ? E8")
					.count(1)
					.get(0)
					.get<void*>(0);
			});
		}
	}
}