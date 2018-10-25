//---------------------------------------------------------------------------
// SystemTest.cc
//---------------------------------------------------------------------------

#include "CC.h"
#include "system/ILowLevelSystem.h"

using namespace CC;

Game* game = NULL;

class SystemUpdate : public IUpdateable
{
  public:
    SystemUpdate()
    {
      // Add an action to exit when ESC key is pressed
      game->GetInput()->AddAction(new ActionKeyboard("ExitGame",
            ccKey(ccKey_ESCAPE), game->GetInput()));
    }

    void Update()
    {
      if(game->GetInput()->BecameTriggered("ExitGame"))
      {
        game->Exit();
      }
      Log("Update called\n");
    }
};

int ccMain()
{
  // Create factories
  GameSetupFactory* setupFactory = new GameSetupFactory();

  // Init game
  ILowLevelGameSetup* gameSetup = setupFactory->CreateGameSetup();
  game = new Game(gameSetup, 800, 600);

  // Add update
  SystemUpdate systemUpdate;
  game->GetUpdater()->AddUpdate(&systemUpdate);

  // Run
  game->Run();

  return 0;
}
