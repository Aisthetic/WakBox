#ifndef REALM_H
#define REALM_H

#include <QObject>
#include <QHostAddress>
#include "Define.h"
#include "RealmConfigurationAvailable.h"

class RealmConfiguration;

struct RealmCommunity
{
    CommunityId id;
    QString name;

public:
    RealmCommunity() {}
    RealmCommunity(CommunityId id, QString name)
    {
        this->id = id;
        this->name = name;
    }
};

typedef QMap<RealmConfigurationPropertyId, RealmConfiguration*> RealmConfigurationMap;

class Realm : public QObject
{
    Q_OBJECT

public:
     Realm(qint32 id);
    ~Realm();

    quint32 GetId() { return m_id; }
    QString GetName() { return m_name; }
    QString GetHostAddress() { return m_address; }
    quint32 GetPortNo() { return m_port; }
    QString GetVersion() { return m_version; }
    RealmCommunity GetCommunity() { return m_community; }
    quint32 GetPlayerLimit() { return m_playerLimit; }
    quint32 GetPlayerCount();
    bool IsLock() { return m_locked; }

    void SetName(QString name) { m_name = name; }
    void SetHostAddress(QString address) { m_address = address; }
    void SetPortNo(quint32 port) { m_port = port; }
    void SetVersion(QString version);
    void SetCommunity(RealmCommunity community) { m_community = community; }
    void SetPlayerLimit(quint32 playerLimit) { m_playerLimit = playerLimit; }
    void Lock(bool locked) { m_locked = locked; }
    
    void AddConfiguration(RealmConfiguration *conf);
    void ClearConfiguration();
    RealmConfigurationMap GetConfigurations();
    RealmConfiguration* GetConfigurationById(qint32 id);

    static bool CheckVersion(QString version);

private :
    quint32 m_id;
    QString m_name;
    QString m_address;
    quint32 m_port;
    QString m_version;
    RealmCommunity m_community;
    quint32 m_playerLimit;
    bool m_locked;
    RealmConfigurationMap m_configurations;
};

#endif // REALM_H
