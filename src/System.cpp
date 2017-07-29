#include "stdafx.h"
#include "System.h"

using namespace ProjectNovigrad;

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
	m_pGame = TW3::CGame::Hook();
}