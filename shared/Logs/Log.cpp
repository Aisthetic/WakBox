#include "Log.h"

template<> Log*  Singleton<Log>::m_instance = 0;

Log::Log()
{
    m_logTypeConsole = LOG_TYPE_NORMAL;
    m_logTypeFile = LOG_TYPE_NORMAL;


    m_logConsoleColor[LOG_TYPE_NORMAL] = ConsoleAppender::eColor::WHITE;
    m_logConsoleColor[LOG_TYPE_INFO] = ConsoleAppender::eColor::CYAN;
    m_logConsoleColor[LOG_TYPE_DEBUG] = ConsoleAppender::eColor::LIGHTGREEN;
    m_logConsoleColor[LOG_TYPE_ERROR] = ConsoleAppender::eColor::RED;

    m_file = NULL;
}

Log::~Log()
{
    if(m_file) m_file->close(); //close the file
}

void Log::Initialize(ushort logConsoleLevel, QString logFile, ushort logFileLevel, QList<int> colors)
{
    m_logTypeConsole = LogType(logConsoleLevel);
    m_logTypeFile = LogType(logFileLevel);


    for(int i =0; i < colors.count(); i++)
    {
        if(i > LOG_TYPE_MAX) break;

        m_logConsoleColor[(LogType)i] = (ConsoleAppender::eColor)colors.at(i);
    }

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

    Log::Write(LOG_TYPE_ERROR, "Cannot open log file %s : %s", fileName.toLatin1().data(), error.toLatin1().data());
}

QString Log::GetLogTypeString(LogType logType)
{
    switch(logType)
    {
    case LOG_TYPE_INFO:
        return "[ Info ] ";
    case LOG_TYPE_DEBUG:
        return "[ Debug ] ";
    case LOG_TYPE_ERROR:
        return "[ Error ] ";
    case LOG_TYPE_NORMAL:
    default:
        return "";
    }
}

void Log::WriteLog(LogType logType, QString logMessage)
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

    va_list ap; //va_list is the list of parameters passed after message

    va_start(ap, message);

    QString logMessage;
    logMessage.vsprintf(message.toUtf8().data(), ap);
    logMessage = logTypeString + logMessage;
    Log::Instance()->WriteLog(logType, logMessage);

    va_end(ap); //clean
}
