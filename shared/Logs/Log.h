#ifndef LOG_H
#define LOG_H

#include <QtCore>
#include <iostream>
#include "Log.h"
#include "Configuration/ConfigMgr.h"
#include "Utils/Singleton.h"
#include "Console/ConsoleAppender.h"

using namespace std;


/**
 * @brief The LogType enum contains all available log type
 */
enum LogType
{
    LOG_TYPE_NORMAL = 0,
    LOG_TYPE_ERROR,
    LOG_TYPE_INFO,
    LOG_TYPE_DEBUG,

    LOG_TYPE_MAX, //Do not use, just serves to count the number of input
};

typedef QMap<LogType, ConsoleAppender::eColor> LogConsoleColor;

/**
 * @brief The Log class
 */
class Log : public Singleton<Log>
{
public:
    Log();
    ~Log();

    /**
     * @brief GetLogTypeString returns the string added to the file for each type of log
     * @param logType
     * @return
     */
    static QString GetLogTypeString(LogType logType);

    /**
     * @brief Initialize initializes the log instance, define the log file and some options
     * @param logConsoleLevel
     * @param logFileLevel
     * @param logFile
     * @param colors
     */
    void Initialize(ushort logConsoleLevel, QString logFile, ushort logFileLevel, QList<int> colors);

    /**
     * @brief WriteLog write a line in the log file directly, don't append [LOG_TYPE]
     * @param logType
     * @param logMessage
     */
    void WriteLog(LogType logType, QString logMessage);

    /**
     * @brief Write write a line with one or more parameters
     * @param logType
     * @param message
     */
    static void Write(LogType logType, QString message, ...);

private:
    /**
     * @brief m_logTypeConsole is minimum level to display in the console
     */
    LogType m_logTypeConsole;

    /**
     * @brief m_logTypeFile is minimum level to append to the file
     */
    LogType m_logTypeFile;

    /**
     * @brief m_logConsoleColor associated color each log level
     */
    LogConsoleColor m_logConsoleColor;

    /**
     * @brief m_file is pointer to the log file
     */
    QFile* m_file;

    /**
     * @brief OpenFile open the log file - only called in initialize
     * @param fileName
     */
    void OpenFile(QString fileName);
};

#endif
