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
     RealmConfiguration(RealmConfigurationAvailable *confAvailable, Realm *realm);
    ~RealmConfiguration();

     void SetValue(QString value);
     QString GetValue();
     qint32 GetId();

private :
    RealmConfigurationAvailable *m_confAvailable;
    Realm *m_realm;
    QString m_value;
};

#endif // REALMCONFIGURATION_H
