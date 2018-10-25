//---------------------------------------------------------------------------
// LowLevelGraphicsGLFW.cc
//---------------------------------------------------------------------------

#include <string>
#include "impl/VertexBufferVBO.h"
#include "impl/ShaderProgramGL.h"
#include "impl/LowLevelGraphicsGLFW.h"

namespace CC
{
  //---------------------------------------------------------------------------
  LowLevelGraphicsGLFW::LowLevelGraphicsGLFW()
  {
  }

  //---------------------------------------------------------------------------
  bool LowLevelGraphicsGLFW::Init(int width, int height,
      const std::string& windowCaption)
  {
    if (!glfwInit()) 
    {
      return false;
    }
    //glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_ES_API);
    m_window = glfwCreateWindow(width, height, windowCaption.c_str(),
        NULL, NULL);

    if (!m_window)
    {
      glfwTerminate();
      return false;
    }

    glfwMakeContextCurrent(m_window);

    // Must be done after GLFW is initialized and context is current
    GLenum result = glewInit();
    if (result != GLEW_OK)
    {
      return false;
    }

    SetupGL();
    glfwSwapBuffers(m_window);

    return true;
  }

  //---------------------------------------------------------------------------
  void LowLevelGraphicsGLFW::SwapBuffers()
  {
    glfwSwapBuffers(m_window);
  }

  //---------------------------------------------------------------------------
  IVertexBuffer* LowLevelGraphicsGLFW::CreateVertexBuffer()
  {
    return new VertexBufferVBO(*this);
  }

  //---------------------------------------------------------------------------
  IShaderProgram* LowLevelGraphicsGLFW::CreateShaderProgram(const std::string& vertexShaderFileName,
                                                            const std::string& fragmentShaderFileName)
  {
    return new ShaderProgramGL(vertexShaderFileName, fragmentShaderFileName);
  }

  //---------------------------------------------------------------------------
  void LowLevelGraphicsGLFW::SetupGL()
  {
    glClearColor(1.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);
  }

  //---------------------------------------------------------------------------
  GLFWwindow* LowLevelGraphicsGLFW::getWindow()
  {
    return m_window;
  }

  //---------------------------------------------------------------------------
  void LowLevelGraphicsGLFW::ConnectAttributes()
  {
  }

  //---------------------------------------------------------------------------
  void LowLevelGraphicsGLFW::SetMatrix(MatrixType type, const Matrixf& matrix, const IShaderProgram& program)
  {
    switch (type)
    {
      case MATRIXTYPE_MODELVIEW:
        // Not implemented
        break;

      case MATRIXTYPE_PROJECTION:
        // Not implemented
        break;
    }
  }
}
