//---------------------------------------------------------------------------
// IShaderProgram.h
//---------------------------------------------------------------------------

#pragma once

#include "graphics/GraphicsTypes.h"

namespace CC
{
  class IShaderProgram
  {
    public:
      virtual ~IShaderProgram() {};
      virtual void Compile() = 0;
      virtual void Link() = 0;
      virtual void Validate() = 0;
      virtual void Bind() = 0;
      virtual void UnBind() = 0;
      virtual void AddUniform(const std::string& name, const UniformType& type) = 0;
  };
}
