//---------------------------------------------------------------------------
// Updater.cc
//---------------------------------------------------------------------------

#include "game/Updater.h"

namespace CC
{
  //-------------------------------------------------------------------------
  void Updater::OnStart()
  {
    for(std::list<IUpdateable*>::iterator it = m_updateableList.begin();
        it != m_updateableList.end(); ++it)
    {
      (*it)->OnStart();
    }
  }

  //-------------------------------------------------------------------------
  void Updater::Update()
  {
    for(std::list<IUpdateable*>::iterator it = m_updateableList.begin();
        it != m_updateableList.end(); ++it)
    {
      (*it)->Update();
    }
  }

  //-------------------------------------------------------------------------
  void Updater::OnExit()
  {
    for(std::list<IUpdateable*>::iterator it = m_updateableList.begin();
        it != m_updateableList.end(); ++it)
    {
      (*it)->OnExit();
    }
  }

  //-------------------------------------------------------------------------
  void Updater::AddUpdate(IUpdateable* updateable)
  {
    m_updateableList.push_back(updateable);
  }
}
