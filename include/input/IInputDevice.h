//---------------------------------------------------------------------------
// IInputDevice.h
//---------------------------------------------------------------------------

#pragma once

namespace CC
{
  class IInputDevice
  {
    public:
      /** Update the device, called by Input
       */
      virtual void Update() = 0;
  };
}
