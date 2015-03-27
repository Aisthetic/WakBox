#include <QCoreApplication>
#include <QTimer>
#include <csignal>

#include "AuthMain.h"

void stop(int /*s*/)
{
   QCoreApplication::exit();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    AuthMain* app = new AuthMain(&a);
    QObject::connect(&a, &QCoreApplication::aboutToQuit, app, &AuthMain::stop);

    signal(SIGINT, &stop);
    signal(SIGTERM, &stop);

    QTimer::singleShot(0, app, SLOT(run()));

    return a.exec();
}
