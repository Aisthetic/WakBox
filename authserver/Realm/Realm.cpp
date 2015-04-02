#include "Realm.h"
#include "RealmMgr.h"
#include "Logs/Log.h"

Realm::Realm(qint32 id)
{
   m_id = id;

   //default value for all attributes
   m_version = "0.0.0";
   m_port = 5556;
   m_community = sRealmMgr->GetCommunityById(COMMUNITY_INT);
   m_locked = true;
   m_address = "127.0.0.1";
   m_playerLimit = 0;
   m_name = "";
}

Realm::~Realm()
{
}

quint32 Realm::GetPlayerCount()
{
    return 1;     //@TODO
}

void Realm::SetVersion(QString version)
{
    if(version.split(".").length() < 3)
    {
        Log::Write(LOG_TYPE_ERROR, "Invalid version pattern (x.x.x) for realmd %s", m_name.toLatin1().data());
        return;
    }

    m_version = version;
}

