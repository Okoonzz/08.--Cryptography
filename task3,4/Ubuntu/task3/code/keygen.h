#ifndef HKEYGEN_H
#define HKEYGEN_H
#include "cryptopp/rsa.h"
using CryptoPP::RSA;
using CryptoPP::InvertibleRSAFunction;

#include "cryptopp/base64.h"
using CryptoPP::Base64Encoder;
#include "cryptopp/filters.h"
using CryptoPP::StringSink;
using CryptoPP::StringSource;

#include "cryptopp/files.h"
using CryptoPP::FileSink;
using CryptoPP::FileSource;

#include "cryptopp/osrng.h"
using CryptoPP::AutoSeededRandomPool;

// work with queue of byte
#include "cryptopp/queue.h"
using CryptoPP::ByteQueue;
using CryptoPP::BufferedTransformation;
#include <string>
using std::string;

#include <exception>
using std::exception;
#include "cryptopp/pem.h"
#include <iostream>
// #include <windows.h>
using std::cin;
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


bool KeyGen(string filePriv, string filePub, int chooseuser)
{
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
        CryptoPP::FileSink public_key(filePub.c_str(), true);
        CryptoPP::PEM_Save(public_key, pubKey);
        CryptoPP::FileSink private_key(filePriv.c_str(), true);
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
#endif