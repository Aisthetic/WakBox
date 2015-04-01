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

void RealmMgr::ToRealmPacket(WorldPacket& data, Packet& data2)
{
    int realmCount = m_realms.size();
    data << realmCount;

    for (RealmsList::ConstIterator itr = m_realms.begin(); itr != m_realms.end(); ++itr)
    {
        Realm* realm = (*itr);

        // ===
        // = Part 1 : Proxy Info
        // ===

        data << realm->GetId();
        data.WriteString(realm->GetName(), STRING_SIZE_4);

        data << (quint32) realm->GetCommunity().id;
        data.WriteString(realm->GetHostAddress(), STRING_SIZE_4);

        // Port count (loop)
        data << (int) 1;
        data << realm->GetPort();

        // Order
        data << (quint8) realm->GetId();

        // ===
        // = Part 2 : World Info
        // ===

        data2 << realm->GetId();

        // World version
        data2.StartBlock<int>();
        {
            QStringList version = realm->GetVersion().split(".");

            data2 << (quint8)  version.at(0).toUShort();
            data2 << (quint16) version.at(1).toUShort();
            data2 << (quint8)  version.at(2).toUShort();
            data2.WriteString("-1");
        }
        data2.EndBlock<int>();

        // World configuration
        data2.StartBlock<int>();
        {
            /* Config example
            COMMUNITY_CHECK_ENABLE 208 : "true"
            COMMUNITY_REQUIRED 209 : 0
            COMMUNITY_FORBIDDEN 210 : ""
            AUTHORIZED_PARTNERS 220 : "default"
            SERVER_ID 420 : 1
            */

            // Nb of properties (loop)
            data2 << (int) 0;

            // Short config key
            // Int config string length
            // String config value
        }
        data2.EndBlock<int>();

        data2 << realm->GetPlayerCount();
        data2 << realm->GetPlayerLimit();
        data2 << realm->IsLocked();
    }

    data << realmCount;
}

