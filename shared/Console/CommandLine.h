#ifndef COMMANDLINE_H
#define COMMANDLINE_H

#include <QtCore>
#include <iostream>
#include "Console/ConsoleAppender.h"
#include "Logs/Log.h"

class CommandLine : public QObject
{
    Q_OBJECT

public:
    CommandLine(QString title, QObject* parent = 0);
    virtual void HandleCommand(QString command) = 0;

signals:
    void finished();

public slots:
    void run();
    void stop() { m_stop = true; }

 private:
    bool m_stop;
    QString m_title;

};

#endif
