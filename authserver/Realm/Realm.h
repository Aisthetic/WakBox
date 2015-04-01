#ifndef REALM_H
#define REALM_H

#include <QObject>
#include <QHostAddress>
#include <QSqlQuery>

#include "Define.h"

struct RealmCommunity
{
    CommunityId id;
    QString name;
};

class Realm : public QObject
{
    Q_OBJECT

public:
     explicit Realm(QObject *parent = 0);
    ~Realm();

    void LoadFromDB(QSqlQuery query);

    quint32 GetId() { return m_id; }
    QString GetName() { return m_name; }
    QHostAddress GetHostAddress() { return m_address; }
    quint32 GetPort() { return m_port; }
    QString GetVersion() { return m_version; }
    RealmCommunity GetCommunity() { return m_community; }
    quint32 GetPlayerCount() { return m_playerCount; }
    quint32 GetPlayerLimit() { return m_playerLimit; }
    bool IsLocked() { return m_locked; }

private :
    quint32 m_id;
    QString m_name;
    QHostAddress m_address;
    quint32 m_port;
    QString m_version;
    RealmCommunity m_community;
    quint32 m_playerCount;
    quint32 m_playerLimit;
    bool m_locked;
};

#endif // REALM_H
