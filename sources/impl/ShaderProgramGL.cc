//---------------------------------------------------------------------------
// ShaderProgramGL.cc
//---------------------------------------------------------------------------

#include <fstream>
#include "system/ILowLevelSystem.h"
#include "impl/ShaderProgramGL.h"

namespace CC
{
  //-------------------------------------------------------------------------
  ShaderProgramGL::ShaderProgramGL(const std::string& vertexShaderFileName,
                                   const std::string& fragmentShaderFileName) :
    m_vertexShaderSource(""),
    m_fragmentShaderSource("")
  {
    // Read vertex shader
    std::ifstream vertexShaderFile(vertexShaderFileName);
    std::string line;

    if (vertexShaderFile.is_open())
    {
      while(std::getline(vertexShaderFile, line))
      {
        m_vertexShaderSource += line + "\n";
      }
    }
    Log("Read vertex shader: %s\n", m_vertexShaderSource.c_str());

    // Read fragment shader
    std::ifstream fragmentShaderFile(fragmentShaderFileName);

    if (fragmentShaderFile.is_open())
    {
      while(std::getline(fragmentShaderFile, line))
      {
        m_fragmentShaderSource += line + "\n";
      }
    }
    Log("Read fragment shader: %s\n", m_fragmentShaderSource.c_str());
  }

  //-------------------------------------------------------------------------
  void ShaderProgramGL::Compile()
  {
    m_shaderProgram = glCreateProgram();

    // Vertex shader
    GLenum ShaderType = GL_VERTEX_SHADER;
    GLuint ShaderObj = glCreateShader(ShaderType);
    const GLchar* vsText = m_vertexShaderSource.c_str();
    glShaderSource(ShaderObj, 1, &vsText, NULL);
    glCompileShader(ShaderObj);

    // Check for errors
    GLint success;
    glGetShaderiv(ShaderObj, GL_COMPILE_STATUS, &success);
    if (!success)
    {
      GLchar InfoLog[1024];
      glGetShaderInfoLog(ShaderObj, sizeof(InfoLog), NULL, InfoLog);
      Log("Error compiling shader type %d: %s\n", ShaderType, InfoLog);
    }
    else
    {
      glAttachShader(m_shaderProgram, ShaderObj);
      Log("Vertex Shader successfully compiled!\n");
    }

    // Fragment shader
    ShaderType = GL_FRAGMENT_SHADER;
    ShaderObj = glCreateShader(ShaderType);
    const GLchar* fsText = m_fragmentShaderSource.c_str();
    glShaderSource(ShaderObj, 1, &fsText, NULL);
    glCompileShader(ShaderObj);

    // Check for errors
    glGetShaderiv(ShaderObj, GL_COMPILE_STATUS, &success);
    if (!success)
    {
      GLchar InfoLog[1024];
      glGetShaderInfoLog(ShaderObj, sizeof(InfoLog), NULL, InfoLog);
      Log("Error compiling shader type %d: %s\n", ShaderType, InfoLog);
    }
    else
    {
      glAttachShader(m_shaderProgram, ShaderObj);
      Log("Fragment Shader successfully compiled!\n");
    }
  }

  //-------------------------------------------------------------------------
  void ShaderProgramGL::Link()
  {
    glLinkProgram(m_shaderProgram);

    // Check for errors
    GLint success;
    glGetProgramiv(m_shaderProgram, GL_LINK_STATUS, &success);
    if (!success)
    {
      GLchar ErrorLog[1024];
      glGetProgramInfoLog(m_shaderProgram, sizeof(ErrorLog), NULL, ErrorLog);
      Log("Error linking shader program: %s\n", ErrorLog);
    }
    else
    {
      Log("Shader Program successfully linked!\n");
    }
  }

  //-------------------------------------------------------------------------
  void ShaderProgramGL::Validate()
  {
    glValidateProgram(m_shaderProgram);

    // Check for errors
    GLint success;
    glGetProgramiv(m_shaderProgram, GL_VALIDATE_STATUS, &success);
    if (!success)
    {
      GLchar ErrorLog[1024];
      glGetProgramInfoLog(m_shaderProgram, sizeof(ErrorLog), NULL, ErrorLog);
      Log("Error validating shader program: %s\n", ErrorLog);
    }
    else
    {
      Log("Shader Program successfully validated!\n");
    }
  }

  //-------------------------------------------------------------------------
  void ShaderProgramGL::ApplyUniforms()
  {
    if (m_uniforms.size() == 0)
    {
      Log("No uniforms to apply\n");
      return;
    }

    for (std::vector< std::pair<std::string, UniformType> >::const_iterator it = m_uniforms.begin();
         it != m_uniforms.end(); ++it)
    {
      const std::string& name = it->first;
      const UniformType& type = it->second;
      GLuint location = glGetUniformLocation(m_shaderProgram, it->first.c_str());

      if (location == -1)
      {
        Log("Cannot obtain location for uniform %s\n", name.c_str());
      }

      // FIXME: Retrieve the uniform value
      switch (type)
      {
        case UNIFORMTYPE_FLOAT:
          glUniform1f(location, 0.5f);
          break;

        case UNIFORMTYPE_MATRIX:
          // Not yet implemented
          break;
      }
    }
    Log("Shader uniforms applied\n");
  }

  //-------------------------------------------------------------------------
  void ShaderProgramGL::AddUniform(const std::string& name, const UniformType& type)
  {
    m_uniforms.push_back(std::make_pair(name, type));
  }

  //-------------------------------------------------------------------------
  void ShaderProgramGL::Bind()
  {
    glUseProgram(m_shaderProgram);
    Log("Shader program bound\n");

    ApplyUniforms();
    Log("Shader uniforms applied\n");
  }

  //-------------------------------------------------------------------------
  void ShaderProgramGL::UnBind()
  {
    glUseProgram(0);
    Log("Shader program unbound\n");
  }
}
