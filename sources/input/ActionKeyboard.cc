//---------------------------------------------------------------------------
// ActionKeyboard.cc
//---------------------------------------------------------------------------

#include <string>
#include "input/Input.h"
#include "input/IKeyboard.h"
#include "input/ActionKeyboard.h"

namespace CC
{
  //-------------------------------------------------------------------------
  ActionKeyboard::ActionKeyboard(std::string name, int key, Input* input) :
    IAction(name),
    m_input(input),
    m_key((ccKey)key)
  {
  }

  //-------------------------------------------------------------------------
  bool ActionKeyboard::IsTriggered()
  {
    return m_input->GetKeyboard()->KeyIsDown(m_key);
  }
}
