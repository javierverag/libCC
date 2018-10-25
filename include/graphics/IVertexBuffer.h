//---------------------------------------------------------------------------
// IVertexBuffer.h
//---------------------------------------------------------------------------

#pragma once

#include "math/MathTypes.h"

namespace CC
{
  enum VertexBufferDrawType
  {
    DRAWTYPE_POINTS,
    DRAWTYPE_TRIANGLES
  };

  class IVertexBuffer
  {
    public:
      virtual ~IVertexBuffer() {};
      virtual void AddVertex(const Vector3f& vertex) = 0;
      virtual void Bind() = 0;
      virtual void UnBind() = 0;
      virtual void Compile() = 0;
      virtual void Draw(const VertexBufferDrawType drawType) = 0;
  };
}
