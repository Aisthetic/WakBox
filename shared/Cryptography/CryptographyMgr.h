#ifndef CRYPTOGRAPHY_H
#define CRYPTOGRAPHY_H

#include <QtCore>
#include <osrng.h>
#include <hex.h>
#include <randpool.h>
#include <rsa.h>
#include <files.h>
#include "Utils/Singleton.h"

class CryptographyMgr : public Singleton<CryptographyMgr>
{
public:
    CryptographyMgr();
    ~CryptographyMgr();

    bool Initialize();
    bool GenerateKeyPair();
    bool LoadKeyPair();

    QByteArray GetPublicKey() { return m_publicKey; }
    QByteArray Decrypt(QByteArray buffer);

private:
    CryptoPP::InvertibleRSAFunction m_privateKey;
    QByteArray m_publicKey;
};

#define sCryptographyMgr CryptographyMgr::Instance()

#endif
