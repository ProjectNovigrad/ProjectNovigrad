#pragma once

#include "Game.h"
#include "Entity.h"

namespace ProjectNovigrad
{
	class __declspec(dllexport) CSystem
	{
	public:
		CSystem();
		~CSystem();

		void Init();
		TW3::CGame* GetGame() { return *m_pGame; }
	private:
		TW3::CGame** m_pGame;
	};
}