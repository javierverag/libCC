//---------------------------------------------------------------------------
// ILowLevelGraphics.h
//---------------------------------------------------------------------------

#pragma once

#include <string>
#include "math/MathTypes.h"
#include "graphics/GraphicsTypes.h"

/**
 * Fwd Declarations
 */
namespace CC
{
  class IVertexBuffer;
  class IShaderProgram;
}

namespace CC
{
  /** ILowLevelGraphics
   */
  class ILowLevelGraphics
  {
    public:
      virtual bool Init(int width, int height, const std::string& windowCaption) = 0;
      virtual void SwapBuffers() = 0;
      virtual IVertexBuffer* CreateVertexBuffer() = 0;
      virtual IShaderProgram* CreateShaderProgram(const std::string& vertexShaderSource,
                                                  const std::string& fragmentShaderSource) = 0;
      virtual void SetMatrix(MatrixType type, const Matrixf& matrix, const IShaderProgram& program) = 0;
  };
}
