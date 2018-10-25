//---------------------------------------------------------------------------
// Graphics.cc
//---------------------------------------------------------------------------

#include "graphics/ILowLevelGraphics.h"
#include "graphics/Graphics.h"

namespace CC
{
  //-------------------------------------------------------------------------
  Graphics::Graphics(ILowLevelGraphics* lowLevelGraphics) :
    m_lowLevelGraphics(lowLevelGraphics)
  {
  }

  //-------------------------------------------------------------------------
  bool Graphics::Init(int width, int height, const std::string& windowCaption)
  {
    return m_lowLevelGraphics->Init(width, height, windowCaption);
  }

  //-------------------------------------------------------------------------
  ILowLevelGraphics* Graphics::GetLowLevel()
  {
    return m_lowLevelGraphics;
  }
}
