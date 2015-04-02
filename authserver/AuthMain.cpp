#include "AuthMain.h"

void AuthMain::run()
{
    QTime t;
    t.start();

    //=================
    //Command line init
    //=================

    m_threadCommandLine = new QThread();
    m_commandLine = new AuthCommandLine("Auth>");
    m_commandLine->moveToThread(m_threadCommandLine);

    connect(m_threadCommandLine, SIGNAL(started()), m_commandLine, SLOT(run()));
    connect(m_commandLine, SIGNAL(finished()), m_threadCommandLine, SLOT(quit()));
    connect(m_commandLine, SIGNAL(finished()), m_threadCommandLine, SLOT(deleteLater()));

    //==========
    //Auth start
    //==========
    Log::Write(LOG_TYPE_NORMAL, "WW       WW         kk     BBBBB                 ");
    Log::Write(LOG_TYPE_NORMAL, "WW       WW   aa aa kk  kk BB   B   oooo  xx  xx ");
    Log::Write(LOG_TYPE_NORMAL, "WW   W   WW  aa aaa kkkkk  BBBBBB  oo  oo   xx   ");
    Log::Write(LOG_TYPE_NORMAL, " WW WWW WW  aa  aaa kk kk  BB   BB oo  oo   xx   ");
    Log::Write(LOG_TYPE_NORMAL, "  WW   WW    aaa aa kk  kk BBBBBB   oooo  xx  xx ");
    Log::Write(LOG_TYPE_NORMAL, "");
    Log::Write(LOG_TYPE_NORMAL, "Wakfu sandbox developped by Sgt Fatality & Totomakers.\n");
    Log::Write(LOG_TYPE_NORMAL, "Press ctrl + c to quit.\n");

    if (!sAuthServer->Initialize())
        QCoreApplication::exit();

    Log::Write(LOG_TYPE_NORMAL, "\nWakBox::AuthServer started in %s sec.\n", QString::number(t.elapsed() / IN_MILLISECONDS).toLatin1().data());

    m_threadCommandLine->start();
}

void AuthMain::stop()
{
   m_commandLine->stop();
   delete m_commandLine;

   sAuthServer->Delete();
}
