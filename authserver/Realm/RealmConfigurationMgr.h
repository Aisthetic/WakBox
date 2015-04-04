#ifndef REALMCONFIGURATIONMGR_H
#define REALMCONFIGURATIONMGR_H

#include "Utils/Singleton.h"
#include "RealmConfiguration.h"
#include "RealmConfigurationAvailable.h"
#include "Realm.h"

typedef QMap<RealmConfigurationPropertyId, RealmConfigurationAvailable*> RealmConfAvailableMap;

class RealmConfigurationMgr : public Singleton<RealmConfigurationMgr>
{
public:
    RealmConfigurationMgr();
    ~RealmConfigurationMgr();

    void LoadRealmConfiguration(Realm* realmd);
    
private:
    RealmConfAvailableMap m_realmConfigurationAvailable;
    void InitRealmConfigurationAvailable();
    void AddConfigurationAvailable(RealmConfigurationPropertyId id, QString key, QString defaultValue, RealmConfigurationValueType type, bool sharedWithClient);
};

#define sRealmConfigurationMgr RealmConfigurationMgr::Instance()

#endif // REALMCONFIGURATIONMGR_H
