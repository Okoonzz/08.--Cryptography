#include "encMode.h"
#include "tmnip.h"
#include "display.h"
#include <chrono>

void _displayEnc(string rcp){
    int tmp1;
    string filene = "Cipherfile.txt";
    cout << "> Display:\n"
        << "1. Terminal;\n"
        << "2. File\n";
    cin >> tmp1;
    cin.ignore();
    switch (tmp1){
        case 1: {
            termin(rcp);
            break;
        }
        case 2: {
            fl(rcp, filene);
            break;
        }
        default:
            cout << "=> Invalid input\n";
            exit(0);
    }
}

void _displayDec(string rpl){
    int tmp2;
    string filenef = "Plainfile.txt";
    cout << "> Display:\n"
        << "1. Terminal;\n"
        << "2. File\n";
    cin >> tmp2;
    cin.ignore();
    switch (tmp2) {
        case 1: {
            termindec(rpl);
            break;
        }
        case 2: {
            fldec(rpl, filenef);
            break;
        }
        default:
            cout << "=> Invalid input\n";
            exit(0);
    }
}

void _displaychoose(){
    cout << "> Would you like to encryption or decryption message:\n"
        << "1. key and iv generation;\n"
        << "2. encryption;\n"
        << "3. decryption;\n"
        << "> Please enter your number?\n";
}

string _displayFilename(){
    int case21;
    string filename;
    cout << "> Enter your file \n"
        << "1. file1.txt;\n"
        << "2. file2.txt;\n"
        << "3. file3.txt;\n"
        << "4. file4.txt;\n"
        << "5. file5.txt;\n"
        << "6. file6.txt;\n"
        << "7. Other file;\n";
    cin >> case21;
    cin.ignore();
    switch (case21){
        case 1:{
            filename = "file1.txt";
            break;
    }
        case 2:{
            filename = "file2.txt";
            break;
    }
        case 3:{
            filename = "file3.txt";
            break;
    }
        case 4:{
            filename = "file4.txt";
            break;
    }
        case 5:{
            filename = "file5.txt";
            break;
    }
        case 6:{
            filename = "file6.txt";
            break;
    }
        case 7:{
            cout << "Enter your file: ";
            cin >> filename;
            cin.ignore();
            break;
        }
        default:
            cout << "=> Sorry we only have 6 files!!!\n";
            exit(0);
    }
    return filename;
}

string _Entercipher(){
    string tmpcp;
    cout << "> Enter your ciphertext: ";
    getline(cin, tmpcp);
    return tmpcp;
}

string _Enterfilecp(){
    cout << "> Enter file ciphertext: \n";
    string namef;
    cin >> namef;
    cin.ignore();
    return namef;
}

