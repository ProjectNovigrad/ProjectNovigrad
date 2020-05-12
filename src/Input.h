#pragma once
#include <vector>
#include "IInputListener.h"

class __declspec(dllexport) CInput
{
public:
  CInput::CInput() {};
  CInput::~CInput();
  void RegisterInputListener(IInputListener* listener);
  bool OnViewportInputHook(void* thisptr, void* viewport, EInputKey inputKey, EInputAction inputAction, float tick);
private:
  std::vector<IInputListener*> listeners;
};

