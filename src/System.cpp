#include "System.h"

CSystem::CSystem()
{
	
}

CSystem::~CSystem()
{
	
}

void CSystem::Init()
{
	m_threadHandle = CreateThread(nullptr, 0, CSystem::ThreadEntrypoint, 0, 0, nullptr);
}

DWORD ThreadEntrypoint(LPVOID args)
{
	return 1;
}

