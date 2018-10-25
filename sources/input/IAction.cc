//---------------------------------------------------------------------------
// IAction.cc
//---------------------------------------------------------------------------

#include "input/IAction.h"

namespace CC
{
  //-------------------------------------------------------------------------
  IAction::IAction(std::string name) :
    m_name(name),
    m_isTriggered(false)
  {
  }

  //-------------------------------------------------------------------------
  void IAction::Update()
  {
    if (!IsTriggered())
    {
      m_isTriggered = false;
    }
    else
    {
      m_becameTriggered = true;
    }
  }

  //-------------------------------------------------------------------------
  bool IAction::BecameTriggered()
  {
    if(!m_isTriggered && IsTriggered())
    {
      m_isTriggered = true;
      return true;
    }
    return false;
  }

  //-------------------------------------------------------------------------
  std::string IAction::GetName()
  {
    return m_name;
  }
}
