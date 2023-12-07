// Cryptopp lib
#include "rsa.h"
using CryptoPP::RSA;
using CryptoPP::InvertibleRSAFunction;
using CryptoPP::RSAES_OAEP_SHA256_Encryptor;
using CryptoPP::RSAES_OAEP_SHA256_Decryptor;

#include "sha.h"
using CryptoPP::SHA1;

#include "filters.h"
using CryptoPP::StringSink;
using CryptoPP::StringSource;
using CryptoPP::PK_EncryptorFilter;
using CryptoPP::PK_DecryptorFilter;

#include "hex.h"
using CryptoPP::HexEncoder;
using CryptoPP::HexDecoder;

#include "files.h"
using CryptoPP::FileSink;
using CryptoPP::FileSource;

#include "osrng.h"
using CryptoPP::AutoSeededRandomPool;

#include "SecBlock.h"
using CryptoPP::SecByteBlock;

#include "cryptlib.h"
using CryptoPP::Exception;
using CryptoPP::DecodingResult;

#include "base64.h"
using CryptoPP::Base64Encoder;
using CryptoPP::Base64Decoder;

#include <pem.h>

// standard lib
#include <string>
using std::string;

#include <exception>
using std::exception;

#include <iostream>
using std::cout;
using std::cerr;
using std::endl;

#include <assert.h>

/* Set utf8 support for windows*/
#ifdef _WIN32
#include <io.h>
#include <fcntl.h>
#else
#endif
/* Convert string <--> utf8*/
#include <locale>
// using std::wstring_convert;
#include <codecvt>
using  std::codecvt_utf8;
#ifdef _WIN32
#include <windows.h>
#endif

#ifdef _WIN32
#include <io.h>
#include <fcntl.h>
#endif


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

extern "C" {
    __declspec(dllexport) void Decrypt(const char* filenamedata, const char* filenamecipher, const char* filenamekey, int wherecip, int wherecipherout, int typeprivkey, int typecipher, char* str, int maxLen);
}

void Decrypt(const char* filenamedata, const char* filenamecipher, const char* filenamekey, int wherecip, int wherecipherout, int typeprivkey, int typecipher, char* str, int maxLen) {
#ifdef __linux__
    std::locale::global(std::locale("C.UTF-8"));
#endif

#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif
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
            FileSource fsPrivate(filenamekey, true);
            PEM_Load(fsPrivate, privateKey);
            break;
        }
        }
        FileSource(filenamecipher, true, new StringSink(tmpcipher));
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
            StringSource(recovered, true, new FileSink(filenamedata, recovered.size()));
            break;
        }
        case 2: { //screen
            recovered = recovered.substr(0, maxLen);
            std::copy(recovered.begin(), recovered.end(), str);
            str[maxLen] = 0;
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
            FileSource fsPrivate(filenamekey, true);
            PEM_Load(fsPrivate, privateKey);
            break;
        }
        }
        tmpcipher = filenamecipher;
        for (int i = 0; i < tmpcipher.size() - 1; i++) if (tmpcipher[i] == ':') exit(0);
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
            StringSource(recovered, true, new FileSink(filenamedata, recovered.size()));
            break;
        }
        case 2: { //screen
            recovered = recovered.substr(0, maxLen);
            std::copy(recovered.begin(), recovered.end(), str);
            str[maxLen] = 0;
            break;
        }
        }
        break;
    }
    }
}