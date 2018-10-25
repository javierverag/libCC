//---------------------------------------------------------------------------
// GameSetupFactory.h
//---------------------------------------------------------------------------

#pragma once

namespace CC
{
  class ILowLevelGameSetup;

  /** Creates a platform dependent GameSetup
   */
  class GameSetupFactory
  {
    public:
      GameSetupFactory();
      ILowLevelGameSetup* CreateGameSetup();
  };
}
