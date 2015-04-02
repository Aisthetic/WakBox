#ifndef AUTHMAIN_H
#define AUTHMAIN_H

#include "Logs/Log.h"
#include "Utils/ConsoleApp.h"
#include "AuthServer.h"
#include "AuthCommandLine.h"
#include "Define.h"


class AuthMain : public ConsoleApp
{
    Q_OBJECT

public:
    AuthMain(QObject* parent) : ConsoleApp(parent) {}

public slots:
    void run();
    void stop();


private :
    QThread* m_threadCommandLine;
    AuthCommandLine* m_commandLine;

};

#endif // AUTHMAIN_H
