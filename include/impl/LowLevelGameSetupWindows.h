//---------------------------------------------------------------------------
// LowLevelGameSetupWindows.h
//---------------------------------------------------------------------------

#pragma once

#include "game/ILowLevelGameSetup.h"

namespace CC
{
    // Forward declarations
    class Input;
    class System;
    class Graphics;
    class ILowLevelSystem;
    class LowLevelGraphicsGLFW;
    class LowLevelInputGLFW;

    /** LowLevelGameSetupWindows
    */
    class LowLevelGameSetupWindows : public ILowLevelGameSetup
    {
    public:
        LowLevelGameSetupWindows();
        ~LowLevelGameSetupWindows();

        Input* CreateInput();
        System* CreateSystem();
        Graphics* CreateGraphics();

    private:
        ILowLevelSystem* m_lowLevelSystem;
        LowLevelGraphicsGLFW* m_lowLevelGraphics;
        LowLevelInputGLFW* m_lowLevelInput;
    };
}