//---------------------------------------------------------------------------
// LowLevelInputGLFW.h
//---------------------------------------------------------------------------

#pragma once

#include "GLFW/glfw3.h"
#include "gleq.h"

#include <list>
#include "input/ILowLevelInput.h"

namespace CC
{
  class LowLevelGraphicsGLFW;
  class ILowLevelGraphics;
  class IKeyboard;

  /** LowLevelInputGLFW
   */
  class LowLevelInputGLFW : public ILowLevelInput
  {
    public:
      LowLevelInputGLFW();

      void Init(LowLevelGraphicsGLFW* lowLevelGraphics);
      void BeginInputUpdate();
      void EndInputUpdate();
      IKeyboard* CreateKeyboard();

    public:
      std::list<GLEQevent> m_listEvents;

    private:
      ILowLevelGraphics* m_lowLevelGraphics;
  };
}
