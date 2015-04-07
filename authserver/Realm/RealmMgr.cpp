#include "RealmMgr.h"
#include "Databases/Database.h"

template<> RealmMgr*  Singleton<RealmMgr>::m_instance = 0;

RealmMgr::RealmMgr()
{
    m_communities.clear();
    m_communities[COMMUNITY_FR]     = RealmCommunity(COMMUNITY_FR, "fr");
    m_communities[COMMUNITY_UK]     = RealmCommunity(COMMUNITY_UK, "uk");
    m_communities[COMMUNITY_INT]    = RealmCommunity(COMMUNITY_INT, "en");
    m_communities[COMMUNITY_DE]     = RealmCommunity(COMMUNITY_DE, "de");
    m_communities[COMMUNITY_ES]     = RealmCommunity(COMMUNITY_ES, "es");
    m_communities[COMMUNITY_RU]     = RealmCommunity(COMMUNITY_RU, "ru");
    m_communities[COMMUNITY_PT]     = RealmCommunity(COMMUNITY_PT, "pt");
    m_communities[COMMUNITY_NL]     = RealmCommunity(COMMUNITY_NL, "nl");
    m_communities[COMMUNITY_JP]     = RealmCommunity(COMMUNITY_JP, "jp");
    m_communities[COMMUNITY_IT]     = RealmCommunity(COMMUNITY_IT, "it");
    m_communities[COMMUNITY_NA]     = RealmCommunity(COMMUNITY_NA, "na");
    m_communities[COMMUNITY_CN]     = RealmCommunity(COMMUNITY_CN, "cn");
    m_communities[COMMUNITY_ASIA]   = RealmCommunity(COMMUNITY_ASIA, "asia");
    m_communities[COMMUNITY_TW]     = RealmCommunity(COMMUNITY_TW, "tw");

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
        QString version = result.value("version").toString();
        qint32 id = (quint32) result.value("realm_id").toInt();
        QString name  = result.value("name").toString();
        QString address = result.value("address").toString();
        qint32 port  = (quint32) result.value("port").toInt();
        quint32 playerLimit  = (quint32) result.value("player_limit").toInt();
        bool locked = result.value("locked").toBool();
        CommunityId communityId = (CommunityId) result.value("community").toInt();

        Realm* realm = new Realm(id);
        realm->SetVersion(version);
        realm->SetName(name);
        realm->SetHostAddress(address);
        realm->SetPortNo(port);
        realm->SetPlayerLimit(playerLimit);
        realm->Lock(locked);
        realm->SetCommunity(this->GetCommunityById(communityId));

        m_realms.push_back(realm);
    }
}

RealmCommunity RealmMgr::GetCommunityById(CommunityId id)
{
    return m_communities.value(id);
}

void RealmMgr::ToRealmPacket(WorldPacket& dataProxy, Packet& dataInfo)
{
    int realmCount = m_realms.size();
    dataProxy << realmCount;

    for (RealmList::ConstIterator itr = m_realms.begin(); itr != m_realms.end(); ++itr)
    {
        Realm* realm = (*itr);

        // ===================
        // Part 1 : Realm Entry
        // ===================

        dataEntry << realm->GetId();
        dataEntry.WriteString(realm->GetName(), STRING_SIZE_4);

        dataEntry << (quint32) realm->GetCommunity().id;
        dataEntry.WriteString(realm->GetHostAddress(), STRING_SIZE_4);

        // Port count (loop)
        dataEntry << (int) 1;
        dataEntry << realm->GetPortNo();

        // Order
        dataEntry << (quint8) realm->GetId();

        // =====================
        // Part 2 : Realm Info
        // =====================

        dataEntry << realm->GetId();

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

        // Realm configuration
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
        dataInfo << realm->IsLock();
    }

    dataEntry << realmCount;
}

