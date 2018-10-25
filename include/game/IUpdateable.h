//---------------------------------------------------------------------------
// IUpdateable.h
//---------------------------------------------------------------------------

#pragma once

namespace CC
{
  /** IUpdateable
   */
  class IUpdateable
  {
    public:
      virtual void OnStart(){}
      virtual void Update(){}
      virtual void OnExit(){}
  };
}
