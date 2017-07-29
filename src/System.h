#pragma once

#include "Game.h"
#include "Entity.h"

class __declspec(dllexport) CSystem
{
public:
	CSystem();
	~CSystem();

	void Init();
	CGame* GetGame() { return *m_pGame; }
private:
	CGame** m_pGame;
};