#include <QCoreApplication>
#include <csignal>

#include "WorldMain.h"


void stop(int /*s*/)
{
   QCoreApplication::exit();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    WorldMain* app = new WorldMain(&a);
    QObject::connect(&a, &QCoreApplication::aboutToQuit, app, &WorldMain::stop);

    signal(SIGINT, &stop);
    signal(SIGTERM, &stop);

    QTimer::singleShot(0, app, SLOT(run()));

    return a.exec();
}
