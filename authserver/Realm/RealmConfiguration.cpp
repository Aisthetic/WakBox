#include "RealmConfiguration.h"
#include "Realm.h"

//================
//DE/CONSTRUCTOR
//================

RealmConfiguration::RealmConfiguration(RealmConfigurationAvailable *confAvailable, Realm *realm)
{
    *m_confAvailable = *confAvailable;
    m_realm = realm;
}

RealmConfiguration::~RealmConfiguration()
{
    delete m_confAvailable;
    //don't delete realm, realm is deleted by is own manager
}

//==============
//GETTER
//==============

QString RealmConfiguration::GetValue()
{
    return m_value;
}

qint32 RealmConfiguration::GetId()
{
    return m_confAvailable->GetId();
}

//==============
//LOGIC
//==============

void RealmConfiguration::SetValue(QString value)
{
    if (!m_confAvailable->CheckValue(value))
    {
        Log::Write(LOG_TYPE_ERROR, "Realm %s - Try to set invalid value for property %s", m_realm->GetName().toLatin1().data(), m_confAvailable->GetKey().toLatin1().data());
        return;
    }

    m_value = value;
}
