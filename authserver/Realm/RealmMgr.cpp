#include "RealmMgr.h"
#include "Databases/Database.h"

template<> RealmMgr*  Singleton<RealmMgr>::m_instance = 0;

RealmMgr::RealmMgr()
{
    m_communities[COMMUNITY_FR]     = "fr";
    m_communities[COMMUNITY_UK]     = "uk";
    m_communities[COMMUNITY_INT]    = "en";
    m_communities[COMMUNITY_DE]     = "de";
    m_communities[COMMUNITY_ES]     = "es";
    m_communities[COMMUNITY_RU]     = "ru";
    m_communities[COMMUNITY_PT]     = "pt";
    m_communities[COMMUNITY_NL]     = "nl";
    m_communities[COMMUNITY_JP]     = "jp";
    m_communities[COMMUNITY_IT]     = "it";
    m_communities[COMMUNITY_NA]     = "na";
    m_communities[COMMUNITY_CN]     = "cn";
    m_communities[COMMUNITY_ASIA]   = "asia";
    m_communities[COMMUNITY_TW]     = "tw";

    m_realms.clear();
}

RealmMgr::~RealmMgr()
{
    m_communities.clear();

    qDeleteAll(m_realms);
    m_realms.clear();
}

void RealmMgr::LoadRealmList()
{
    QSqlQuery result = sAuthDatabase->Query(SELECT_REALMS);
    while (result.next())
    {
        Realm* realm = new Realm();
        realm->LoadFromDB(result);

        m_realms.push_back(realm);
    }
}

void RealmMgr::ToRealmPacket(WorldPacket& data)
{
    //@TODO
}
