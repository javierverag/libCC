//---------------------------------------------------------------------------
// LowLevelSystemEmsc.h
//---------------------------------------------------------------------------

#pragma once

#include <string>
#include "system/ILowLevelSystem.h"

namespace CC
{
  class LogWriter
  {
    public:
      LogWriter(const std::string& logFileName);
      ~LogWriter();

      void Write(const std::string& message);

    private:
      void ReopenFile();

      std::string m_logFileName;
      FILE* m_logFile;
  };

  class LowLevelSystemEmsc : public ILowLevelSystem
  {
  };
}

