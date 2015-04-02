#include "CommandLine.h"

CommandLine::CommandLine(QString title, QObject *parent) : QObject(parent)
{
    m_stop = false;
    m_title = title;
}

void CommandLine::run()
{
    forever
    {
        if(m_stop)
            break;

        ConsoleAppender::WriteLine(ConsoleAppender::eColor::LIGHTCYAN, m_title);

        std::string command_str;
        std::getline(std::cin, command_str);

        if(command_str.length() == 0)
            continue;

        QString command = QString::fromStdString(command_str);
        command.replace('\n', "");
        command.replace('\r', "");

        fflush(stdout);
        HandleCommand(command);
    }

    Log::Write(LOG_TYPE_DEBUG, "CommandLine %s stopped", m_title.toLatin1().data());
    emit finished();
}
