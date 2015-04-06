#ifndef REALMCONFIGURATION_H
#define REALMCONFIGURATION_H

#include <QObject>
#include <QHostAddress>
#include "Define.h"
#include "RealmConfigurationAvailable.h"

class Realm;

class RealmConfiguration : public QObject
{
    Q_OBJECT

public:
     RealmConfiguration(RealmConfigurationAvailable* confAvailable, Realm* realm) { m_confAvailable = confAvailable; m_realm = realm; }
    ~RealmConfiguration() {}

     void SetValue(QString value);

     QString GetValue() { return m_value; }
     qint32 GetId() { return m_confAvailable->GetId(); }

private :
    RealmConfigurationAvailable* m_confAvailable;
    Realm* m_realm;
    QString m_value;
};

#endif // REALMCONFIGURATION_H
