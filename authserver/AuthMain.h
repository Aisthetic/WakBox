#ifndef AUTHMAIN_H
#define AUTHMAIN_H

#include "Utils/ConsoleApp.h"
#include "AuthServer.h"
#include "Logs/Log.h"
#include "Define.h"

class AuthMain : public ConsoleApp
{
    Q_OBJECT

public:
    AuthMain(QObject* parent) : ConsoleApp(parent) {}

public slots:
    void run();
    void stop();


};

#endif // AUTHMAIN_H
