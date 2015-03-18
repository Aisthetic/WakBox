#ifndef CONFIGMGR_H
#define CONFIGMGR_H

#include <QtCore>
#include "Configuration.h"
#include "Utils/Singleton.h"

/**
 * @brief The ConfigMgr class
 */
class ConfigMgr : public Singleton<ConfigMgr>
{
public:
    ConfigMgr();
    ~ConfigMgr();

    /**
     * @brief GetAuthConfig returns the pointer to the auth configuration file
     * @return
     */
    Configuration* GetAuthConfig()
    {
        return m_auth;
    }

    /**
     * @brief GetWorldConfig returns the pointer to the auth configuration file
     * @return
     */
    Configuration* GetWorldConfig()
    {
        return m_world;
    }

    /**
     * @brief LoadAuthConfig loads the file passed as a parameter in the m_auth pointer
     * @param fileName
     * @return
     */
    bool LoadAuthConfig(QString fileName);

    /**
     * @brief LoadAuthConfig loads the file passed as a parameter in the m_world pointer
     * @param fileName
     * @return
     */
    bool LoadWorldConfig(QString fileName);

    /**
     * @brief FileExists check if the filename exist
     * @param name
     * @return
     */
    bool FileExists(QString name);

private:
    Configuration* m_auth;
    Configuration* m_world;
};

#define sConfigMgr ConfigMgr::Instance()
#define sAuthConfig sConfigMgr->GetAuthConfig()
#define sWorldConfig sConfigMgr->GetWorldConfig()

#endif
