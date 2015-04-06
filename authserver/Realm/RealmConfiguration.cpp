#include "RealmConfiguration.h"
#include "Realm.h"

void RealmConfiguration::SetValue(QString value)
{
    if(!m_confAvailable->CheckValue(value))
    {
        Log::Write(LOG_TYPE_ERROR, "Realm %s - Try to set invalid value for property %s", m_realm->GetName().toLatin1().data(), m_confAvailable->GetKey().toLatin1().data());
        return;
    }

    m_value = value;
}
