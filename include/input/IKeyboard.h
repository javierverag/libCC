//---------------------------------------------------------------------------
// IKeyboard.h
//---------------------------------------------------------------------------

#pragma once

#include "input/InputTypes.h"
#include "input/IInputDevice.h"

namespace CC
{
  class IKeyboard : public IInputDevice
  {
    public:

      /**
       * @return true if any key is pressed
       */
      virtual bool KeyIsPressed() = 0;

      /**
       *
       */
      virtual bool KeyIsDown(ccKey key) = 0;
  };
}
