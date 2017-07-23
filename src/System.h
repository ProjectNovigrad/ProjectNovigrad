#pragma once

#include <Windows.h>

class CSystem
{
public:
	CSystem();
	~CSystem();

	void Init();
private:
	HANDLE m_threadHandle;
	DWORD ThreadEntrypoint(LPVOID arguments);
};