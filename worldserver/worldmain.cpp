#include "WorldMain.h"

void WorldMain::run()
{
    m_commandLine = new CommandLine();
    m_worldRunnable = new WorldRunnable();

    QTime t;
    t.start();

    Log::Write(LOG_TYPE_NORMAL, "WW      WW         kk     BBBBB                 ");
    Log::Write(LOG_TYPE_NORMAL, "WW      WW   aa aa kk  kk BB   B   oooo  xx  xx ");
    Log::Write(LOG_TYPE_NORMAL, "WW   W  WW  aa aaa kkkkk  BBBBBB  oo  oo   xx   ");
    Log::Write(LOG_TYPE_NORMAL, " WW WWW WW aa  aaa kk kk  BB   BB oo  oo   xx   ");
    Log::Write(LOG_TYPE_NORMAL, "  WW   WW   aaa aa kk  kk BBBBBB   oooo  xx  xx ");
    Log::Write(LOG_TYPE_NORMAL, "");
    Log::Write(LOG_TYPE_NORMAL, "Wakfu sandbox developped by Sgt Fatality & Totomakers.");
    Log::Write(LOG_TYPE_NORMAL, "");
    Log::Write(LOG_TYPE_NORMAL, "Press ctrl + c to quit.");

    if (!sWorldServer->Initialize())
        QCoreApplication::exit();

    Log::Write(LOG_TYPE_NORMAL, "Worldserver started in %s sec.", QString::number(t.elapsed() / IN_MILLISECONDS).toLatin1().data());

    m_commandLine->start();
    m_worldRunnable->start();
}

void WorldMain::stop()
{
    m_commandLine->exit();
    m_worldRunnable->exit();
    sWorldServer->Delete();
}
