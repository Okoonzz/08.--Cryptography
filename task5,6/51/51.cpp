#include <iostream>
#include <chrono>
#include <string>
#include <cstring>
#include <fstream>
#include <sstream>
using std::string;
using std::cin;
using std::cout;
using std::endl;
#ifdef _WIN32
#include <io.h>
#include <fcntl.h>
#include <windows.h>
#endif

#include <locale>
#include "cryptopp/cryptlib.h"
#include "cryptopp/sha3.h"
#include "cryptopp/sha.h"
#include "cryptopp/shake.h"
#include "cryptopp/hex.h"
#include "cryptopp/files.h"
using CryptoPP::FileSink;

using namespace CryptoPP;
using namespace std;

string readfromfile(char* agv){
    //read file
    ifstream file(agv, ios::binary);
    if(!file) cout << "Error";
    string msg((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    return msg;
}

int main (int argc, char* argv[])
{
    #ifdef linux
        std::locale::global(std::locale("C.UTF-8"));
    #endif
    #ifdef _WIN32
        // Set console code page to UTF-8 on Windows
        SetConsoleOutputCP(CP_UTF8);
        SetConsoleCP(CP_UTF8);
    #endif
    if(argc != 4){
        cout << "<Input from screen (-s) or file (-f)> <Type hash (SHA224, SHA256, SHA384, SHA512, SHA3-224, SHA3-256, SHA3-384, SHA3-512, SHAKE128, SHAKE256)> <data/file>";
        return 1;
    }
    string msg;

     if(string(argv[1]) == "-s"){
        msg = argv[3];
    } else if (string(argv[1]) == "-f"){
        msg = readfromfile(argv[3]);
    } else{
        cout << "Invalid choice.\n";
        exit(0);
    }

    //option hash
    unique_ptr<HashTransformation> hash;
    string tmpagv = argv[2];
    transform(tmpagv.begin(), tmpagv.end(), tmpagv.begin(), ::toupper); 
    if (tmpagv== "SHA224") {
        hash.reset(new SHA224);
    } else if (tmpagv == "SHA256") {
        hash.reset(new SHA256);
    } else if (tmpagv == "SHA384") {
        hash.reset(new SHA384);
    } else if (tmpagv == "SHA512") {
        hash.reset(new SHA512);
    } else if (tmpagv == "SHA3-224") {
        hash.reset(new SHA3_224);
    }else if (tmpagv == "SHA3-256") {
        hash.reset(new SHA3_256);
    }else if (tmpagv == "SHA3-384") {
        hash.reset(new SHA3_384);
    }else if (tmpagv == "SHA3-512") {
        hash.reset(new SHA3_512);
    }else if (tmpagv == "SHAKE128") {
        int lenout;
        cout << "Enter output len: ";
        cin >> lenout;
        cin.ignore();
        hash.reset(new SHAKE128(lenout));
    }else if (tmpagv == "SHAKE256") {
        int lenout;
        cout << "Enter output len: ";
        cin >> lenout;
        cin.ignore();
        hash.reset(new SHAKE256(lenout));
    }else {
        cerr << "Invalid hash type: " << tmpagv << endl;
        return 1;
    }



    cout << "Your mess: " << argv[3] << endl;
    cout << "Name: " << hash->AlgorithmName() << endl;
    cout << "Digest size: " << hash->DigestSize() << endl;
    cout << "Block size: " << hash->BlockSize() << endl;

    string digest;
    string encoded;
    auto start = std::chrono::high_resolution_clock::now();
    hash->Update((const CryptoPP::byte*)msg.data(), msg.size());
    digest.resize(hash->DigestSize());
    hash->Final((CryptoPP::byte*)&digest[0]);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

    std::cout << "Digest: ";
    StringSource(digest, true, new HexEncoder(new StringSink(encoded)));
    std::cout <<encoded <<std::endl;
    cout << "Time for hash: " << duration << " ms" << std::endl;

    return 0; 
}