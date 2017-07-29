/*
 * This file is part of the CitizenFX project - http://citizen.re/
 *
 * See LICENSE and MENTIONS in the root of the source tree for information
 * regarding licensing.
 */

#pragma once

#include <string>

//
// Initialization function that will be called after the game is loaded.
//

class __declspec(dllexport) HookFunctionBase {
 private:
  HookFunctionBase* m_next;

 public:
  HookFunctionBase() { Register(); }

  virtual void Run() = 0;

  static void RunAll();
  void Register();
};

class __declspec(dllexport) HookFunction : public HookFunctionBase {
 private:
  void (*m_function)();

 public:
  HookFunction(void (*function)()) { m_function = function; }

  virtual void Run() { m_function(); }
};

class __declspec(dllexport) RuntimeHookFunction {
 private:
  void (*m_function)();
  std::string m_key;

  RuntimeHookFunction* m_next;

 public:
  RuntimeHookFunction(const char* key, void (*function)()) {
    m_key = key;
    m_function = function;

    Register();
  }

  static void Run(const char* key);
  void Register();
};