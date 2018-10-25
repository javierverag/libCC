//---------------------------------------------------------------------------
// LowLevelInputGLFW.cc
//---------------------------------------------------------------------------

#include "impl/LowLevelGraphicsGLFW.h"
#include "input/IKeyboard.h"
#include "impl/KeyboardGLFW.h"
#include "impl/LowLevelInputGLFW.h"

namespace CC
{
  //---------------------------------------------------------------------------
  LowLevelInputGLFW::LowLevelInputGLFW()
  {
  }

  //---------------------------------------------------------------------------
  void LowLevelInputGLFW::Init(LowLevelGraphicsGLFW* lowLevelGraphics)
  {
    m_lowLevelGraphics = lowLevelGraphics;
    gleqTrackWindow(lowLevelGraphics->getWindow());
  }

  //---------------------------------------------------------------------------
  void LowLevelInputGLFW::BeginInputUpdate()
  {
    glfwPollEvents();
    GLEQevent event;

    while (gleqNextEvent(&event))
    {
      m_listEvents.push_back(event);
    }
  }

  //---------------------------------------------------------------------------
  void LowLevelInputGLFW::EndInputUpdate()
  {
    m_listEvents.clear();
  }

  //---------------------------------------------------------------------------
  IKeyboard* LowLevelInputGLFW::CreateKeyboard()
  {
    return (new KeyboardGLFW(this));
  }
}
