//---------------------------------------------------------------------------
// LowLevelGameSetupLinux.cc
//---------------------------------------------------------------------------

#include "input/Input.h"
#include "graphics/Graphics.h"
#include "system/System.h"
#include "impl/LowLevelSystemLinux.h"
#include "impl/LowLevelGraphicsGLFW.h"
#include "impl/LowLevelInputGLFW.h"
#include "impl/LowLevelGameSetupLinux.h"

namespace CC
{
  //---------------------------------------------------------------------------
  LowLevelGameSetupLinux::LowLevelGameSetupLinux()
  {
    m_lowLevelSystem = new LowLevelSystemLinux();
    m_lowLevelGraphics = new LowLevelGraphicsGLFW();
    m_lowLevelInput = new LowLevelInputGLFW();
  }

  //---------------------------------------------------------------------------
  LowLevelGameSetupLinux::~LowLevelGameSetupLinux()
  {
    delete m_lowLevelInput;
    delete m_lowLevelGraphics;
    delete m_lowLevelSystem;
  }

  //---------------------------------------------------------------------------
  Input* LowLevelGameSetupLinux::CreateInput()
  {
    m_lowLevelInput->Init(m_lowLevelGraphics);
    return new Input(m_lowLevelInput);
  }

  //---------------------------------------------------------------------------
  System* LowLevelGameSetupLinux::CreateSystem()
  {
    return new System(m_lowLevelSystem);
  }

  //---------------------------------------------------------------------------
  Graphics* LowLevelGameSetupLinux::CreateGraphics()
  {
    return new Graphics(m_lowLevelGraphics);
  }
}
