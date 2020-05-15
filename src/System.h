#pragma once

#include "Game.h"
#include "Entity.h"
#include "Input.h"
#include "../vtable/vmthooks.h"

namespace ProjectNovigrad
{
  class __declspec(dllexport) CSystem
  {
  public:
    CSystem();
    ~CSystem();

    void Init();
    CInput* GetInput() { return m_pInput; }
    TW3::CGame* GetGame() { return *m_pGame; }
  private:
    void WaitForGame();
    void CreateConsole();
    TW3::CGame** m_pGame;
    CInput* m_pInput;
    utils::VtableHook* m_pGameVtableHook;
  };
}