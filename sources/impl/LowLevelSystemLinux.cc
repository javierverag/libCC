//---------------------------------------------------------------------------
// LowLevelSystemLinux.cc
//---------------------------------------------------------------------------

#include <cstdio>
#include <cstdarg>
#include <sys/time.h>
#include "impl/LowLevelSystemLinux.h"

using namespace std;

extern int ccMain();

//---------------------------------------------------------------------------
int main(int argc, char *argv[])
{
  return ccMain();
}

namespace CC
{
  unsigned long GetApplicationTime()
  {
    static clock_t zeroClock = clock();
    clock_t newClock = clock();

    // Return time in milliseconds since first frame
    return (unsigned long)((float)(newClock-zeroClock) /
        ((float)CLOCKS_PER_SEC/1000.0));
  }

  static LogWriter logWriter("cc.log");

  //-------------------------------------------------------------------------
  LogWriter::LogWriter(const string& logFileName) :
    m_logFileName(logFileName)
  {
  }

  //-------------------------------------------------------------------------
  LogWriter::~LogWriter()
  {
    if(m_logFile)
    {
      fclose(m_logFile);
    }
  }

  //-------------------------------------------------------------------------
  void LogWriter::Write(const string& message)
  {
    if(!m_logFile)
    {
      ReopenFile();
    }
    fprintf(m_logFile, message.c_str());
    fflush(m_logFile);
  }

  //-------------------------------------------------------------------------
  void LogWriter::ReopenFile()
  {
    if (m_logFile)
    {
      fclose(m_logFile);
    }
    m_logFile = fopen(m_logFileName.c_str(), "w");
  }

  //-------------------------------------------------------------------------
  void Log(const char* format, ...)
  {
    char text[2048];
    va_list args;
    if (format == NULL)
      return;
    va_start(args, format);
    vsprintf(text, format, args);
    va_end(args);

    string message = "";
    message += text;
    logWriter.Write(message);
  }
}
