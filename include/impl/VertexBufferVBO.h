//---------------------------------------------------------------------------
// VertexBufferVBO.h
//---------------------------------------------------------------------------

#pragma once

#include <vector>
#include "GL/glew.h"
#include "graphics/IVertexBuffer.h"

// Fwd Declarations
namespace CC
{
  class ILowLevelGraphics;
}

namespace CC
{
  class VertexBufferVBO : public IVertexBuffer
  {
    public:
      VertexBufferVBO(const ILowLevelGraphics& lowLevelGraphics);
      void AddVertex(const Vector3f& vertex);
      void Bind();
      void UnBind();
      void Compile();
      void Draw(VertexBufferDrawType drawType);

    private:
      GLenum getDrawTopology(const VertexBufferDrawType drawType);

      const ILowLevelGraphics& m_lowLevelGraphics;
      std::vector<Vector3f> m_vertexArray;
      unsigned int m_handle;
  };
}
