//---------------------------------------------------------------------------
// LowLevelGameSetupWindows.cc
//---------------------------------------------------------------------------

#include "input/Input.h"
#include "graphics/Graphics.h"
#include "system/System.h"
#include "impl/LowLevelSystemWindows.h"
#include "impl/LowLevelGraphicsGLFW.h"
#include "impl/LowLevelInputGLFW.h"
#include "impl/LowLevelGameSetupWindows.h"

namespace CC
{
    //---------------------------------------------------------------------------
    LowLevelGameSetupWindows::LowLevelGameSetupWindows()
    {
        m_lowLevelSystem = new LowLevelSystemWindows();
        m_lowLevelGraphics = new LowLevelGraphicsGLFW();
        m_lowLevelInput = new LowLevelInputGLFW();
    }

    //---------------------------------------------------------------------------
    LowLevelGameSetupWindows::~LowLevelGameSetupWindows()
    {
        delete m_lowLevelInput;
        delete m_lowLevelGraphics;
        delete m_lowLevelSystem;
    }

    //---------------------------------------------------------------------------
    Input* LowLevelGameSetupWindows::CreateInput()
    {
        m_lowLevelInput->Init(m_lowLevelGraphics);
        return new Input(m_lowLevelInput);
    }

    //---------------------------------------------------------------------------
    System* LowLevelGameSetupWindows::CreateSystem()
    {
        return new System(m_lowLevelSystem);
    }

    //---------------------------------------------------------------------------
    Graphics* LowLevelGameSetupWindows::CreateGraphics()
    {
        return new Graphics(m_lowLevelGraphics);
    }
}