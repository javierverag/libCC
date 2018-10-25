//---------------------------------------------------------------------------
// GameSetupFactory.cc
//---------------------------------------------------------------------------

#include "game/GameSetupFactory.h"
#include "game/ILowLevelGameSetup.h"
#include "impl/LowLevelGameSetupEmsc.h"
#include "impl/LowLevelGameSetupLinux.h"
#include "impl/LowLevelGameSetupWindows.h"

namespace CC
{
  //-----------------------------------------------------------------------
  GameSetupFactory::GameSetupFactory()
  {
  }

  //-----------------------------------------------------------------------
  ILowLevelGameSetup* GameSetupFactory::CreateGameSetup()
  {
#ifdef LINUX
    return new LowLevelGameSetupLinux();
#elif EMSC
    return new LowLevelGameSetupEmsc();
#elif WINDOWS
    return new LowLevelGameSetupWindows();
#endif
  }
}
