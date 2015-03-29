#include "CommandLine.h"


void CommandLine::run()
{
    forever
    {
        if(m_stop)
            break;

        ConsoleAppender::WriteLine(ConsoleAppender::eColor::LIGHTCYAN, "Wakbox>");

        std::string command_str;
        std::getline(std::cin, command_str);

        if(command_str.length() == 0)
            continue;

        QString command = QString::fromStdString(command_str);
        command.replace('\n', "");
        command.replace('\r', "");

        fflush(stdout);
        Chat::Instance()->ParseCommand(command);
    }

    Log::Write(LOG_TYPE_INFO, "Command line stopped");
    emit finished();
}
