#include "stdafx.h"
#include "System.h"

using namespace ProjectNovigrad;

typedef bool (*OnViewportInputType)(void* thisptr,
  void* viewport,
  EInputKey input_key,
  EInputAction input_action,
  float tick);
OnViewportInputType OnViewportInputDebugConsole = nullptr;

void** globalDebugConsole = nullptr;

CSystem* pSystem = nullptr;

bool OnViewportInputDebugAlwaysHook(void* thisptr, void* viewport, EInputKey inputKey, EInputAction inputAction, float tick)
{
  if (!pSystem) return false;
  pSystem->GetInput()->OnViewportInputHook(thisptr, viewport, inputKey, inputAction, tick);
  return OnViewportInputDebugConsole(globalDebugConsole, viewport, inputKey, inputAction, tick);
}

CSystem::CSystem()
{

}

CSystem::~CSystem()
{
  if (m_pInput)
    delete m_pInput;
  if (m_pGameVtableHook)
    delete m_pGameVtableHook;
}

void CSystem::CreateConsole() {
  AllocConsole();
  freopen("CONOUT$", "w", stdout);
}

void CSystem::Init()
{
  hook::set_base();
  HookFunction::RunAll();
  CreateConsole();
  m_pGame = TW3::CGame::Hook();
  m_pInput = new CInput();
  m_pGameVtableHook = new utils::VtableHook(m_pGame);
  pSystem = this;

  OnViewportInputDebugConsole =
    hook::pattern("48 83 EC 28 48 8B 05 ? ? ? ? 0F B6 90")
    .count(1)
    .get(0)
    .get<OnViewportInputType>(0);
  globalDebugConsole =
    hook::pattern("48 89 05 ? ? ? ? EB 07 48 89 35 ? ? ? ? 48 8B")
    .count(1)
    .get(0)
    .extract<void**>(3);
  m_pGameVtableHook->HookMethod(OnViewportInputDebugAlwaysHook, 136);
}

