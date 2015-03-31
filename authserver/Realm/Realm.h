#ifndef REALM_H
#define REALM_H

#include <QObject>
#include <QHostAddress>

class RealmCommunity
{
private:
    qint32 m_id;
    QString m_name;

    RealmCommunity(qint32 id, QString name)
    {
        m_id = id;
        m_name = name;
    }

 public:
    static RealmCommunity* byId(qint32 id)
    {
        switch(id)
        {
            case 1: return new RealmCommunity(1, "fr");
        }
    }
};

class Realm : public QObject
{
    Q_OBJECT

public:
     explicit Realm(QObject *parent = 0);
    ~Realm();

private :
    qint32 m_id;
    QString m_name;
    QHostAddress m_adress;
    QList<qint16> m_port;
    QString m_version;
    RealmCommunity* m_community;
    qint32 getPlayerCount() { return 0; }
    qint32 m_playerLimit;

    bool locked;
};

#endif // REALM_H
