#ifndef WORLDHMAIN_H
#define WORLDHMAIN_H

#include "Utils/ConsoleApp.h"
#include "WorldMain.h"
#include "Logs/Log.h"
#include "Define.h"
#include "Chat/CommandLine.h"
#include "World/WorldLoop.h"

class WorldMain : public ConsoleApp
{
    Q_OBJECT

public:
    WorldMain(QObject* parent) : ConsoleApp(parent) {}


public slots:
    void run();
    void stop();

private :
    QThread* m_threadCommandLine;
    QThread* m_threadWorldLoop;

    CommandLine* m_commandLine;
    WorldLoop* m_worldLoop;
};

#endif // AUTHMAIN_H
