#include "m_AES.h"
#include "key_exp.h"
#include <iostream>
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
#include <string>
using std::string;
#include<random>
using std::rand;
// using std::wstring;
#include <cstdlib>
using std::exit;

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



std::string padString(std::string _key)
{
    const std::string charset = "123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char key_[16] = {0};
    while (_key.length() < 16)
    {
        unsigned int randomIndex = rand() % charset.length();
        _key += charset[randomIndex];
    }

    if (_key.length() > 16)
    {
        std::memcpy(key_, _key.data(), 16);
        return std::string(key_);
    }
    else
    {
        return _key;
    }
}

int main()
{
    #ifdef _linux_
    std::locale::global(std::locale("C.UTF-8"));
    #endif
  
    #ifdef _WIN32
    // Set console code page to UTF-8 on Windows
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    #endif
    AES_CBC aescbc;
    while (1)
    {
        int aescipher;
        cout << "Enter your choose\n"
              << "1. Encrypt\n"
              << "2. Decrypt\n";

        cin >> aescipher;
        cin.ignore();
        switch (aescipher)
        {
            case 1:
            {
                string tmp1, tmp2, plaintext, key, iv, cp;
                cout << "Plaintext: ";
                getline(cin, plaintext);

                cout << "Key: ";
                getline(cin, tmp1);
                key = padString(tmp1);
                cout << "Your key: " << key << endl;

                cout << "IV: ";
                getline(cin, tmp2);
                iv = padString(tmp2);
                cout << "Your iv: " << iv << endl;

                std::string ciphertext = aescbc.cbc_encrypt(plaintext, key, iv);
                cout << "Cipher: " << ciphertext << endl;
                break;
            }
            case 2:
            {
                string plaintext, key, iv, cp;
                cout << "Key: ";
                getline(cin, key);
                if (key.length() != 16)
                {
                    cout << "Please enter key len 16";
                    exit(0);
                }

                cout << "IV: ";
                getline(cin, iv);
                if (iv.length() != 16)
                {
                    cout << "Please enter iv len 16";
                    exit(0);
                }

                cout << "Ennter your cipher: ";
                getline(cin, cp);

                std::string plain = aescbc.cbc_decrypt(cp, key, iv);
                cout << "Plaintext: " << plain << endl;
                exit(0);
            }
            default:
                cout << "Invalid input\n";
                exit(0);
        }
    }
    return 0;
}