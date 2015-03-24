#include "Configuration.h"
#include "Logs/Log.h"

Configuration::Configuration(QString filename)
{
    m_filename = filename;
    m_config.clear();
}
Configuration::~Configuration()
{
    m_config.clear();
}

bool Configuration::Load()
{
    m_config.clear();

    QSettings settings(m_filename, QSettings::IniFormat);
    const QStringList keys = settings.allKeys();

    QStringList::const_iterator itr;
    for (itr = keys.constBegin(); itr != keys.constEnd(); ++itr)
        m_config.insert((*itr), settings.value((*itr)).toString());

    Log::Write(LOG_TYPE_NORMAL, "Configuration file %s successfully loaded.", m_filename.toLatin1().data());
    return true;
}

QString Configuration::GetValue(QString name)
{
    ConfigMap::const_iterator i = m_config.find(name);
    if(i != m_config.end())
        return i.value();

    Log::Write(LOG_TYPE_ERROR, "Trying to get config value \"%s\" but the value don't exist.", name.toLatin1().data());
    return QString();
}

QString Configuration::GetString(QString name)
{
    return GetValue(name);
}

bool Configuration::GetBool(QString name)
{
    QString val = GetValue(name);
    return (val.toLower() == "true" || val.toLower() == "yes" || val == "1");
}

int Configuration::GetInt(QString name)
{
    return GetValue(name).toInt();
}

ushort Configuration::GetUShort(QString name)
{
    return GetValue(name).toUShort();
}

uint Configuration::GetUInt(QString name)
{
    return GetValue(name).toUInt();
}

QStringList Configuration::GetStringList(QString name, QString separator)
{
    return GetValue(name).split(separator);
}

QList<int> Configuration::GetIntList(QString name, QString separator)
{
    QStringList stringList = GetStringList(name, separator);
    QList<int> outList;

    for(int i = 0; i < stringList.size(); i++)
    {
        bool convertOk;
        int value = stringList.at(i).toInt(&convertOk);

        if(convertOk)
            outList.push_back(value);
        else
            Log::Write(LOG_TYPE_ERROR, "Trying to convert config value \"%s\" to int but failed.", name.toLatin1().data());
    }

    return outList;
}


