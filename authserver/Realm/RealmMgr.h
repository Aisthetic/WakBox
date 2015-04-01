#ifndef REALMMGR_H
#define REALMMGR_H

#include "Utils/Singleton.h"
#include "Packets/WorldPacket.h"
#include "Realm.h"

typedef QMap<CommunityId, QString> RealmCommunityMap;
typedef QList<Realm*> RealmsList;

class RealmMgr : public Singleton<RealmMgr>
{
public:
    RealmMgr();
    ~RealmMgr();

    void LoadRealmList();

    QString GetCommunityNameById(CommunityId id)
    {
        return m_communities.value(id);
    }

    void ToRealmPacket(WorldPacket& data, Packet& data2);

private:
    RealmCommunityMap m_communities;
    RealmsList m_realms;
};

#define sRealmMgr RealmMgr::Instance()

#endif // REALMMGR_H
