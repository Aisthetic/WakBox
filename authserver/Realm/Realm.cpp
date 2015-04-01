#include "Realm.h"
#include "RealmMgr.h"

Realm::Realm(QObject *parent) : QObject(parent)
{
    m_id = 0;
    m_name = QString();
    m_address = QHostAddress::LocalHost;
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
    m_address           = QHostAddress(query.value("address").toString());
    m_port              = (quint32) query.value("port").toInt();
    m_version           = query.value("version").toString();
    m_playerCount       = (quint32) query.value("player_count").toInt();
    m_playerLimit       = (quint32) query.value("player_limit").toInt();
    m_locked            = query.value("locked").toBool();

    m_community.id      = (CommunityId) query.value("community").toInt();
    m_community.name    = sRealmMgr->GetCommunityNameById(m_community.id);
}

