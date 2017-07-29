#include "stdafx.h"
#include "System.h"

CSystem::CSystem()
{
	
}

CSystem::~CSystem()
{
	
}

void CSystem::Init()
{
	hook::set_base();
	HookFunction::RunAll();
	m_pGame = CGame::Hook();
}