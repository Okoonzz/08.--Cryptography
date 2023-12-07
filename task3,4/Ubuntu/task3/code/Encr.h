#ifndef HENCR_H
#define HENCR_H
#include "decr.h"
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


void Encrypt(string filenamedata, string filenamecipher, string filenamekey, int wheredata, int wherecipher, int typepubkey, int typecipher){
    string data, cipher, encoded;
    AutoSeededRandomPool rng;
    RSA::PublicKey publicKey;
    switch (wheredata) {
        case 1: {  //path 
            switch (typepubkey) {
                case 1: { // BER
                    DecodePublicKey(filenamekey, publicKey);
                    break;
                }
                case 2: { //PEM
                    FileSource fsPublic(filenamekey.c_str(), true);
                    PEM_Load(fsPublic, publicKey);
                    break;
                }
            }
            FileSource(filenamedata.c_str(), true, new StringSink(data));
            RSAES_OAEP_SHA256_Encryptor e(publicKey);
            StringSource(data, true, new PK_EncryptorFilter(rng, e, new StringSink(cipher)));
            switch (typecipher) {
                case 1: { //Hex
                    StringSource(cipher, true, new HexEncoder(new StringSink(encoded)));
                    break;
                }
                case 2: { //Base64
                    StringSource(cipher, true, new Base64Encoder(new StringSink(encoded), false));
                    break;
                }
            }
            switch (wherecipher) {
                case 1: { //File
                    StringSource(encoded, true, new FileSink(filenamecipher.c_str(), encoded.size()));
                    break;
                }
                case 2: { //screen
                    cout << "Here is your cipher: " << encoded << endl;
                    break;
                }
            }
            break;
        }
        case 2: { //keyboard
            switch (typepubkey) {
                case 1: { // BER
                    DecodePublicKey(filenamekey, publicKey);
                    break;
                }
                case 2: { //PEM
                    FileSource fsPublic(filenamekey.c_str(), true);
                    PEM_Load(fsPublic, publicKey);
                    break;
                }
            }
            data = filenamedata;
            RSAES_OAEP_SHA256_Encryptor e(publicKey);
            StringSource(data, true, new PK_EncryptorFilter(rng, e, new StringSink(cipher)));
            switch (typecipher) {
                case 1: { //Hex
                    StringSource(cipher, true, new HexEncoder(new StringSink(encoded)));
                    break;
                }
                case 2: { //Base64
                    StringSource(cipher, true, new Base64Encoder(new StringSink(encoded), false));
                    break;
                }
            }
            switch (wherecipher) {
                case 1: { //File
                    StringSource(encoded, true, new FileSink(filenamecipher.c_str(), encoded.size()));
                    break;
                }
                case 2: { //screen
                    cout << encoded << endl;
                    break;
                }
            }
            break;
        }
    }
}
#endif