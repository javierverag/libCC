//---------------------------------------------------------------------------
// Input.h
//---------------------------------------------------------------------------

#pragma once

#include <list>
#include <map>
#include <string>
#include "game/IUpdateable.h"

namespace CC
{
  class IKeyboard;
  class ILowLevelInput;
  class IInputDevice;
  class IAction;

  typedef std::list<IInputDevice*> InputDeviceListType;
  typedef std::list<IInputDevice*>::iterator InputDeviceListIterator;
  typedef std::map<std::string, IAction*> ActionMapType;
  typedef std::map<std::string, IAction*>::iterator ActionMapIterator;

  /** Input
   */
  class Input : public IUpdateable
  {
    public:

      Input(ILowLevelInput* lowLevelInput);

      /** Updates the input, called by Game
       */
      void Update();
      bool BecameTriggered(std::string action);
      IKeyboard* GetKeyboard();
      void AddAction(IAction* action);

    private:
      ILowLevelInput* m_lowLevelInput;
      InputDeviceListType m_listInputDevices;
      ActionMapType m_actions;
      IKeyboard* m_keyboard;
  };
}