string _pl(string fn){
    ifstream file(fn);
    if (file.fail()) {
        std::cerr << "Error: File does not exist.\n";
        exit(1); 
    }
    string plaintext((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    file.close();
    return plaintext;
}

int main(int argc, char* argv[])
{
    #ifdef _linux_
    std::locale::global(std::locale("C.UTF-8"));
    #endif
  
    #ifdef _WIN32
    // Set console code page to UTF-8 on Windows
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    #endif
    CryptoPP::byte* key = nullptr;
    CryptoPP::byte* iv = nullptr ;
    string namefile;
    string rescp, respl;
    cout << "> Enter your selection:\n"
        << "1. CBC;\n"
        << "2. ECB;\n"
        << "3. CFB;\n" 
        << "4. OFB;\n"
        << "5. CTR;\n"
        << "6. XTS;\n"
        << "7. CCM;\n"
        << "8. GCM\n";
    int mod;
    cin >> mod;
    cin.ignore();
    switch (mod){
        case 1:{
            int aescipher;
            _displaychoose();
            while (1)
            {
                cin >> aescipher;
                cin.ignore();
                switch (aescipher){
                    case 1:{
                        int case1;
                        cout << "> Enter your selection:\n"
                            << "1. Enter from keyboard;\n"
                            << "2. Auto gen key\n"
                            << "3. File\n";
                        cin >> case1;
                        cin.ignore();
                        switch(case1){
                            case 1:{
                                int tmpm;
                                cout << "Hex or string:\n"
                                    << "1. Hex\n"
                                    << "2. String\n";
                                cin >> tmpm;
                                cin.ignore();
                                switch (tmpm){
                                    case 1:{
                                        key = inputkeyhex();
                                        iv = inputIVhex();
                                        break;
                                    }
                                    case 2:{
                                        key = ipKey();
                                        iv = ipIV();
                                        break;
                                    }
                                    default:
                                        cout << "=> Invalid input\n";
                                        exit(0);
                                }
                                break;
                            }
                            case 2: {
                                key = genKey();
                                iv = genIV();
                                break;
                            }
                            case 3:{
                                cout << "Enter file key:\n";
                                string name; 
                                cin >> name;
                                cin.ignore();
                                key = keyFile(name);
                                cout << "Enter fle iv:\n";
                                string _name;
                                cin >> _name;
                                cin.ignore();
                                iv = IVFile(_name);
                                break;
                            }
                            default:
                                cout << "=> Invalid input\n";
                                exit(0);
                        }
                        cout << "> Choose encrypt(2)\n"
                            << " > Choose decrypt (3)\n";
                        break;
                    }
                    case 2:{
                        if (key == nullptr && iv == nullptr){
                            cout << "=> Please gen key and iv first";
                            exit(0);
                        }
                        int chooseip;
                        cout << "> Input where ??\n"
                            << "1. Keyboard;\n"
                            << "2. File\n";
                        cin >> chooseip;
                        cin.ignore();
                        switch (chooseip) {
                            case 1: {
                                string pl;
                                cout << "Enter your plaintext: ";
                                getline(cin, pl);
                                auto start = std::chrono::high_resolution_clock::now();
                                for (int i = 0; i < 1000; ++i) {
                                    rescp = encIpCBC(key, iv, pl);
                                }
                                auto end = std::chrono::high_resolution_clock::now();
                                auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
                                double averageTime = static_cast<double>(duration) / 1000.0;
                                cout << "Average time for encryption over 1000 rounds ipCBC: " << averageTime << " ms" << std::endl;
                                string encoded;
                                StringSource(rescp, true, new Base64Encoder(new StringSink(encoded), false));
                                _displayEnc(encoded);
                                break;
                            }
                            case 2: {
                                namefile = _displayFilename();
                                string pl = _pl(namefile);
                                auto start = std::chrono::high_resolution_clock::now();
                                for (int i = 0; i < 1000; ++i) {
                                    rescp = encCBC(key, iv, pl);
                                }
                                auto end = std::chrono::high_resolution_clock::now();
                                auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
                                double averageTime = static_cast<double>(duration) / 1000.0;
                                cout << "Average time for encryption over 1000 rounds fCBC: " << averageTime << " ms" << std::endl;
                                string encoded;
                                    StringSource(rescp, true,new Base64Encoder( new StringSink(encoded), false));
                                _displayEnc(encoded);
                                break;
                            }
                            default:
                                cout << "=> Invalid input\n";
                                exit(0);
                        }
                        cout << "> Next choose decrypt(3)\n";
                        break;
                    }
                    case 3:{
                        if (key == nullptr && iv == nullptr){
                            cout << "=> Please gen key and iv first";
                            exit(0);
                        }
                        int case3;
                        cout << "> Enter your choose\n"
                            << "1. Terminal;\n"
                            << "2. File\n";
                        cin >> case3;
                        cin.ignore();
                        switch (case3) {
                            case 1: {
                                string cip;
                                cip = _Entercipher();
                                string decoded;
                                StringSource(cip, true, new Base64Decoder(new StringSink(decoded)));
                                auto start = std::chrono::high_resolution_clock::now();
                                for (int i = 0; i < 1000; ++i) {
                                    respl = decrIpCBC(key, iv, decoded);
                                }
                                auto end = std::chrono::high_resolution_clock::now();
                                auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
                                double averageTime = static_cast<double>(duration) / 1000.0;
                                cout << "Average time for decryption over 1000 rounds fCBC: " << averageTime << " ms" << std::endl;
                                _displayDec(respl);
                                break;
                            }
                            case 2: {
                                string namefl = _Enterfilecp();
                                string cip = _pl(namefl);
                                string decoded;
                                StringSource(cip, true, new Base64Decoder(new StringSink(decoded)));
                                auto start = std::chrono::high_resolution_clock::now();
                                for (int i = 0; i < 1000; ++i) {
                                    respl = decrCBC(key, iv, decoded);
                                }
                                auto end = std::chrono::high_resolution_clock::now();
                                auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
                                double averageTime = static_cast<double>(duration) / 1000.0;
                                cout << "Average time for decryption over 1000 rounds fCBC: " << averageTime << " ms" << std::endl;
                                _displayDec(respl);
                                break;
                            }
                            default:
                                cout << "=> Invalid input\n";
                                exit(0);
                        }
                        delete[] key;
                        delete[] iv;
                        exit(0);
                    }
                    default:
                        cout << "=> Invalid input\n";
                        exit(0);
                }
            }
            
            break;
        }
        case 2:{
            int aescipher;
            _displaychoose();
            while (1)
            {
                cin >> aescipher;
                cin.ignore();
                switch (aescipher){
                    case 1:{
                        int case1;
                        cout << "> Enter your selection:\n"
                            << "1. Enter from keyboard;\n"
                            << "2. Auto gen key\n"
                            << "3. File\n";
                        cin >> case1;
                        cin.ignore();
                        switch(case1){
                            case 1:{
                                int tmpm;
                                cout << "Hex or string:\n"
                                    << "1. Hex\n"
                                    << "2. String\n";
                                cin >> tmpm;
                                cin.ignore();
                                switch (tmpm){
                                    case 1:{
                                        key = inputkeyhex();
                                        iv = inputIVhex();
                                        break;
                                    }
                                    case 2:{
                                        key = ipKey();
                                        iv = ipIV();
                                        break;
                                    }
                                    default:
                                        cout << "=> Invalid input\n";
                                        exit(0);
                                }
                                break;
                            }
                            case 2: {
                                key = genKey();
                                iv = genIV();
                                break;
                            }
                            case 3:{
                                cout << "Enter file key:\n";
                                string name; 
                                cin >> name;
                                cin.ignore();
                                key = keyFile(name);
                                break;
                            }
                            default:
                                cout << "=> Invalid input\n";
                                exit(0);
                        }
                        cout << "> Choose encrypt(2)\n"
                            << " > Choose decrypt (3)\n";
                        break;
                    }
                    case 2:{
                        if (key == nullptr && iv == nullptr){
                            cout << "=> Please gen key and iv first";
                            exit(0);
                        }
                        int chooseip;
                        cout << "> Input where ??\n"
                            << "1. Keyboard;\n"
                            << "2. File\n";
                        cin >> chooseip;
                        cin.ignore();
                        switch (chooseip) {
                            case 1: {
                                string pl;
                                cout << "Enter your plaintext: ";
                                getline(cin, pl);
                                auto start = std::chrono::high_resolution_clock::now();
                                for (int i = 0; i < 1000; ++i) {
                                    rescp = encIpECB(key, pl);
                                }
                                auto end = std::chrono::high_resolution_clock::now();
                                auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
                                double averageTime = static_cast<double>(duration) / 1000.0;
                                cout << "Average time for encryption over 1000 rounds ipECB: " << averageTime << " ms" << std::endl;
                                string encoded;
                                StringSource(rescp, true, new Base64Encoder(new StringSink(encoded), false));
                                _displayEnc(encoded);
                                break;
                            }
                            case 2: {
                                namefile = _displayFilename();
                                string pl = _pl(namefile);
                                auto start = std::chrono::high_resolution_clock::now();
                                for (int i = 0; i < 1000; ++i) {
                                    rescp = encECB(key, pl);
                                }
                                auto end = std::chrono::high_resolution_clock::now();
                                auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
                                double averageTime = static_cast<double>(duration) / 1000.0;
                                cout << "Average time for encryption over 1000 rounds fECB: " << averageTime << " ms" << std::endl;
                                string encoded;
                                StringSource(rescp, true,new Base64Encoder(new StringSink(encoded), false));
                                _displayEnc(encoded);
                                break;
                            }
                            default:
                                cout << "=> Invalid input\n";
                                exit(0);
                        }
                        cout << "> Next choose decrypt(3)\n";
                        break;
                    }
                    case 3:{
                        if (key == nullptr && iv == nullptr){
                            cout << "=> Please gen key and iv first";
                            exit(0);
                        }
                        int case3;
                        cout << "> Enter your choose\n"
                            << "1. Terminal;\n"
                            << "2. File\n";
                        cin >> case3;
                        cin.ignore();
                        switch (case3) {
                            case 1: {
                                string cip;
                                cip = _Entercipher();
                                string decoded;
                                StringSource(cip, true, new Base64Decoder(new StringSink(decoded)));
                                auto start = std::chrono::high_resolution_clock::now();
                                for (int i = 0; i < 1000; ++i) {
                                    respl = decrIpECB(key, decoded);
                                }
                                auto end = std::chrono::high_resolution_clock::now();
                                auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
                                double averageTime = static_cast<double>(duration) / 1000.0;
                                cout << "Average time for decryption over 1000 rounds fECB: " << averageTime << " ms" << std::endl;
                                _displayDec(respl);
                                break;
                            }
                            case 2: {
                                string namefl = _Enterfilecp();
                                string cip = _pl(namefl);
                                string decoded;
                                StringSource(cip, true, new Base64Decoder(new StringSink(decoded)));
                                auto start = std::chrono::high_resolution_clock::now();
                                for (int i = 0; i < 1000; ++i) {
                                    respl = decrECB(key, decoded);
                                }
                                auto end = std::chrono::high_resolution_clock::now();
                                auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
                                double averageTime = static_cast<double>(duration) / 1000.0;
                                cout << "Average time for decryption over 1000 rounds fECB: " << averageTime << " ms" << std::endl;
                                _displayDec(respl);
                                break;
                            }
                            default:
                                cout << "=> Invalid input\n";
                                exit(0);
                        }
                        delete[] key;
                        delete[] iv;
                        exit(0);
                    }
                    default:
                        cout << "=> Invalid input\n";
                        exit(0);
                }
            }
            
            break;
        }
        case 3:{
            int aescipher;
            _displaychoose();
            while (1)
            {
                cin >> aescipher;
                cin.ignore();
                switch (aescipher){
                    case 1:{
                        int case1;
                        cout << "> Enter your selection:\n"
                            << "1. Enter from keyboard;\n"
                            << "2. Auto gen key\n"
                            << "3. File\n";
                        cin >> case1;
                        cin.ignore();
                        switch(case1){
                            case 1:{
                                int tmpm;
                                cout << "Hex or string:\n"
                                    << "1. Hex\n"
                                    << "2. String\n";
                                cin >> tmpm;
                                cin.ignore();
                                switch (tmpm){
                                    case 1:{
                                        key = inputkeyhex();
                                        iv = inputIVhex();
                                        break;
                                    }
                                    case 2:{
                                        key = ipKey();
                                        iv = ipIV();
                                        break;
                                    }
                                    default:
                                        cout << "=> Invalid input\n";
                                        exit(0);
                                }
                                break;
                            }
                            case 2: {
                                key = genKey();
                                iv = genIV();
                                break;
                            }
                            case 3:{
                                cout << "Enter file key:\n";
                                string name; 
                                cin >> name;
                                cin.ignore();
                                key = keyFile(name);
                                cout << "Enter fle iv:\n";
                                string _name;
                                cin >> _name;
                                cin.ignore();
                                iv = IVFile(_name);
                                break;
                            }
                            default:
                                cout << "=> Invalid input\n";
                                exit(0);
                        }
                        cout << "> Choose encrypt(2)\n"
                            << " > Choose decrypt (3)\n";
                        break;
                    }
                    case 2:{
                        if (key == nullptr && iv == nullptr){
                            cout << "=> Please gen key and iv first";
                            exit(0);
                        }
                        int chooseip;
                        cout << "> Input where ??\n"
                            << "1. Keyboard;\n"
                            << "2. File\n";
                        cin >> chooseip;
                        cin.ignore();
                        switch (chooseip) {
                            case 1: {
                                string pl;
                                cout << "Enter your plaintext: ";
                                getline(cin, pl);
                                auto start = std::chrono::high_resolution_clock::now();
                                for (int i = 0; i < 1000; ++i) {
                                    rescp = encIpCFB(key, iv, pl);
                                }
                                auto end = std::chrono::high_resolution_clock::now();
                                auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
                                double averageTime = static_cast<double>(duration) / 1000.0;
                                cout << "Average time for encryption over 1000 rounds ipCFB: " << averageTime << " ms" << std::endl;
                                string encoded;
                                StringSource(rescp, true, new Base64Encoder(new StringSink(encoded), false));
                                _displayEnc(encoded);
                                break;
                            }
                            case 2: {
                                namefile = _displayFilename();
                                string pl = _pl(namefile);
                                auto start = std::chrono::high_resolution_clock::now();
                                for (int i = 0; i < 1000; ++i) {
                                    rescp = encCFB(key, iv, pl);
                                }
                                auto end = std::chrono::high_resolution_clock::now();
                                auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
                                double averageTime = static_cast<double>(duration) / 1000.0;
                                cout << "Average time for encryption over 1000 rounds fCFB: " << averageTime << " ms" << std::endl;
                                string encoded;
                                StringSource(rescp, true, new Base64Encoder(new StringSink(encoded), false));
                                _displayEnc(encoded);
                                break;
                            }
                            default:
                                cout << "=> Invalid input\n";
                                exit(0);
                        }
                        cout << "> Next choose decrypt(3)\n";
                        break;
                    }
                    case 3:{
                        if (key == nullptr && iv == nullptr){
                            cout << "=> Please gen key and iv first";
                            exit(0);
                        }
                        int case3;
                        cout << "> Enter your choose\n"
                            << "1. Terminal;\n"
                            << "2. File\n";
                        cin >> case3;
                        cin.ignore();
                        switch (case3) {
                            case 1: {
                                string cip;
                                cip = _Entercipher();
                                string decoded;
                                StringSource(cip, true, new Base64Decoder(new StringSink(decoded)));
                                auto start = std::chrono::high_resolution_clock::now();
                                for (int i = 0; i < 1000; ++i) {
                                    respl = decrIpCFB(key, iv, decoded);
                                }
                                auto end = std::chrono::high_resolution_clock::now();
                                auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
                                double averageTime = static_cast<double>(duration) / 1000.0;
                                cout << "Average time for decryption over 1000 rounds fCFB: " << averageTime << " ms" << std::endl;
                                _displayDec(respl);
                                break;
                            }
                            case 2: {
                                string namefl = _Enterfilecp();
                                string cip = _pl(namefl);
                                string decoded;
                                StringSource(cip, true, new Base64Decoder(new StringSink(decoded)));
                                auto start = std::chrono::high_resolution_clock::now();
                                for (int i = 0; i < 1000; ++i) {
                                    respl = decrCFB(key, iv,decoded);
                                }
                                auto end = std::chrono::high_resolution_clock::now();
                                auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
                                double averageTime = static_cast<double>(duration) / 1000.0;
                                cout << "Average time for decryption over 1000 rounds fCFB: " << averageTime << " ms" << std::endl;
                                _displayDec(respl);
                                break;
                            }
                            default:
                                cout << "=> Invalid input\n";
                                exit(0);
                        }
                        delete[] key;
                        delete[] iv;
                        exit(0);
                    }
                    default:
                        cout << "=> Invalid input\n";
                        exit(0);
                }
            }
            break;
        }
        case 4:{
            int aescipher;
            _displaychoose();
            while (1)
            {
                cin >> aescipher;
                cin.ignore();
                switch (aescipher){
                    case 1:{
                        int case1;
                        cout << "> Enter your selection:\n"
                            << "1. Enter from keyboard;\n"
                            << "2. Auto gen key\n"
                            << "3. File\n";
                        cin >> case1;
                        cin.ignore();
                        switch(case1){
                            case 1:{
                                int tmpm;
                                cout << "Hex or string:\n"
                                    << "1. Hex\n"
                                    << "2. String\n";
                                cin >> tmpm;
                                cin.ignore();
                                switch (tmpm){
                                    case 1:{
                                        key = inputkeyhex();
                                        iv = inputIVhex();
                                        break;
                                    }
                                    case 2:{
                                        key = ipKey();
                                        iv = ipIV();
                                        break;
                                    }
                                    default:
                                        cout << "=> Invalid input\n";
                                        exit(0);
                                }
                                break;
                            }
                            case 2: {
                                key = genKey();
                                iv = genIV();
                                break;
                            }
                            case 3:{
                                cout << "Enter file key:\n";
                                string name; 
                                cin >> name;
                                cin.ignore();
                                key = keyFile(name);
                                cout << "Enter fle iv:\n";
                                string _name;
                                cin >> _name;
                                cin.ignore();
                                iv = IVFile(_name);
                                break;
                            }
                            default:
                                cout << "=> Invalid input\n";
                                exit(0);
                        }
                        cout << "> Choose encrypt(2)\n"
                            << " > Choose decrypt (3)\n";
                        break;
                    }
                    case 2:{
                        if (key == nullptr && iv == nullptr){
                            cout << "=> Please gen key and iv first";
                            exit(0);
                        }
                        int chooseip;
                        cout << "> Input where ??\n"
                            << "1. Keyboard;\n"
                            << "2. File\n";
                        cin >> chooseip;
                        cin.ignore();
                        switch (chooseip) {
                            case 1: {
                                string pl;
                                cout << "Enter your plaintext: ";
                                getline(cin, pl);
                                auto start = std::chrono::high_resolution_clock::now();
                                for (int i = 0; i < 1000; ++i) {
                                    rescp = encIpOFB(key, iv, pl);
                                }
                                auto end = std::chrono::high_resolution_clock::now();
                                auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
                                double averageTime = static_cast<double>(duration) / 1000.0;
                                cout << "Average time for encryption over 1000 rounds ipOFB: " << averageTime << " ms" << std::endl;
                                string encoded;
                                StringSource(rescp, true, new Base64Encoder(new StringSink(encoded), false));
                                _displayEnc(encoded);
                                break;
                            }
                            case 2: {
                                namefile = _displayFilename();
                                string pl = _pl(namefile);
                                auto start = std::chrono::high_resolution_clock::now();
                                for (int i = 0; i < 1000; ++i) {
                                    rescp = encOFB(key, iv, pl);
                                }
                                auto end = std::chrono::high_resolution_clock::now();
                                auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
                                double averageTime = static_cast<double>(duration) / 1000.0;
                                cout << "Average time for encryption over 1000 rounds fOFB: " << averageTime << " ms" << std::endl;
                                string encoded;
                                StringSource(rescp, true, new Base64Encoder(new StringSink(encoded), false));
                                _displayEnc(encoded);
                                break;
                            }
                            default:
                                cout << "=> Invalid input\n";
                                exit(0);
                        }
                        cout << "> Next choose decrypt(3)\n";
                        break;
                    }
                    case 3:{
                        if (key == nullptr && iv == nullptr){
                            cout << "=> Please gen key and iv first";
                            exit(0);
                        }
                        int case3;
                        cout << "> Enter your choose\n"
                            << "1. Terminal;\n"
                            << "2. File\n";
                        cin >> case3;
                        cin.ignore();
                        switch (case3) {
                            case 1: {
                                string cip;
                                cip = _Entercipher();
                                string decoded;
                                StringSource(cip, true, new Base64Decoder(new StringSink(decoded)));
                                auto start = std::chrono::high_resolution_clock::now();
                                for (int i = 0; i < 1000; ++i) {
                                    respl = decrIpOFB(key, iv, decoded);
                                }
                                auto end = std::chrono::high_resolution_clock::now();
                                auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
                                double averageTime = static_cast<double>(duration) / 1000.0;
                                cout << "Average time for decryption over 1000 rounds fOFB: " << averageTime << " ms" << std::endl;
                                _displayDec(respl);
                                break;
                            }
                            case 2: {
                                string namefl = _Enterfilecp();
                                string cip = _pl(namefl);
                                string decoded;
                                StringSource(cip, true, new Base64Decoder(new StringSink(decoded)));
                                auto start = std::chrono::high_resolution_clock::now();
                                for (int i = 0; i < 1000; ++i) {
                                    respl = decrOFB(key, iv, decoded);
                                }
                                auto end = std::chrono::high_resolution_clock::now();
                                auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
                                double averageTime = static_cast<double>(duration) / 1000.0;
                                cout << "Average time for decryption over 1000 rounds fOFB: " << averageTime << " ms" << std::endl;
                                _displayDec(respl);
                                break;
                            }
                            default:
                                cout << "=> Invalid input\n";
                                exit(0);
                        }
                        delete[] key;
                        delete[] iv;
                        exit(0);
                    }
                    default:
                        cout << "=> Invalid input\n";
                        exit(0);
                }
            }
            break;
        }
        case 5:{
            int aescipher;
            _displaychoose();
            while (1)
            {
                cin >> aescipher;
                cin.ignore();
                switch (aescipher){
                    case 1:{
                        int case1;
                        cout << "> Enter your selection:\n"
                            << "1. Enter from keyboard;\n"
                            << "2. Auto gen key\n"
                            << "3. File\n";
                        cin >> case1;
                        cin.ignore();
                        switch(case1){
                            case 1:{
                                int tmpm;
                                cout << "Hex or string:\n"
                                    << "1. Hex\n"
                                    << "2. String\n";
                                cin >> tmpm;
                                cin.ignore();
                                switch (tmpm){
                                    case 1:{
                                        key = inputkeyhex();
                                        iv = inputIVhex();
                                        break;
                                    }
                                    case 2:{
                                        key = ipKey();
                                        iv = ipIV();
                                        break;
                                    }
                                    default:
                                        cout << "=> Invalid input\n";
                                        exit(0);
                                }
                                break;
                            }
                            case 2: {
                                key = genKey();
                                iv = genIV();
                                break;
                            }
                            case 3:{
                                cout << "Enter file key:\n";
                                string name; 
                                cin >> name;
                                cin.ignore();
                                key = keyFile(name);
                                cout << "Enter fle iv:\n";
                                string _name;
                                cin >> _name;
                                cin.ignore();
                                iv = IVFile(_name);
                                break;
                            }
                            default:
                                cout << "=> Invalid input\n";
                                exit(0);
                        }
                        cout << "> Choose encrypt(2)\n"
                            << " > Choose decrypt (3)\n";
                        break;
                    }
                    case 2:{
                        if (key == nullptr && iv == nullptr){
                            cout << "=> Please gen key and iv first";
                            exit(0);
                        }
                        int chooseip;
                        cout << "> Input where ??\n"
                            << "1. Keyboard;\n"
                            << "2. File\n";
                        cin >> chooseip;
                        cin.ignore();
                        switch (chooseip) {
                            case 1: {
                                string pl;
                                cout << "Enter your plaintext: ";
                                getline(cin, pl);
                                auto start = std::chrono::high_resolution_clock::now();
                                for (int i = 0; i < 1000; ++i) {
                                    rescp = encIpCTR(key, iv, pl);
                                }
                                auto end = std::chrono::high_resolution_clock::now();
                                auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
                                double averageTime = static_cast<double>(duration) / 1000.0;
                                cout << "Average time for encryption over 1000 rounds ipCTR: " << averageTime << " ms" << std::endl;
                                string encoded;
                                StringSource(rescp, true, new Base64Encoder(new StringSink(encoded), false));
                                _displayEnc(encoded);
                                break;
                            }
                            case 2: {
                                namefile = _displayFilename();
                                string pl = _pl(namefile);
                                auto start = std::chrono::high_resolution_clock::now();
                                for (int i = 0; i < 1000; ++i) {
                                    rescp = encCTR(key, iv, pl);
                                }
                                auto end = std::chrono::high_resolution_clock::now();
                                auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
                                double averageTime = static_cast<double>(duration) / 1000.0;
                                cout << "Average time for encryption over 1000 rounds fCTR: " << averageTime << " ms" << std::endl;
                                string encoded;
                                StringSource(rescp, true, new Base64Encoder(new StringSink(encoded), false));
                                _displayEnc(encoded);
                                break;
                            }
                            default:
                                cout << "=> Invalid input\n";
                                exit(0);
                        }
                        cout << "> Next choose decrypt(3)\n";
                        break;
                    }
                    case 3:{
                        if (key == nullptr && iv == nullptr){
                            cout << "=> Please gen key and iv first";
                            exit(0);
                        }
                        int case3;
                        cout << "> Enter your choose\n"
                            << "1. Terminal;\n"
                            << "2. File\n";
                        cin >> case3;
                        cin.ignore();
                        switch (case3) {
                            case 1: {
                                string cip;
                                cip = _Entercipher();
                                string decoded;
                                StringSource(cip, true, new Base64Decoder(new StringSink(decoded)));
                                auto start = std::chrono::high_resolution_clock::now();
                                for (int i = 0; i < 1000; ++i) {
                                    respl = decrIpCTR(key, iv, decoded);
                                }
                                auto end = std::chrono::high_resolution_clock::now();
                                auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
                                double averageTime = static_cast<double>(duration) / 1000.0;
                                cout << "Average time for decryption over 1000 rounds fCTR: " << averageTime << " ms" << std::endl;
                                _displayDec(respl);
                                break;
                            }
                            case 2: {
                                string namefl = _Enterfilecp();
                                string cip = _pl(namefl);
                                string decoded;
                                StringSource(cip, true, new Base64Decoder(new StringSink(decoded)));
                                auto start = std::chrono::high_resolution_clock::now();
                                for (int i = 0; i < 1000; ++i) {
                                    respl = decrCTR(key, iv, decoded);
                                }
                                auto end = std::chrono::high_resolution_clock::now();
                                auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
                                double averageTime = static_cast<double>(duration) / 1000.0;
                                cout << "Average time for decryption over 1000 rounds fCTR: " << averageTime << " ms" << std::endl;
                                _displayDec(respl);
                                break;
                            }
                            default:
                                cout << "=> Invalid input\n";
                                exit(0);
                        }
                        delete[] key;
                        delete[] iv;
                        exit(0);
                    }
                    default:
                        cout << "=> Invalid input\n";
                        exit(0);
                }
            }
            break;
        }
        case 6:{
            int aescipher;
            _displaychoose();
            while (1)
            {
                cin >> aescipher;
                cin.ignore();
                switch (aescipher){
                    case 1:{
                        int case1;
                        cout << "> Enter your selection:\n"
                            << "1. Enter from keyboard;\n"
                            << "2. Auto gen key\n"
                            << "3. File\n";
                        cin >> case1;
                        cin.ignore();
                        switch(case1){
                            case 1:{
                                int tmpm;
                                cout << "Hex or string:\n"
                                    << "1. Hex\n"
                                    << "2. String\n";
                                cin >> tmpm;
                                cin.ignore();
                                switch (tmpm){
                                    case 1:{
                                        key = inputkeyhex();
                                        iv = inputIVhex();
                                        break;
                                    }
                                    case 2:{
                                        key = ipKey();
                                        iv = ipIV();
                                        break;
                                    }
                                    default:
                                        cout << "=> Invalid input\n";
                                        exit(0);
                                }
                                break;
                            }
                            case 2: {
                                key = genKey();
                                iv = genIV();
                                break;
                            }
                            case 3:{
                                cout << "Enter file key:\n";
                                string name; 
                                cin >> name;
                                cin.ignore();
                                key = keyFile(name);
                                cout << "Enter fle iv:\n";
                                string _name;
                                cin >> _name;
                                cin.ignore();
                                iv = IVFile(_name);
                                break;
                            }
                            default:
                                cout << "=> Invalid input\n";
                                exit(0);
                        }
                        cout << "> Choose encrypt(2)\n"
                            << " > Choose decrypt (3)\n";
                        break;
                    }
                    case 2:{
                        if (key == nullptr && iv == nullptr){
                            cout << "=> Please gen key and iv first";
                            exit(0);
                        }
                        int chooseip;
                        cout << "> Input where ??\n"
                            << "1. Keyboard;\n"
                            << "2. File\n";
                        cin >> chooseip;
                        cin.ignore();
                        switch (chooseip) {
                            case 1: {
                                string pl;
                                cout << "Enter your plaintext: ";
                                getline(cin, pl);
                                auto start = std::chrono::high_resolution_clock::now();
                                for (int i = 0; i < 1000; ++i) {
                                    rescp = encIpXTS(key, iv, pl);
                                }
                                auto end = std::chrono::high_resolution_clock::now();
                                auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
                                double averageTime = static_cast<double>(duration) / 1000.0;
                                cout << "Average time for encryption over 1000 rounds ipXTS: " << averageTime << " ms" << std::endl;
                                string encoded;
                                StringSource(rescp, true, new Base64Encoder(new StringSink(encoded), false));
                                _displayEnc(encoded);
                                break;
                            }
                            case 2: {
                                namefile = _displayFilename();
                                string pl = _pl(namefile);
                                auto start = std::chrono::high_resolution_clock::now();
                                for (int i = 0; i < 1000; ++i) {
                                    rescp = encXTS(key, iv, pl);
                                }
                                auto end = std::chrono::high_resolution_clock::now();
                                auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
                                double averageTime = static_cast<double>(duration) / 1000.0;
                                cout << "Average time for encryption over 1000 rounds fXTS: " << averageTime << " ms" << std::endl;
                                string encoded;
                                StringSource(rescp, true, new Base64Encoder(new StringSink(encoded), false));
                                _displayEnc(encoded);
                                break;
                            }
                            default:
                                cout << "=> Invalid input\n";
                                exit(0);
                        }
                        cout << "> Next choose decrypt(3)\n";
                        break;
                    }
                    case 3:{
                        if (key == nullptr && iv == nullptr){
                            cout << "=> Please gen key and iv first";
                            exit(0);
                        }
                        int case3;
                        cout << "> Enter your choose\n"
                            << "1. Terminal;\n"
                            << "2. File\n";
                        cin >> case3;
                        cin.ignore();
                        switch (case3) {
                            case 1: {
                                string cip;
                                cip = _Entercipher();
                                string decoded;
                                StringSource(cip, true, new Base64Decoder(new StringSink(decoded)));
                                auto start = std::chrono::high_resolution_clock::now();
                                for (int i = 0; i < 1000; ++i) {
                                    respl = decrIpXTS(key, iv, decoded);
                                }
                                auto end = std::chrono::high_resolution_clock::now();
                                auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
                                double averageTime = static_cast<double>(duration) / 1000.0;
                                cout << "Average time for decryption over 1000 rounds fXTS: " << averageTime << " ms" << std::endl;
                                _displayDec(respl);
                                break;
                            }
                            case 2: {
                                string namefl = _Enterfilecp();
                                string cip = _pl(namefl);
                                string decoded;
                                StringSource(cip, true, new Base64Decoder(new StringSink(decoded)));
                                auto start = std::chrono::high_resolution_clock::now();
                                for (int i = 0; i < 1000; ++i) {
                                    respl = decrXTS(key, iv, decoded);
                                }
                                auto end = std::chrono::high_resolution_clock::now();
                                auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
                                double averageTime = static_cast<double>(duration) / 1000.0;
                                cout << "Average time for decryption over 1000 rounds fXTS: " << averageTime << " ms" << std::endl;
                                _displayDec(respl);
                                break;
                            }
                            default:
                                cout << "=> Invalid input\n";
                                exit(0);
                        }
                        delete[] key;
                        delete[] iv;
                        exit(0);
                    }
                    default:
                        cout << "=> Invalid input\n";
                        exit(0);
                }
            }
            break;
        }
        case 7:{
            int aescipher;
            _displaychoose();
            while (1)
            {
                cin >> aescipher;
                cin.ignore();
                switch (aescipher){
                    case 1:{
                        int case1;
                        cout << "> Enter your selection:\n"
                            << "1. Enter from keyboard;\n"
                            << "2. Auto gen key\n"
                            << "3. File\n";
                        cin >> case1;
                        cin.ignore();
                        switch(case1){
                            case 1:{
                                int tmpm;
                                cout << "Hex or string:\n"
                                    << "1. Hex\n"
                                    << "2. String\n";
                                cin >> tmpm;
                                cin.ignore();
                                switch (tmpm){
                                    case 1:{
                                        key = inputkeyhex();
                                        iv = inputIVhex();
                                        break;
                                    }
                                    case 2:{
                                        key = ipKey();
                                        iv = ipIV();
                                        break;
                                    }
                                    default:
                                        cout << "=> Invalid input\n";
                                        exit(0);
                                }
                                break;
                            }
                            case 2: {
                                key = genKey();
                                iv = genIV();
                                break;
                            }
                            case 3:{
                                cout << "Enter file key:\n";
                                string name; 
                                cin >> name;
                                cin.ignore();
                                key = keyFile(name);
                                cout << "Enter fle iv:\n";
                                string _name;
                                cin >> _name;
                                cin.ignore();
                                iv = IVFile(_name);
                                break;
                            }
                            default:
                                cout << "=> Invalid input\n";
                                exit(0);
                        }
                        cout << "> Choose encrypt(2)\n"
                            << " > Choose decrypt (3)\n";
                        break;
                    }
                    case 2:{
                        if (key == nullptr && iv == nullptr){
                            cout << "=> Please gen key and iv first";
                            exit(0);
                        }
                        int chooseip;
                        cout << "> Input where ??\n"
                            << "1. Keyboard;\n"
                            << "2. File\n";
                        cin >> chooseip;
                        cin.ignore();
                        switch (chooseip) {
                            case 1: {
                                string pl;
                                cout << "Enter your plaintext: ";
                                getline(cin, pl);
                                auto start = std::chrono::high_resolution_clock::now();
                                for (int i = 0; i < 1000; ++i) {
                                    rescp = encIpCCM(key, iv, pl);
                                }
                                auto end = std::chrono::high_resolution_clock::now();
                                auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
                                double averageTime = static_cast<double>(duration) / 1000.0;
                                cout << "Average time for encryption over 1000 rounds ipCCM: " << averageTime << " ms" << std::endl;
                                string encoded;
                                StringSource(rescp, true, new Base64Encoder(new StringSink(encoded), false));
                                _displayEnc(encoded);
                                break;
                            }
                            case 2: {
                                namefile = _displayFilename();
                                string pl = _pl(namefile);
                                auto start = std::chrono::high_resolution_clock::now();
                                for (int i = 0; i < 1000; ++i) {
                                    rescp = encCCM(key, iv, pl);
                                }
                                auto end = std::chrono::high_resolution_clock::now();
                                auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
                                double averageTime = static_cast<double>(duration) / 1000.0;
                                cout << "Average time for encryption over 1000 rounds fCCM: " << averageTime << " ms" << std::endl;
                                string encoded;
                                    StringSource(rescp, true, new Base64Encoder(new StringSink(encoded), false));
                                _displayEnc(encoded);
                                break;
                            }
                            default:
                                cout << "=> Invalid input\n";
                                exit(0);
                        }
                        cout << "> Next choose decrypt(3)\n";
                        break;
                    }
                    case 3:{
                        if (key == nullptr && iv == nullptr){
                            cout << "=> Please gen key and iv first";
                            exit(0);
                        }
                        int case3;
                        cout << "> Enter your choose\n"
                            << "1. Terminal;\n"
                            << "2. File\n";
                        cin >> case3;
                        cin.ignore();
                        switch (case3) {
                            case 1: {
                                string cip;
                                cip = _Entercipher();
                                string decoded;
                                StringSource(cip, true, new Base64Decoder(new StringSink(decoded)));
                                auto start = std::chrono::high_resolution_clock::now();
                                for (int i = 0; i < 1000; ++i) {
                                    respl = decrIpCCM(key, iv, decoded);
                                }
                                auto end = std::chrono::high_resolution_clock::now();
                                auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
                                double averageTime = static_cast<double>(duration) / 1000.0;
                                cout << "Average time for decryption over 1000 rounds fCCM: " << averageTime << " ms" << std::endl;
                                _displayDec(respl);
                                break;
                            }
                            case 2: {
                                string namefl = _Enterfilecp();
                                string cip = _pl(namefl);
                                string decoded;
                                StringSource(cip, true, new Base64Decoder(new StringSink(decoded)));
                                auto start = std::chrono::high_resolution_clock::now();
                                for (int i = 0; i < 1000; ++i) {
                                    respl = decrCCM(key, iv, decoded);
                                }
                                auto end = std::chrono::high_resolution_clock::now();
                                auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
                                double averageTime = static_cast<double>(duration) / 1000.0;
                                cout << "Average time for decryption over 1000 rounds fCCM: " << averageTime << " ms" << std::endl;
                                _displayDec(respl);
                                break;
                            }
                            default:
                                cout << "=> Invalid input\n";
                                exit(0);
                        }
                        delete[] key;
                        delete[] iv;
                        exit(0);
                    }
                    default:
                        cout << "=> Invalid input\n";
                        exit(0);
                }
            }
            break;
        }
        case 8:{
            int aescipher;
            _displaychoose();
            while (1)
            {
                cin >> aescipher;
                cin.ignore();
                switch (aescipher){
                    case 1:{
                        int case1;
                        cout << "> Enter your selection:\n"
                            << "1. Enter from keyboard;\n"
                            << "2. Auto gen key\n"
                            << "3. File\n";
                        cin >> case1;
                        cin.ignore();
                        switch(case1){
                            case 1:{
                                int tmpm;
                                cout << "Hex or string:\n"
                                    << "1. Hex\n"
                                    << "2. String\n";
                                cin >> tmpm;
                                cin.ignore();
                                switch (tmpm){
                                    case 1:{
                                        key = inputkeyhex();
                                        iv = inputIVhex();
                                        break;
                                    }
                                    case 2:{
                                        key = ipKey();
                                        iv = ipIV();
                                        break;
                                    }
                                    default:
                                        cout << "=> Invalid input\n";
                                        exit(0);
                                }
                                break;
                            }
                            case 2: {
                                key = genKey();
                                iv = genIV();
                                break;
                            }
                            case 3:{
                                cout << "Enter file key:\n";
                                string name; 
                                cin >> name;
                                cin.ignore();
                                key = keyFile(name);
                                cout << "Enter fle iv:\n";
                                string _name;
                                cin >> _name;
                                cin.ignore();
                                iv = IVFile(_name);
                                break;
                            }
                            default:
                                cout << "=> Invalid input\n";
                                exit(0);
                        }
                        cout << "> Choose encrypt(2)\n"
                            << " > Choose decrypt (3)\n";
                        break;
                    }
                    case 2:{
                        if (key == nullptr && iv == nullptr){
                            cout << "=> Please gen key and iv first";
                            exit(0);
                        }
                        int chooseip;
                        cout << "> Input where ??\n"
                            << "1. Keyboard;\n"
                            << "2. File\n";
                        cin >> chooseip;
                        cin.ignore();
                        switch (chooseip) {
                            case 1: {
                                string pl;
                                cout << "Enter your plaintext: ";
                                getline(cin, pl);
                                auto start = std::chrono::high_resolution_clock::now();
                                for (int i = 0; i < 1000; ++i) {
                                    rescp = encIpGCM(key, iv, pl);
                                }
                                auto end = std::chrono::high_resolution_clock::now();
                                auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
                                double averageTime = static_cast<double>(duration) / 1000.0;
                                cout << "Average time for encryption over 1000 rounds ipGCM: " << averageTime << " ms" << std::endl;
                                string encoded;
                                StringSource(rescp, true, new Base64Encoder(new StringSink(encoded), false));
                                _displayEnc(encoded);

                                break;
                            }
                            case 2: {
                                namefile = _displayFilename();
                                string pl = _pl(namefile);
                                auto start = std::chrono::high_resolution_clock::now();
                                for (int i = 0; i < 1000; ++i) {
                                    rescp = encGCM(key, iv, pl);
                                }
                                auto end = std::chrono::high_resolution_clock::now();
                                auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
                                double averageTime = static_cast<double>(duration) / 1000.0;
                                cout << "Average time for encryption over 1000 rounds fGCM: " << averageTime << " ms" << std::endl;
                                string encoded;
                                StringSource(rescp, true, new Base64Encoder(new StringSink(encoded), false));
                                _displayEnc(encoded);
                                break;
                            }
                            default:
                                cout << "=> Invalid input\n";
                                exit(0);
                        }
                        cout << "> Next choose decrypt(3)\n";
                        break;
                    }
                    case 3:{
                        if (key == nullptr && iv == nullptr){
                            cout << "=> Please gen key and iv first";
                            exit(0);
                        }
                        int case3;
                        cout << "> Enter your choose\n"
                            << "1. Terminal;\n"
                            << "2. File\n";
                        cin >> case3;
                        cin.ignore();
                        switch (case3) {
                            case 1: {
                                string cip;
                                cip = _Entercipher();
                                string decoded;
                                StringSource(cip, true, new Base64Decoder(new StringSink(decoded)));
                                auto start = std::chrono::high_resolution_clock::now();
                                for (int i = 0; i < 1000; ++i) {
                                    respl = decrIpGCM(key, iv, decoded);
                                }
                                auto end = std::chrono::high_resolution_clock::now();
                                auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
                                double averageTime = static_cast<double>(duration) / 1000.0;
                                cout << "Average time for decryption over 1000 rounds fGCM: " << averageTime << " ms" << std::endl;
                                _displayDec(respl);
                                break;
                            }
                            case 2: {
                                string namefl = _Enterfilecp();
                                string cip = _pl(namefl);
                                string decoded;
                                StringSource(cip, true, new Base64Decoder(new StringSink(decoded)));
                                auto start = std::chrono::high_resolution_clock::now();
                                for (int i = 0; i < 1000; ++i) {
                                    respl = decrGCM(key, iv, decoded);
                                }
                                auto end = std::chrono::high_resolution_clock::now();
                                auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
                                double averageTime = static_cast<double>(duration) / 1000.0;
                                cout << "Average time for decryption over 1000 rounds fGCM: " << averageTime << " ms" << std::endl;
                                _displayDec(respl);
                                break;
                            }
                            default:
                                cout << "=> Invalid input\n";
                                exit(0);
                        }
                        delete[] key;
                        delete[] iv;
                        exit(0);
                    }
                    default:
                        cout << "=> Invalid input\n";
                        exit(0);
                }
            }
            break;
        }
        default:
            cout << "=> Invalid input\n";
            exit(0);
    }
    return 0;
}
