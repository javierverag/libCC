//---------------------------------------------------------------------------
// Updater.h
//---------------------------------------------------------------------------

#pragma once

#include <list>
#include "game/IUpdateable.h"

namespace CC
{
  class Updater
  {
    public:
      void OnStart();
      void Update();
      void OnExit();
      void AddUpdate(IUpdateable* updateable);

    private:
      std::list<IUpdateable*> m_updateableList;
  };
}
