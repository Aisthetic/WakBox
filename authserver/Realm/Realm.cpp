#include "Realm.h"
#include "RealmMgr.h"
#include "Logs/Log.h"

Realm::Realm(QObject *parent) : QObject(parent)
{
    m_id = 0;
    m_name = QString();
    m_address = QString();
    m_port = 0;
    m_version = QString();
    m_community.id = COMMUNITY_FR;
    m_community.name = QString();
    m_playerCount = 0;
    m_playerLimit = 0;
    m_locked = false;
}

Realm::~Realm()
{
}

void Realm::LoadFromDB(QSqlQuery query)
{
    m_id                = (quint32) query.value("realm_id").toInt();
    m_name              = query.value("name").toString();
    m_address           = query.value("address").toString();
    m_port              = (quint32) query.value("port").toInt();
    m_version           = query.value("version").toString();
    m_playerCount       = (quint32) query.value("player_count").toInt();
    m_playerLimit       = (quint32) query.value("player_limit").toInt();
    m_locked            = query.value("locked").toBool();

    m_community.id      = (CommunityId) query.value("community").toInt();
    m_community.name    = sRealmMgr->GetCommunityNameById(m_community.id);

    if(m_version.split(".").length() < 3)
    {
        Log::Write(LOG_TYPE_ERROR, "Invalid version pattern (x.x.x) for realmd %s", m_name.toLatin1().data());
        exit(0);
    }
}

