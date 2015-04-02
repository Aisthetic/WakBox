#ifndef WORLDCOMMANDLINE_H
#define WORLDCOMMANDLINE_H

#include <QtCore>
#include <iostream>

#include "Console/CommandLine.h"
#include "Console/ConsoleAppender.h"
#include "Chat/Chat.h"
#include "World/World.h"

class WorldCommandLine : public CommandLine
{
    Q_OBJECT

public:
    WorldCommandLine(QString title, QObject* parent = 0) : CommandLine(title, parent) {}
    void HandleCommand(QString command);
};

#endif
