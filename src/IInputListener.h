#pragma once
#include "WitcherEnums.h"

struct __declspec(dllexport) IInputListener
{
  virtual void OnInputEvent(EInputAction inputAction, EInputKey inputKey, float tick) = 0;
};