#ifndef HSIG_H
#define HSIG_H
#include <openssl/evp.h>
#include <openssl/pem.h>
#include <openssl/ec.h>
#include <openssl/bio.h>
#include <openssl/ec.h>
#include <openssl/sha.h>
#include <fstream>
#include <vector>
#include <iterator>
#include<string>

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

bool signa(const char* pathprivkey, string pathdata, const char* data, char* pathdatakeyb, string signatruepath, int choice, int choicepath) {
    switch (choicepath) {
    case 1: { //file
        BIO* bio = BIO_new(BIO_s_file());
        BIO_read_filename(bio, pathprivkey);
        switch (choice) {
        case 1: { //PEM
            EVP_PKEY* privateKey = PEM_read_bio_PrivateKey(bio, NULL, NULL, NULL);

            if (EVP_PKEY_base_id(privateKey) != EVP_PKEY_EC) {
                return false;
            }

            unsigned char hash[SHA256_DIGEST_LENGTH];
            std::ifstream pdfFile(pathdata.c_str(), std::ios::binary);
            std::vector<unsigned char> pdfContents((std::istreambuf_iterator<char>(pdfFile)), std::istreambuf_iterator<char>());
            pdfFile.close();

            SHA256(&pdfContents[0], pdfContents.size(), hash);

            EVP_MD_CTX* ctx = EVP_MD_CTX_new();
            EVP_DigestSignInit(ctx, NULL, EVP_sha256(), NULL, privateKey);
            size_t sig_len;

            EVP_DigestSign(ctx, NULL, &sig_len, hash, SHA256_DIGEST_LENGTH);

            unsigned char* sig = (unsigned char*)malloc(sig_len);

            EVP_DigestSign(ctx, sig, &sig_len, hash, SHA256_DIGEST_LENGTH);

            std::ofstream signatureFile(signatruepath.c_str(), std::ios::binary);
            signatureFile.write(reinterpret_cast<const char*>(sig), sig_len);
            signatureFile.close();

            EVP_MD_CTX_free(ctx);
            BIO_free(bio);
            free(sig);
            return true;
        }
        case 2: { //BER
            EVP_PKEY* privateKey = d2i_PrivateKey_bio(bio, NULL);
            if (EVP_PKEY_base_id(privateKey) != EVP_PKEY_EC) {
                return false;
            }

            unsigned char hash[SHA256_DIGEST_LENGTH];
            std::ifstream pdfFile(pathdata.c_str(), std::ios::binary);
            std::vector<unsigned char> pdfContents((std::istreambuf_iterator<char>(pdfFile)), std::istreambuf_iterator<char>());
            pdfFile.close();

            SHA256(&pdfContents[0], pdfContents.size(), hash);

            EVP_MD_CTX* ctx = EVP_MD_CTX_new();
            EVP_DigestSignInit(ctx, NULL, EVP_sha256(), NULL, privateKey);
            size_t sig_len;

            EVP_DigestSign(ctx, NULL, &sig_len, hash, SHA256_DIGEST_LENGTH);

            unsigned char* sig = (unsigned char*)malloc(sig_len);

            EVP_DigestSign(ctx, sig, &sig_len, hash, SHA256_DIGEST_LENGTH);

            std::ofstream signatureFile(signatruepath.c_str(), std::ios::binary);
            signatureFile.write(reinterpret_cast<const char*>(sig), sig_len);
            signatureFile.close();

            EVP_MD_CTX_free(ctx);
            BIO_free(bio);
            free(sig);
            return true;
        }
        }
    }
    case 2: {//keyboard
        BIO* bio1 = BIO_new(BIO_s_file());
        BIO_write_filename(bio1, pathdatakeyb);
        BIO_write(bio1, data, strlen(data));
        BIO_free(bio1);

        BIO* bio = BIO_new(BIO_s_file());
        BIO_read_filename(bio, pathprivkey);
        switch (choice) {
        case 1: { //PEM
            EVP_PKEY* privateKey = PEM_read_bio_PrivateKey(bio, NULL, NULL, NULL);

            if (EVP_PKEY_base_id(privateKey) != EVP_PKEY_EC) {
                return false;
            }

            unsigned char hash[SHA256_DIGEST_LENGTH];
            std::ifstream pdfFile(pathdatakeyb, std::ios::binary);
            std::vector<unsigned char> pdfContents((std::istreambuf_iterator<char>(pdfFile)), std::istreambuf_iterator<char>());
            pdfFile.close();

            SHA256(&pdfContents[0], pdfContents.size(), hash);

            EVP_MD_CTX* ctx = EVP_MD_CTX_new();
            EVP_DigestSignInit(ctx, NULL, EVP_sha256(), NULL, privateKey);
            size_t sig_len;

            EVP_DigestSign(ctx, NULL, &sig_len, hash, SHA256_DIGEST_LENGTH);

            unsigned char* sig = (unsigned char*)malloc(sig_len);

            EVP_DigestSign(ctx, sig, &sig_len, hash, SHA256_DIGEST_LENGTH);

            std::ofstream signatureFile(signatruepath.c_str(), std::ios::binary);
            signatureFile.write(reinterpret_cast<const char*>(sig), sig_len);
            signatureFile.close();

            EVP_MD_CTX_free(ctx);
            BIO_free(bio);
            free(sig);
            return true;
        }
        case 2: { //BER
            EVP_PKEY* privateKey = d2i_PrivateKey_bio(bio, NULL);
            if (EVP_PKEY_base_id(privateKey) != EVP_PKEY_EC) {
                return false;
            }

            unsigned char hash[SHA256_DIGEST_LENGTH];
            std::ifstream pdfFile(pathdatakeyb, std::ios::binary);
            std::vector<unsigned char> pdfContents((std::istreambuf_iterator<char>(pdfFile)), std::istreambuf_iterator<char>());
            pdfFile.close();

            SHA256(&pdfContents[0], pdfContents.size(), hash);

            EVP_MD_CTX* ctx = EVP_MD_CTX_new();
            EVP_DigestSignInit(ctx, NULL, EVP_sha256(), NULL, privateKey);
            size_t sig_len;

            EVP_DigestSign(ctx, NULL, &sig_len, hash, SHA256_DIGEST_LENGTH);

            unsigned char* sig = (unsigned char*)malloc(sig_len);

            EVP_DigestSign(ctx, sig, &sig_len, hash, SHA256_DIGEST_LENGTH);

            std::ofstream signatureFile(signatruepath.c_str(), std::ios::binary);
            signatureFile.write(reinterpret_cast<const char*>(sig), sig_len);
            signatureFile.close();

            EVP_MD_CTX_free(ctx);
            BIO_free(bio);
            free(sig);
            return true;
        }
        }
    }
    }
    return false;
}
#endif