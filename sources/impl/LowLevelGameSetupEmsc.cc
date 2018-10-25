//---------------------------------------------------------------------------
// LowLevelGameSetupEmsc.cc
//---------------------------------------------------------------------------

#include "input/Input.h"
#include "graphics/Graphics.h"
#include "system/System.h"
#include "impl/LowLevelSystemEmsc.h"
#include "impl/LowLevelGraphicsGLFW.h"
#include "impl/LowLevelInputGLFW.h"
#include "impl/LowLevelGameSetupEmsc.h"

namespace CC
{
  //---------------------------------------------------------------------------
  LowLevelGameSetupEmsc::LowLevelGameSetupEmsc()
  {
    m_lowLevelSystem = new LowLevelSystemEmsc();
    m_lowLevelGraphics = new LowLevelGraphicsGLFW();
    m_lowLevelInput = new LowLevelInputGLFW();
  }

  //---------------------------------------------------------------------------
  LowLevelGameSetupEmsc::~LowLevelGameSetupEmsc()
  {
    delete m_lowLevelInput;
    delete m_lowLevelGraphics;
    delete m_lowLevelSystem;
  }

  //---------------------------------------------------------------------------
  Input* LowLevelGameSetupEmsc::CreateInput()
  {
    m_lowLevelInput->Init(m_lowLevelGraphics);
    return new Input(m_lowLevelInput);
  }

  //---------------------------------------------------------------------------
  System* LowLevelGameSetupEmsc::CreateSystem()
  {
    return new System(m_lowLevelSystem);
  }

  //---------------------------------------------------------------------------
  Graphics* LowLevelGameSetupEmsc::CreateGraphics()
  {
    return new Graphics(m_lowLevelGraphics);
  }
}

