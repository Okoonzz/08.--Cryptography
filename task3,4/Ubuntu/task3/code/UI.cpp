#include "Encr.h"
#include "keygen.h"
#include "decr.h"
#include <chrono>
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

int main(){
#ifdef __linux__
    std::locale::global(std::locale("C.UTF-8"));
#endif

#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif
    int choosefunc;
    int choosekey;
    string filepriv, filepub;
    int choosewheredata, choosetypecipher, chooseoutput, choosetypepub;
    string filenamedata, filenamecipher, filenamekey;
    cout << "Enter Your Selection\n"
        << "1. Gen Key\n"
        << "2. Encr\n"
        << "3. Decr\n";
    cin >> choosefunc;
    cin.ignore();
    switch (choosefunc){
        case 1:{ //Gen
            cout << "Enter your choose key:\n"
                << "1. BER\n"
                << "2. PEM\n";
            cin >> choosekey;
            cin.ignore();
            switch (choosekey){
                case 1:{
                    cout << "Enter your name Privatekey (.ber): ";
                    getline(cin, filepriv);
                    cout << "Enter your Publickey (.ber): ";
                    getline(cin, filepub);
                    break;
                }
                case 2:{
                    cout << "Enter your name Privatekey (.pem): ";
                    getline(cin, filepriv);
                    cout << "Enter your Publickey (.pem): ";
                    getline(cin, filepub);
                    break;           
                }
                default:
                    exit(0);
            }
            auto start = std::chrono::high_resolution_clock::now();
            KeyGen(filepriv, filepub, choosekey);
            auto end = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
            cout << "Time for genkey: " << duration << " ms" << std::endl;
            break;
        }
        case 2: { //Encrypt
            cout << "Choose your type key:\n"
                << "1. BER\n"
                    << "2. PEM\n";
            cin >> choosetypepub;
            cin.ignore();
            cout << "Enter your filename Publickey: ";
            getline(cin, filenamekey);
            cout << "Choose your data:\n"
                << "1. Path\n"
                << "2. Screen\n";
            cin >> choosewheredata;
            cin.ignore();
            cout << "Choose type Cipher:\n"
                <<"1. Hex\n"
                <<"2. Base64\n";
            cin >>choosetypecipher;
            cin.ignore();
            cout << "Choose your cipher out:\n"
                <<"1. Path\n"
                <<"2. Screen\n";
            cin >> chooseoutput;
            cin.ignore();
            switch (choosewheredata){
                case 1:{ //PATH
                    cout << "Enter your filename data: ";
                    getline(cin, filenamedata);
                    switch (chooseoutput){
                        case 1: { //path
                            cout << "Enter your filename cipher: ";
                            getline(cin, filenamecipher);
                            auto start = std::chrono::high_resolution_clock::now();
                            Encrypt(filenamedata, filenamecipher, filenamekey, choosewheredata, chooseoutput, choosetypepub, choosetypecipher);
                            auto end = std::chrono::high_resolution_clock::now();
                            auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
                            cout << "Done\n";
                            cout << "Time for encryption: " << duration << " ms" << std::endl;
                            break;
                        }
                        case 2:{ //screen
                            getline(cin, filenamecipher);
                            auto start = std::chrono::high_resolution_clock::now();
                            Encrypt(filenamedata, filenamecipher, filenamekey, choosewheredata, chooseoutput, choosetypepub, choosetypecipher);
                            auto end = std::chrono::high_resolution_clock::now();
                            auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
                            cout << endl;
                            cout << "Time for encryption: " << duration << " ms" << std::endl;
                            break;
                        }
                    }
                    break;
                }
                case 2:{ //Keyboard
                    cout << "Enter your plaintext: ";
                    getline(cin, filenamedata);
                    switch (chooseoutput){
                        case 1: { //path
                            cout << "Enter your filename cipher: ";
                            getline(cin, filenamecipher);
                            auto start = std::chrono::high_resolution_clock::now();
                            Encrypt(filenamedata, filenamecipher, filenamekey, choosewheredata, chooseoutput, choosetypepub, choosetypecipher);
                            auto end = std::chrono::high_resolution_clock::now();
                            auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
                            cout << "Done\n";
                            cout << "Time for encryption: " << duration << " ms" << std::endl;
                            break;
                        }
                        case 2:{ //screen
                            auto start = std::chrono::high_resolution_clock::now();
                            Encrypt(filenamedata, filenamecipher, filenamekey, choosewheredata, chooseoutput, choosetypepub, choosetypecipher);
                            auto end = std::chrono::high_resolution_clock::now();
                            auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
                            cout << endl;
                            cout << "Time for encryption: " << duration << " ms" << std::endl;
                            break;
                        }
                    }
                    break;
                }
            }
                break;
        }
        case 3: { //Decrypt
            cout << "Choose Your type key:\n"
                << "1. BER\n"
                << "2. PEM\n";
            cin >> choosetypepub;
            cin.ignore();
            cout << "Enter your filename privatekey: ";
            getline(cin, filenamekey);
            cout << "Choose your cipher:\n"
                << "1. Path\n"
                << "2. Screen\n";
            cin >> choosewheredata;
            cin.ignore();
            cout << "Choose type Cipher:\n"
                <<"1. Hex\n"
                <<"2. Base64\n";
            cin >>choosetypecipher;
            cin.ignore();
            cout << "Choose your plaintext out:\n"
                <<"1. Path\n"
                <<"2. Screen\n";
            cin >> chooseoutput;
            cin.ignore();
            switch (choosewheredata){
                case 1:{ //PATH
                    cout << "Enter your filename cipher: ";
                    getline(cin, filenamedata);
                    switch (chooseoutput){
                        case 1: { //path
                            cout << "Enter your filename reover: ";
                            getline(cin, filenamecipher);
                            auto start = std::chrono::high_resolution_clock::now();
                            Decrypt(filenamecipher, filenamedata,filenamekey, choosewheredata, chooseoutput, choosetypepub, choosetypecipher);
                            auto end = std::chrono::high_resolution_clock::now();
                            auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
                            cout << "Done\n";
                            cout << "Time for Decryption: " << duration << " ms" << std::endl;
                            break;
                        }
                        case 2:{ //screen
                            auto start = std::chrono::high_resolution_clock::now();
                            Decrypt(filenamecipher, filenamedata, filenamekey, choosewheredata, chooseoutput, choosetypepub, choosetypecipher);
                            auto end = std::chrono::high_resolution_clock::now();
                            auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
                            cout << endl;
                            cout << "Time for Decryption: " << duration << " ms" << std::endl;
                            break;
                        }
                    }
                    break;
                }
                case 2:{//Keyboard
                    cout << "Enter your ciphertext: ";
                    getline(cin, filenamedata);
                    switch (chooseoutput){
                        case 1: { //path
                            cout << "Enter your filename cipher: ";
                            getline(cin, filenamecipher);
                            auto start = std::chrono::high_resolution_clock::now();
                            Decrypt(filenamecipher, filenamedata, filenamekey, choosewheredata, chooseoutput, choosetypepub, choosetypecipher);
                            auto end = std::chrono::high_resolution_clock::now();
                            auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
                            cout << "Done\n";
                            cout << "Time for Decryption: " << duration << " ms" << std::endl;
                            break;
                        }
                        case 2:{ //screen
                            auto start = std::chrono::high_resolution_clock::now();
                            Decrypt(filenamecipher, filenamedata, filenamekey, choosewheredata, chooseoutput, choosetypepub, choosetypecipher);
                            auto end = std::chrono::high_resolution_clock::now();
                            auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
                            cout << endl;
                            cout << "Time for Decryption: " << duration << " ms" << std::endl;
                            break;
                        }
                    }
                    break;
                }
            }
            break;
        }
    }
}