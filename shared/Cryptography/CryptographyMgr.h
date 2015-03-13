#ifndef CRYPTOGRAPHY_H
#define CRYPTOGRAPHY_H

#include <QtCore>
#include <openssl/rsa.h>
#include <openssl/pkcs12.h>
#include <openssl/rand.h>
#include <openssl/crypto.h>
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
    QByteArray m_privateKey;
    QByteArray m_publicKey;
};

#define sCryptographyMgr CryptographyMgr::Instance()

#endif
