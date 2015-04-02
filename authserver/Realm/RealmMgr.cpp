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

void RealmMgr::ToRealmPacket(WorldPacket& dataProxy, Packet& dataInfo)
{
    int realmCount = m_realms.size();
    dataProxy << realmCount;

    for (RealmsList::ConstIterator itr = m_realms.begin(); itr != m_realms.end(); ++itr)
    {
        Realm* realm = (*itr);

        // ===
        // = Part 1 : Proxy Info
        // ===

        dataProxy << realm->GetId();
        dataProxy.WriteString(realm->GetName(), STRING_SIZE_4);

        dataProxy << (quint32) realm->GetCommunity().id;
        data.WriteString(realm->GetHostAddress(), STRING_SIZE_4);

        // Port count (loop)
        dataProxy << (int) 1;
        dataProxy << realm->GetPort();

        // Order
        dataProxy << (quint8) realm->GetId();

        // ===
        // = Part 2 : World Info
        // ===

        dataInfo << realm->GetId();

        // World version
        dataInfo.StartBlock<int>();
        {
            QStringList version = realm->GetVersion().split(".");

            dataInfo << (quint8)  version.at(0).toUShort();
            dataInfo << (quint16) version.at(1).toUShort();
            dataInfo << (quint8)  version.at(2).toUShort();
            dataInfo.WriteString("-1");
        }
        dataInfo.EndBlock<int>();

        // World configuration
        dataInfo.StartBlock<int>();
        {
            /* Config example
            COMMUNITY_CHECK_ENABLE 208 : "true"
            COMMUNITY_REQUIRED 209 : 0
            COMMUNITY_FORBIDDEN 210 : ""
            AUTHORIZED_PARTNERS 220 : "default"
            SERVER_ID 420 : 1
            */

            // Nb of properties (loop)
            dataInfo << (int) 0;

            // Short config key
            // Int config string length
            // String config value
        }
        dataInfo.EndBlock<int>();

        dataInfo << realm->GetPlayerCount();
        dataInfo << realm->GetPlayerLimit();
        dataInfo << realm->IsLocked();
    }

    dataProxy << realmCount;
}

