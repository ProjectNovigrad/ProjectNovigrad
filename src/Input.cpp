#include "Input.h"

CInput::~CInput() 
{
  listeners.clear();
}

bool CInput::OnViewportInputHook(void* thisptr, void* viewport, EInputKey inputKey, EInputAction inputAction, float tick)
{
  for (auto listener : listeners)
  {
    if (listener)
    {
      listener->OnInputEvent(inputAction, inputKey, tick);
    }
  }
  return true;
}

void CInput::RegisterInputListener(IInputListener* listener)
{
  listeners.push_back(listener);
}
