//---------------------------------------------------------------------------
// IAction.h
//---------------------------------------------------------------------------

#pragma once

#include <string>

namespace CC
{
  class IAction
  {
    public:
      IAction(std::string name);

      void Update();
      bool BecameTriggered();
      virtual bool IsTriggered() = 0;
      std::string GetName();

    private:
      std::string m_name;
      bool m_becameTriggered;
      bool m_isTriggered;
  };
}
