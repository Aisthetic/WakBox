#ifndef CONSOLEAPP_H
#define CONSOLEAPP_H

#include <QObject>

class ConsoleApp : public QObject
{
    Q_OBJECT
public:
     ConsoleApp(QObject *parent = 0) : QObject(parent) {}

signals:
    void run();
    void stop();

};

#endif // CONSOLEAPP_H
