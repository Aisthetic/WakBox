#ifndef COMMANDLINE_H
#define COMMANDLINE_H

#include <QtCore>
#include <iostream>

#include "Console/ConsoleAppender.h"
#include "Chat.h"
#include "World/World.h"

class CommandLine : public QObject
{
    Q_OBJECT
public:
    CommandLine(QObject* parent = 0) : QObject(parent) { m_stop = false; }

signals:
    void finished();

public slots:
    void run();
    void stop() { m_stop = true; }

 private:
    bool m_stop;

};

#endif
