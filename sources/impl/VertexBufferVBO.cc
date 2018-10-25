//---------------------------------------------------------------------------
// VertexBufferVBO.cc
//---------------------------------------------------------------------------

#include "system/ILowLevelSystem.h"
#include "graphics/ILowLevelGraphics.h"
#include "impl/VertexBufferVBO.h"

namespace CC
{
  //-------------------------------------------------------------------------
  VertexBufferVBO::VertexBufferVBO(const ILowLevelGraphics& lowLevelGraphics) :
    m_lowLevelGraphics(lowLevelGraphics)
  {
  }

  //-------------------------------------------------------------------------
  void VertexBufferVBO::AddVertex(const Vector3f& vertex)
  {
    m_vertexArray.push_back(vertex);
  }

  //-------------------------------------------------------------------------
  void VertexBufferVBO::Bind()
  {
    glBindBuffer(GL_ARRAY_BUFFER, m_handle);

    // m_lowLevelGraphics->ConnectAttributes();
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
  }

  //-------------------------------------------------------------------------
  void VertexBufferVBO::UnBind()
  {
    glDisableVertexAttribArray(0);
  }

  //-------------------------------------------------------------------------
  void VertexBufferVBO::Compile()
  {
    // Create VBO vertex arrays
    glGenBuffers(1, &m_handle);

    glBindBuffer(GL_ARRAY_BUFFER, m_handle);
    glBufferData(GL_ARRAY_BUFFER, m_vertexArray.size() * sizeof(Vector3f), &m_vertexArray[0], GL_STATIC_DRAW);
    Log("VBO compiled\n");
  }

  //-------------------------------------------------------------------------
  void VertexBufferVBO::Draw(const VertexBufferDrawType drawType)
  {
    // Get the draw call topology
    GLenum topology = getDrawTopology(drawType);

    glDrawArrays(topology, 0, m_vertexArray.size());
  }

  //-------------------------------------------------------------------------
  GLenum VertexBufferVBO::getDrawTopology(const VertexBufferDrawType drawType)
  {
    switch (drawType)
    {
      case DRAWTYPE_TRIANGLES:
        return GL_TRIANGLES;

      default:
        return GL_POINTS;
    }
  }
}
