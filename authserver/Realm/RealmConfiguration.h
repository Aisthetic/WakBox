#ifndef REALMCONFIGURATION_H
#define REALMCONFIGURATION_H

#include <QObject>
#include <QHostAddress>
#include "Define.h"
#include "RealmConfigurationAvailable.h"
#include "Realm.h"

class RealmConfiguration : public QObject
{
    Q_OBJECT

public:
     RealmConfiguration(RealmConfigurationAvailable* confAvailable, Realm *realm) { m_confAvailable = confAvailable; m_realm = realm; }
    ~RealmConfiguration() {}

     void SetValue(QString value)
     {
         if(!m_confAvailable->CheckValue(value))
         {
             Log::Write(LOG_TYPE_ERROR, "Realm %s - Try to set invalid value for property %s", m_realm->GetName().toLatin1().data(), m_confAvailable->GetKey().toLatin1().data());
             return;
         }

         m_value = value;
     }

     QString GetValue() { return m_value; }
     qint32 GetId() { return m_confAvailable->GetId(); }

private :
    RealmConfigurationAvailable* m_confAvailable;
    Realm* m_realm;
    QString m_value;
};

#endif // REALMCONFIGURATION_H
