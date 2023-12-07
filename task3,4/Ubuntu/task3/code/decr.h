#ifndef HDECR_H
#define HDECR_H
// Cryptopp lib
#include "cryptopp/rsa.h"
using CryptoPP::RSA;
using CryptoPP::InvertibleRSAFunction;
using CryptoPP::RSAES_OAEP_SHA256_Encryptor;
using CryptoPP::RSAES_OAEP_SHA256_Decryptor;

#include "cryptopp/sha.h"
using CryptoPP::SHA1;

#include "cryptopp/filters.h"
using CryptoPP::StringSink;
using CryptoPP::StringSource;
using CryptoPP::PK_EncryptorFilter;
using CryptoPP::PK_DecryptorFilter;

#include "cryptopp/hex.h"
using CryptoPP::HexEncoder;
using CryptoPP::HexDecoder;

#include "cryptopp/files.h"
using CryptoPP::FileSink;
using CryptoPP::FileSource;

#include "cryptopp/osrng.h"
using CryptoPP::AutoSeededRandomPool;

#include "cryptopp/secblock.h"
using CryptoPP::SecByteBlock;

#include "cryptopp/cryptlib.h"
using CryptoPP::Exception;
using CryptoPP::DecodingResult;

#include "cryptopp/base64.h"
using CryptoPP::Base64Encoder;
using CryptoPP::Base64Decoder;

#include <cryptopp/pem.h>

// standard lib
#include <string>
using std::string;

#include <exception>
using std::exception;

#include <iostream>
using std::cin;
using std::cout;
using std::cerr;
using std::endl;

#include <assert.h>

using namespace std;
using namespace CryptoPP;


void Decode(const string& filename, BufferedTransformation& bt)
{
    FileSource file(filename.c_str(), true);
    file.TransferTo(bt);
    bt.MessageEnd();
}


void DecodePrivateKey(const string& filename, RSA::PrivateKey& key)
{
    ByteQueue queue;
    Decode(filename, queue);
    key.BERDecodePrivateKey(queue, false, queue.MaxRetrievable());
}

void DecodePublicKey(const string& filename, RSA::PublicKey& key)
{
    ByteQueue queue;
    Decode(filename, queue);
    key.BERDecodePublicKey(queue, false, queue.MaxRetrievable());
}

void Decrypt(string filenamedata, string filenamecipher, string filenamekey, int wherecip, int wherecipherout, int typeprivkey, int typecipher) {
    string tmpcipher, cipher, recovered;
    AutoSeededRandomPool rng;
    RSA::PrivateKey privateKey;
    switch (wherecip) {
    case 1: {  //path 
        switch (typeprivkey) {
        case 1: { // BER
            DecodePrivateKey(filenamekey, privateKey);
            break;
        }
        case 2: { //PEM
            FileSource fsPrivate(filenamekey.c_str(), true);
            PEM_Load(fsPrivate, privateKey);
            break;
        }
        }
        FileSource(filenamecipher.c_str(), true, new StringSink(tmpcipher));
        switch (typecipher) {
        case 1: { //Hex
            StringSource(tmpcipher, true, new HexDecoder(new StringSink(cipher)));
            RSAES_OAEP_SHA256_Decryptor d(privateKey);
            StringSource(cipher, true, new PK_DecryptorFilter(rng, d, new StringSink(recovered)));
            break;
        }
        case 2: { //Base64
            StringSource(tmpcipher, true, new Base64Decoder(new StringSink(cipher)));
            RSAES_OAEP_SHA256_Decryptor d(privateKey);
            StringSource(cipher, true, new PK_DecryptorFilter(rng, d, new StringSink(recovered)));
            break;
        }
        }
        switch (wherecipherout) {
        case 1: { //File
            StringSource(recovered, true, new FileSink(filenamedata.c_str(), recovered.size()));
            break;
        }
        case 2: { //screen
            cout << "Your plaintext: " << recovered;
            break;
        }
        }
        break;
    }
    case 2: { //keyboard
        switch (typeprivkey) {
        case 1: { // BER
            DecodePrivateKey(filenamekey, privateKey);
            break;
        }
        case 2: { //PEM
            FileSource fsPrivate(filenamekey.c_str(), true);
            PEM_Load(fsPrivate, privateKey);
            break;
        }
        }
        tmpcipher = filenamecipher;
        switch (typecipher) {
        case 1: { //Hex
            StringSource(tmpcipher, true, new HexDecoder(new StringSink(cipher)));
            RSAES_OAEP_SHA256_Decryptor d(privateKey);
            StringSource(cipher, true, new PK_DecryptorFilter(rng, d, new StringSink(recovered)));
            break;
        }
        case 2: { //Base64
            StringSource(tmpcipher, true, new Base64Decoder(new StringSink(cipher)));
            RSAES_OAEP_SHA256_Decryptor d(privateKey);
            StringSource(cipher, true, new PK_DecryptorFilter(rng, d, new StringSink(recovered)));
            break;
        }
        }
        switch (wherecipherout) {
        case 1: { //File
            StringSource(recovered, true, new FileSink(filenamedata.c_str(), recovered.size()));
            break;
        }
        case 2: { //screen
            cout << "Your Plaintetx: "<< recovered;
            break;
        }
        }
        break;
    }
    }
}
#endif