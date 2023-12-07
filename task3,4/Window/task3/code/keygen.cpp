#include "rsa.h"
using CryptoPP::RSA;
using CryptoPP::InvertibleRSAFunction;

#include "base64.h"
using CryptoPP::Base64Encoder;
#include "filters.h"
using CryptoPP::StringSink;
using CryptoPP::StringSource;

#include "files.h"
using CryptoPP::FileSink;
using CryptoPP::FileSource;

#include "osrng.h"
using CryptoPP::AutoSeededRandomPool;

// work with queue of byte
#include "queue.h"
using CryptoPP::ByteQueue;
using CryptoPP::BufferedTransformation;
#include <string>
using std::string;

#include <exception>
using std::exception;
#include "pem.h"
#include <iostream>
#include <windows.h>
#include <pem.h>
using std::cout;
using std::cerr;
using std::endl;
using namespace std;
// using namespace CryptoPP;
#include <assert.h>

// Def function
void Encode(const string& filename, const BufferedTransformation& bt);
void EncodePublicKey(const string& filename, const RSA::PublicKey& key);
void EncodePrivateKey(const string& filename, const RSA::PrivateKey& key);


extern "C" {
    __declspec(dllexport) bool KeyGen(const char* filePriv, const char* filePub, int chooseuser);
}

bool KeyGen(const char* filePriv, const char* filePub, int chooseuser)
{
#ifdef __linux__
    std::locale::global(std::locale("C.UTF-8"));
#endif
#ifdef _WIN32
    // Set console code page to UTF-8 on Windows
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif
    // define random generator
    AutoSeededRandomPool rng;
    InvertibleRSAFunction parameters;
    parameters.GenerateRandomWithKeySize(rng, 5120);
    RSA::PrivateKey privKey(parameters);
    RSA::PublicKey pubKey(parameters);

    switch (chooseuser)
    {
    case 1:
    {
        EncodePrivateKey(filePriv, privKey);
        EncodePublicKey(filePub, pubKey);
        break;
    }
    case 2:
    {
        CryptoPP::FileSink public_key(filePub, true);
        CryptoPP::PEM_Save(public_key, pubKey);
        CryptoPP::FileSink private_key(filePriv, true);
        CryptoPP::PEM_Save(private_key, privKey);
        break;
    }
    default:
        return false;
    }
    return true;
}

void Encode(const string& filename, const BufferedTransformation& bt)
{
    FileSink file(filename.c_str());
    bt.CopyTo(file);
    file.MessageEnd();
}
// encode publickey into binary format
void EncodePublicKey(const string& filename, const RSA::PublicKey& key)
{
    ByteQueue queue;
    key.DEREncodePublicKey(queue);
    Encode(filename, queue);
}
// encode private key into binary format
void EncodePrivateKey(const string& filename, const RSA::PrivateKey& key)
{
    ByteQueue queue;
    key.DEREncodePrivateKey(queue);
    Encode(filename, queue);
}