//---------------------------------------------------------------------------
// System.h
//---------------------------------------------------------------------------

#pragma once

namespace CC
{
  class ILowLevelSystem;

  class System
  {
    public:

      System(ILowLevelSystem* lowLevelSystem);

    private:

      ILowLevelSystem* m_lowLevelSystem;
  };
}
