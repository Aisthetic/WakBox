#include "ConfigMgr.h"
#include "Logs/Log.h"
#include "Console/ConsoleAppender.h"

template<> ConfigMgr*  Singleton<ConfigMgr>::m_instance = 0;

ConfigMgr::ConfigMgr()
{
    m_auth = NULL;
    m_world = NULL;
}

ConfigMgr::~ConfigMgr()
{
    if (m_auth) delete m_auth;
    if (m_world) delete m_world;

    m_auth = NULL;
    m_world = NULL;
}

bool ConfigMgr::LoadAuthConfig(QString name)
{
    if (FileExists(name))
    {
        m_auth = new Configuration(name);
        return m_auth->Load();
    }

    return false;
}

bool ConfigMgr::LoadWorldConfig(QString name)
{
    if (FileExists(name))
    {
        m_world = new Configuration(name);    
        return m_world->Load();
    }

    return false;
}

bool ConfigMgr::FileExists(QString name)
{
    QFile file(name);
    bool exists = file.open(QIODevice::ReadOnly);

    if (!exists)
         Log::Write(LOG_TYPE_ERROR, "Cannot open configuration file %s : %s ",
                    name.toLatin1().data(),
                    file.errorString().toLatin1().data());

    file.close();
    return exists;
}
