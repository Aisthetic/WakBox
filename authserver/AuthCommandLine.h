#ifndef AUTHCOMMANDLINE_H
#define AUTHCOMMANDLINE_H

#include <QtCore>
#include <iostream>

#include "Console/CommandLine.h"
#include "Console/ConsoleAppender.h"

class AuthCommandLine : public CommandLine
{
    Q_OBJECT

public:
    AuthCommandLine(QString title, QObject* parent = 0) : CommandLine(title, parent) {}
    void HandleCommand(QString command);
};

#endif
