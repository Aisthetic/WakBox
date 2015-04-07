#include "Realm.h"
#include "RealmMgr.h"
#include "Logs/Log.h"
#include "RealmConfiguration.h"

Realm::Realm(qint32 id)
{
   m_id = id;

   SetVersion("0.0.0");
   SetCommunity(RealmCommunity(COMMUNITY_INT, "en"));
   SetHostAddress("127.0.0.1");
   SetPortNo(5556);
   SetPlayerLimit(500);
   SetName("Wakbox - default Realm");
   Lock(true);
}

Realm::~Realm()
{
}

quint32 Realm::GetPlayerCount()
{
    return 1; //@TODO
}

void Realm::SetVersion(QString version)
{
    if (!CheckVersion(version))
    {
        Log::Write(LOG_TYPE_ERROR, "Try to set invalid version for the realm %s", GetName().toLatin1().data());
        return;
    }

    m_version = version;
}

void Realm::AddConfiguration(RealmConfiguration *conf)
{
    m_configurations[(RealmConfigurationPropertyId)conf->GetId()] = conf;
}

void Realm::ClearConfiguration()
{
    m_configurations.clear();
}

RealmConfigurationMap Realm::GetConfigurations()
{
    return m_configurations;
}

bool Realm::CheckVersion(QString version)
{
    return (version.split(".").length() < 3);
}

