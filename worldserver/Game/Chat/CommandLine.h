#ifndef COMMANDLINE_H
#define COMMANDLINE_H

#include <QtCore>
#include <iostream>

#include "Console/ConsoleAppender.h"
#include "Chat.h"
#include "World/World.h"

using namespace std;

class CommandLine : public QThread
{
    Q_OBJECT
public:
    CommandLine(QObject* parent = 0) : QThread(parent) {}

    virtual void run()
    {
        forever
        {
            if(!World::Instance()->IsRunning())
                break;

            ConsoleAppender::Write(ConsoleAppender::eColor::LIGHTCYAN, "Wakbox>");
            fflush(stdout);

            std::string command;
            std::getline(std::cin, command);

            if (command != "")
            {
                QString commandStr = QString::fromStdString(command);

                if (commandStr.size() > 0 && commandStr.at(0) != '.')
                    commandStr.prepend('.');

                Chat::Instance()->ParseCommand(commandStr);
            }
        }
    }
};

#endif
