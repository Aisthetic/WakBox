#ifndef WORLD_H
#define WORLD_H

#include <QtCore>
#include "WorldServer.h"
#include "Logs/Log.h"
#include "Configuration/ConfigMgr.h"
#include "Utils/Singleton.h"

class WorldSession;

typedef QList<WorldSession*> SessionList;

class World : public Singleton<World>
{
    Q_OBJECT

public:
    World();
    ~World();

    bool Initialize();

    void AddSession(WorldSession* session);
    void RemoveSession(WorldSession* session);

    void Update(quint64 diff);

signals:
   void stopped();

private:
    SessionList m_sessions;
};

#define sWorld World::Instance()

#endif
