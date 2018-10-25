//---------------------------------------------------------------------------
// Input.cc
//---------------------------------------------------------------------------

#include "input/ILowLevelInput.h"
#include "input/IInputDevice.h"
#include "input/IKeyboard.h"
#include "input/Input.h"
#include "input/IAction.h"

namespace CC
{
  //---------------------------------------------------------------------------
  Input::Input(ILowLevelInput* lowLevelInput) :
    m_lowLevelInput(lowLevelInput)
  {
    m_keyboard = m_lowLevelInput->CreateKeyboard();
    m_listInputDevices.push_back(m_keyboard);
  }

  //---------------------------------------------------------------------------
  void Input::Update()
  {
    m_lowLevelInput->BeginInputUpdate();

    for(InputDeviceListIterator it = m_listInputDevices.begin();
        it != m_listInputDevices.end(); ++it)
    {
      (*it)->Update();
    }

    m_lowLevelInput->EndInputUpdate();

    for(ActionMapIterator it = m_actions.begin(); it != m_actions.end(); ++it)
    {
      it->second->Update();
    }
  }

  //---------------------------------------------------------------------------
  bool Input::BecameTriggered(std::string action)
  {
    return m_actions[action]->BecameTriggered();
  }

  //---------------------------------------------------------------------------
  IKeyboard* Input::GetKeyboard()
  {
    return m_keyboard;
  }

  //---------------------------------------------------------------------------
  void Input::AddAction(IAction* action)
  {
    std::string name = action->GetName();

    ActionMapType::value_type value = ActionMapType::value_type(name, action);
    m_actions.insert(value);
  }
}
