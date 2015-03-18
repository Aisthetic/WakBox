#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <QtCore>

typedef QMap<QString, QString> ConfigMap;

class Configuration
{
public:
    Configuration(QString filename);
    ~Configuration();

    /**
     * @brief GetString returns the value of <name> in string
     * @param name
     * @return
     */
    QString GetString(QString name);

    /**
     * @brief GetString returns the value of <name> in bool
     * @param name
     * @return
     */
    bool GetBool(QString name);

    /**
     * @brief GetInt returns the value of <name> in int
     * @param name
     * @return
     */
    int GetInt(QString name);

    /**
     * @brief GetUShort returns the value of <name> in ushort
     * @param name
     * @return
     */
    ushort GetUShort(QString name);

    /**
     * @brief GetUInt returns the value of <name> in uint
     * @param name
     * @return
     */
    uint GetUInt(QString name);

    /**
     * @brief GetStringList returns the value of <name> in string list, default separator is ";"
     * @param name
     * @param separator
     * @return
     */
    QStringList GetStringList(QString name, QString separator = ";");

    /**
     * @brief GetIntList returns the value of <name> in int list, default separator is ";"
     * @param name
     * @param separator
     * @return
     */
    QList<int> GetIntList(QString name, QString separator = ";");

    /**
     * @brief Load load the file
     * @return
     */
    bool Load();

    /**
     * @brief Reload all you to refreshes different value dynamically
     * @return
     */
    bool Reload() { return Load(); }

private:
    QString GetValue(QString name); //any values ​​are of type string in file

    QString m_filename;
    ConfigMap m_config;
};

#endif
