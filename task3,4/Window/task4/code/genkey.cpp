#include <openssl/evp.h>
#include <openssl/pem.h>
#include <openssl/ec.h>
#include <openssl/bio.h>
#include <windows.h>

extern "C" {
    __declspec(dllexport) bool genkey(const char* filenamepriv, const char* filenamepub, int typekey);
}

bool genkey(const char* filenamepriv, const char* filenamepub, int typekey) {

#ifdef __linux__
    std::locale::global(std::locale("C.UTF-8"));
#endif
#ifdef _WIN32
    // Set console code page to UTF-8 on Windows
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif

    EVP_PKEY* pkey = NULL;
    EVP_PKEY_CTX* pctx = NULL;
    EC_KEY* ec_key = NULL;

    pctx = EVP_PKEY_CTX_new_id(EVP_PKEY_EC, NULL);
    EVP_PKEY_keygen_init(pctx);
    EVP_PKEY_CTX_set_ec_paramgen_curve_nid(pctx, NID_secp384r1);
    EVP_PKEY_keygen(pctx, &pkey);

    switch (typekey) {
    case 1: { //PEM
        //save priv
        BIO* bio = BIO_new_file(filenamepriv, "wb");
        PEM_write_bio_PrivateKey(bio, pkey, NULL, NULL, 0, NULL, NULL);
        BIO_free(bio);

        //save pub
        bio = BIO_new_file(filenamepub, "wb");
        PEM_write_bio_PUBKEY(bio, pkey);
        BIO_free(bio);

        EVP_PKEY_free(pkey);
        EVP_PKEY_CTX_free(pctx);
        break;
    }
    case 2: { //BER
        //save priv
        BIO* bio = BIO_new_file(filenamepriv, "wb");
        i2d_PrivateKey_bio(bio, pkey);
        BIO_free(bio);

        //save pub
        bio = BIO_new_file(filenamepub, "wb");
        i2d_PUBKEY_bio(bio, pkey);
        BIO_free(bio);

        EVP_PKEY_free(pkey);
        EVP_PKEY_CTX_free(pctx);
        break;
    }
    default:
        return false;
    }
    return true;
}
