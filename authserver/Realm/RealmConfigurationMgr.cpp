#include "RealmConfigurationMgr.h"
#include "Databases/Database.h"
#include "Databases/AuthDatabase.h"

RealmConfigurationMgr::RealmConfigurationMgr()
{
}

RealmConfigurationMgr::~RealmConfigurationMgr()
{
    for (RealmConfAvailableMap::const_iterator itr = m_configurationAvailable.begin(); itr != m_configurationAvailable.end(); ++itr)
       delete itr.value();
}

void RealmConfigurationMgr::InitRealmConfigurationAvailable()
{
    #define ADD_REALM_CONF_AVAILABLE(propertyId, key, defaultValue, type, sharedWithClient) AddConfigurationAvailable(propertyId, key, defaultValue, type, sharedWithClient);

    m_configurationAvailable.clear();
    ADD_REALM_CONF_AVAILABLE(RealmConfigurationPropertyId::MONITORED_PROPERTIES, "monitoredproperties.enable", "true", RealmConfigurationValueType::TYPE_BOOLEAN, false);
}

void RealmConfigurationMgr::AddConfigurationAvailable(RealmConfigurationPropertyId id, QString key, QString defaultValue, RealmConfigurationValueType type, bool sharedWithClient)
{
   if (!RealmConfigurationAvailable::CheckValue(type, defaultValue))
   {
       Log::Write(LOG_TYPE_ERROR, "RealmConfigurationMgr::InitRealmConfigurationAvailable have invalid default value or invalid type (key:%i)", (int)id);
       return;
   }

    m_configurationAvailable[id] = new RealmConfigurationAvailable(id, key, defaultValue, type, sharedWithClient);
}

void RealmConfigurationMgr::LoadRealmConfiguration(Realm* realm)
{
    QSqlQuery result = sAuthDatabase->Query(SELECT_REALM_CONFIGURATION, QVariantList() << realm->GetId());

    while (result.next())
    {
    }
}




