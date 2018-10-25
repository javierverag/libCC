//---------------------------------------------------------------------------
// ILowLevelInput.h
//---------------------------------------------------------------------------

#pragma once

namespace CC
{
  class IKeyboard;

  /** ILowLevelInput
   */
  class ILowLevelInput
  {
    public:

      /** Called by Input
       */
      virtual void BeginInputUpdate() = 0;

      /** Called by Input
       */
      virtual void EndInputUpdate() = 0;

      virtual IKeyboard* CreateKeyboard() = 0;
  };
}
