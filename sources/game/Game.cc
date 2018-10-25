//---------------------------------------------------------------------------
// Game.cc
//---------------------------------------------------------------------------


#ifdef EMSC
#include <emscripten/emscripten.h>
#endif
#include "input/IKeyboard.h"

#include "game/Updater.h"
#include "game/ILowLevelGameSetup.h"
#include "system/ILowLevelSystem.h"

#include "game/Game.h"

namespace CC
{
  Game* Game::self = 0;

  //-------------------------------------------------------------------------
  Game::Game(ILowLevelGameSetup* lowLevelGameSetup, int width, int height) :
    m_exit(false)
  {
    GameInit(lowLevelGameSetup);
  }

  //-------------------------------------------------------------------------
  void Game::GameInit(ILowLevelGameSetup* lowLevelGameSetup)
  {
    self = this;

    Log("Creating Engine Modules\n");
    Log("--------------------------------------------------------\n");

    m_lowLeveGameSetup = lowLevelGameSetup;

    Log(" Creating system module\n");
    m_system = lowLevelGameSetup->CreateSystem();

    Log(" Creating graphics module\n");
    m_graphics = lowLevelGameSetup->CreateGraphics();
    m_graphics->Init(800, 600, "Hello World!");

    Log(" Creating input module\n");
    m_input = lowLevelGameSetup->CreateInput();

    Log(" Adding engine updates\n");
    m_updater = new Updater();
    m_updater->AddUpdate(m_input);
  }

  //-------------------------------------------------------------------------
  void Game::Run()
  {
    bool exit = false;
    unsigned int time = GetApplicationTime();

#ifdef EMSC
    emscripten_set_main_loop(StaticDoFrame, 0, 1);
#else
    while (!m_exit)
    {
      unsigned int oldTime = time;
      time = GetApplicationTime();
      unsigned int delta = time - oldTime;

      Log("%u ms\n", delta);

      for (int i = 0; i < 1000000; ++i);

      m_updater->Update();
    }
#endif
  }

  //-------------------------------------------------------------------------
  void Game::DoFrame()
  {
    // TODO: Call this from Run()
    m_updater->Update();
  }

  //-------------------------------------------------------------------------
  void Game::StaticDoFrame()
  {
    self->DoFrame();
  }

  //-------------------------------------------------------------------------
  void Game::Exit()
  {
    m_exit = true;
  }

  //-------------------------------------------------------------------------
  Updater* Game::GetUpdater()
  {
    return m_updater;
  }

  //-------------------------------------------------------------------------
  Input* Game::GetInput()
  {
    return m_input;
  }

  //-------------------------------------------------------------------------
  Graphics* Game::GetGraphics()
  {
    return m_graphics;
  }
}
