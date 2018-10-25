//---------------------------------------------------------------------------
// ShaderProgramGL.h
//---------------------------------------------------------------------------

#pragma once

#include <string>
#include <vector>
#include "GL/glew.h"
#include "graphics/IShaderProgram.h"

namespace CC
{
  class ShaderProgramGL : public IShaderProgram
  {
    public:
      ShaderProgramGL(const std::string& vertexShaderFileName,
                      const std::string& fragmentShaderFileName);

      void Compile();
      void Link();
      void Validate();
      void Bind();
      void UnBind();
      void AddUniform(const std::string& name, const UniformType& type);

    private:
      void ApplyUniforms();

      std::string m_vertexShaderSource;
      std::string m_fragmentShaderSource;
      GLuint m_shaderProgram;
      std::vector<std::pair<std::string, UniformType> > m_uniforms;
  };
}
