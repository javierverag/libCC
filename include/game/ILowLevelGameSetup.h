//---------------------------------------------------------------------------
// LowLevelGameSetup.h
//---------------------------------------------------------------------------

#pragma once

#include "system/System.h"
#include "graphics/Graphics.h"
#include "input/Input.h"

namespace CC
{
  /** ILowLevelGameSetup
   */
  class ILowLevelGameSetup
  {
    public:
      virtual ~ILowLevelGameSetup(){}

      virtual Input* CreateInput()=0;
      virtual System* CreateSystem()=0;
      virtual Graphics* CreateGraphics()=0;
  };
}
