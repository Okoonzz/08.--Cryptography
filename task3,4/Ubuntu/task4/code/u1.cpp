#include <iostream>
using std::cin;
using std::cout;
#include<string>
#include <chrono>
#include "genkey.h"
#include "sig.h"
#include "verify.h"
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

int main(int argc, char*argv[]){
#ifdef __linux__
    std::locale::global(std::locale("C.UTF-8"));
#endif

#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif
    if (argc != 5) {
        std::cerr << "Usage: " << argv[0] << "<genkey or signature or verify (-g or -s or -v)> <pem or der (-p or -d)> <file> <signature output file>" << std::endl;
        return 1;
    }
    string gensigveri = argv[1];
    string typekey = argv[2];
    char* data = argv[3];
    string outdata = argv[4];
    string namekeypriv, namekeypub;

    int tmptypekey;
    if(typekey == "-p") tmptypekey = 1;
    else if (typekey == "-d") tmptypekey = 2;
    else exit(0);

    if(gensigveri == "-g"){ //genkey
        cout << "Enter name Privatekey: ";
        getline(cin, namekeypriv);
        cout << "Enter name Publickey:  ";
        getline(cin, namekeypub);
        auto start = std::chrono::high_resolution_clock::now();
        genkey(namekeypriv, namekeypub, tmptypekey);
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        cout << "Time for genkey: " << duration << " ms" << std::endl;
    }

    else if (gensigveri == "-s"){//sign
        int choose;
        cout << "Enter your privatekey: ";
        getline(cin, namekeypriv);

        cout << "Data from:\n"
            << "1. File\n"
            << "2. Screen\n";
        cin >> choose;
        cin.ignore();
        switch (choose){
            case 1: { //file
                auto start = std::chrono::high_resolution_clock::now();
                signa(namekeypriv.c_str(), data, nullptr, nullptr, outdata, tmptypekey, 1);
                auto end = std::chrono::high_resolution_clock::now();
                auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
                cout << "Done\n";
                cout << "Time for sig: " << duration << " ms" << std::endl;
                break;
            }
            case 2: { //keyboard
                string tmpdata;
                cout << "Enter your data: ";
                getline(cin, tmpdata);
                auto start = std::chrono::high_resolution_clock::now();
                signa(namekeypriv.c_str(), "", tmpdata.c_str(), data, outdata, tmptypekey, 2);
                auto end = std::chrono::high_resolution_clock::now();
                auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
                cout << "Done\n";
                cout << "Time for sig: " << duration << " ms" << std::endl;
                break;
            }
        }
    } 

    else if(gensigveri == "-v"){ //verify
        cout << "Enter your public key: ";
        getline(cin, namekeypub);
        auto start = std::chrono::high_resolution_clock::now();
        if(verifySignature(namekeypub.c_str(), data, outdata, tmptypekey)){
            auto end = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
            cout << "Nice\n";
            cout << "Time for sig: " << duration << " ms" << std::endl;
        }
        else cout << "No";
    }
    else{
        exit(0);
    }
}