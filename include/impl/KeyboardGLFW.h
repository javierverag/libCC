//---------------------------------------------------------------------------
// KeyboardGLFW.h
//---------------------------------------------------------------------------

#pragma once

#include <list>
#include <vector>
#include "input/InputTypes.h"
#include "input/IKeyboard.h"

namespace CC
{
  class LowLevelInputGLFW;

  class KeyboardGLFW : public IKeyboard
  {
    public:
      KeyboardGLFW(LowLevelInputGLFW* lowLevelInputGLFW);

      void Update();
      bool KeyIsPressed();
      bool KeyIsDown(ccKey key);

    private:
      void ClearKeyList();
      ccKey GLEQToKey(int key);

      std::vector<bool> m_keyArray;
      std::list<KeyPress> m_listKeysPressed;
      LowLevelInputGLFW* m_lowLevelInputGLFW;
  };
}
