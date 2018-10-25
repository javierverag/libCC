//---------------------------------------------------------------------------
// System.cc
//---------------------------------------------------------------------------

#include "system/ILowLevelSystem.h"
#include "system/System.h"

namespace CC
{
  //-------------------------------------------------------------------------
  System::System(ILowLevelSystem* lowLevelSystem) :
    m_lowLevelSystem(lowLevelSystem)
  {
  }
}
