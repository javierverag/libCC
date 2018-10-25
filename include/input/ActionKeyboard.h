//---------------------------------------------------------------------------
// ActionKeyboard.h
//---------------------------------------------------------------------------

#pragma once

#include "input/InputTypes.h"
#include "input/IAction.h"

namespace CC
{
  class Input;

  class ActionKeyboard : public IAction
  {
    public:
      ActionKeyboard(std::string name, int key, Input* input);

      bool IsTriggered();

    private:
      Input* m_input;
      ccKey m_key;
  };
}
