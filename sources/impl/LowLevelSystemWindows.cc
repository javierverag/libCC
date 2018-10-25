//---------------------------------------------------------------------------
// LowLevelSystemWindows.cc
//---------------------------------------------------------------------------

#include <cstdio>
#include <cstdarg>
#include <windows.h>
#include "impl/LowLevelSystemWindows.h"

using namespace std;

extern int ccMain();

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR	lpCmdLine, int nCmdShow)
{
    return ccMain();
}

namespace CC
{
    //-------------------------------------------------------------------------
    unsigned long GetApplicationTime()
    {
        static LARGE_INTEGER frequency = { 0, 0 };
        static LARGE_INTEGER zeroTime = { 0, 0 };
        LARGE_INTEGER newTime;

        if (!zeroTime.QuadPart)
        {
            QueryPerformanceFrequency(&frequency);
            QueryPerformanceCounter(&zeroTime);
        }
        QueryPerformanceCounter(&newTime);

        // Return time in milliseconds since first frame
        return (unsigned long)((newTime.QuadPart - zeroTime.QuadPart) /
            (frequency.QuadPart / 1000.0));
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
        if (m_logFile)
        {
            fclose(m_logFile);
        }
    }

    //-------------------------------------------------------------------------
    void LogWriter::Write(const string& message)
    {
        if (!m_logFile)
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
