#include "Log.h"
#include "Console/ConsoleAppender.h"

template<> Log*  Singleton<Log>::m_instance = 0;

Log::Log()
{
    m_logTypeConsole = LOG_TYPE_NORMAL;
    m_logTypeFile = LOG_TYPE_NORMAL;
    m_file = NULL;
}

Log::~Log()
{
    if(m_file)
        m_file->close();
}

void Log::Initialize(ushort logConsoleLevel, ushort logFileLevel, QString logFile, QStringList colors)
{
    m_logTypeConsole = LogType(logConsoleLevel);
    m_logTypeFile = LogType(logFileLevel);

    InitializeColors(colors);
    OpenFile(logFile);
}

void Log::OpenFile(QString fileName)
{
    m_file = new QFile(fileName, this);
    if(m_file->open(QIODevice::WriteOnly | QIODevice::Text))
        return;

    QString error = m_file->errorString();
    delete m_file;
    m_file = NULL;

    Log::Write(LOG_TYPE_NORMAL, "Cannot open log file %s : %s", fileName.toLatin1().data(), error.toLatin1().data());
}

void Log::WriteLog(QString logMessage, LogType logType)
{
    if (logType <= m_logTypeConsole)
         ConsoleAppender::WriteLine(m_logConsoleColor[logType], logMessage);

    if(m_file && logType <= m_logTypeFile)
    {
        m_file->write(logMessage.toUtf8() + "\n");
        m_file->flush();
    }
}

void Log::Write(LogType logType, QString message, ...)
{
    QString logTypeString = Log::GetLogTypeString(logType);

    va_list ap;
    va_start(ap, message);
    QString logMessage;
    logMessage.vsprintf(message.toUtf8().data(), ap);

    logMessage = logTypeString + logMessage;
    Log::Instance()->WriteLog(logMessage, logType);

    va_end(ap);
}

void Log::InitializeColors(QStringList colors)
{
    // default colors value
    m_logConsoleColor[LOG_TYPE_NORMAL] = ConsoleAppender::eColor::YELLOW;
    m_logConsoleColor[LOG_TYPE_DETAIL] = ConsoleAppender::eColor::MAGENTA;
    m_logConsoleColor[LOG_TYPE_DEBUG] = ConsoleAppender::eColor::RED;

    //parse
    for(int i=0; i < LOG_TYPE_MAX; i++)
    {
        QString logType = colors.value(i, "");
        if(logType != "")
        {
            bool convertToColor = false;
            int color = logType.toInt(&convertToColor);

            if(convertToColor)
                m_logConsoleColor[(LogType)i] = (ConsoleAppender::eColor)color;
        }
    }
}
