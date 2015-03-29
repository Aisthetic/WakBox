#ifndef WORLDRUNNABLE_H
#define WORLDRUNNABLE_H

#include <QtCore>
#include <QTimer>

#include "World.h"

class WorldLoop : public QObject
{

    Q_OBJECT
public:
    WorldLoop(QObject *parent = 0) : QObject(parent) { m_stop = false; }

public slots:
    void run();
    void stop() { m_stop = true; }

 private:
    bool m_stop;

signals:
    void finished();
};

#endif
