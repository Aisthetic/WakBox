#ifndef WORLDHMAIN_H
#define WORLDHMAIN_H

#include "Utils/ConsoleApp.h"
#include "WorldMain.h"
#include "Logs/Log.h"
#include "Define.h"

#include "Chat/CommandLine.h"
#include "World/WorldRunnable.h"

class WorldMain : public ConsoleApp
{
    Q_OBJECT

public:
    WorldMain(QObject* parent) : ConsoleApp(parent) {}

public slots:
    void run();
    void stop();

private :
    CommandLine* m_commandLine;
    WorldRunnable* m_worldRunnable;
};

#endif // AUTHMAIN_H
