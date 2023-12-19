#include <openssl/bio.h>
#include <openssl/err.h>
#include <openssl/pem.h>
#include <openssl/x509.h>
#include <string>
using namespace std;


void PrintInfo(EVP_PKEY* publicKey){
    //Print algo publickey
    const char *algorithm = OBJ_nid2ln(EVP_PKEY_id(publicKey));
    printf("Public Key Algorithm: %s\n", algorithm);

    //Print the public key
    BIO *bio_out = BIO_new(BIO_s_mem());
    if (!EVP_PKEY_print_public(bio_out, publicKey, 0, NULL)) {
        printf("Error printing public key\n");
        exit(0);
    }
    char *publicKeyStr = NULL;
    long publicKeyLen = BIO_get_mem_data(bio_out, &publicKeyStr);
    fwrite(publicKeyStr, 1, publicKeyLen, stdout);
    BIO_free(bio_out);
}


bool VeriFy(X509* cert, STACK_OF(X509)* issuers, X509_STORE* store) {
    // Create a verification context
    X509_STORE_CTX* ctx = X509_STORE_CTX_new();
    X509_STORE_CTX_init(ctx, store, cert, issuers);
    
    // Verify the certificate
    int result = X509_verify_cert(ctx);
    // Clean up
    X509_STORE_CTX_free(ctx);
    return result == 1;
}

int ValidOrNot(char* certificate, char* intermediate, char* rootcertificate, int choice){
    OpenSSL_add_all_algorithms();
    ERR_load_BIO_strings();
    ERR_load_crypto_strings();

    X509 *cert = NULL;
    STACK_OF(X509)* issuers = sk_X509_new_null();
    X509 *issuer = NULL;
    X509 *root = NULL;

    // Load the certificate from file
    BIO *certificateBio = BIO_new(BIO_s_file());
    if (!(BIO_read_filename(certificateBio, certificate))) {
        printf("Error in reading certificate file\n");
        return -1;
    }

    //Load Intermedidate
    BIO *intermed = BIO_new(BIO_s_file());
    if (!(BIO_read_filename(intermed, intermediate))) {
        printf("Error in reading intermediate cert file\n");
        return -1;
    }

    // Load the certificate from file
    BIO *rootCert = BIO_new(BIO_s_file());
    if (!(BIO_read_filename(rootCert, rootcertificate))) {
        printf("Error in reading rootcertificate file\n");
        return -1;
    }
    
    //Load type
    switch (choice){
        case 1: { //PEM
            cert = PEM_read_bio_X509(certificateBio, NULL, 0, NULL);
            while ((issuer = PEM_read_bio_X509(intermed, NULL, 0, NULL)) != NULL) {
                sk_X509_push(issuers, issuer);
            }           
            root = PEM_read_bio_X509(rootCert, NULL, 0, NULL);
            break;
        }
        case 2:{ //DER
            cert = d2i_X509_bio(certificateBio, NULL);
            while ((issuer = d2i_X509_bio(intermed, NULL)) != NULL) {
                sk_X509_push(issuers, issuer);
            }  
            root = d2i_X509_bio(rootCert, NULL);
            break;
        }
    }
    if (cert == NULL|| root == NULL) {
        printf("Error loading certificate/intermediate/rootcertificate into memory\n");
        return -1;
    }

    // Create a certificate store and add Root CA Cert
    X509_STORE* store = X509_STORE_new();
    X509_STORE_add_cert(store, root);

    int isValid = VeriFy(cert, issuers, store);

    // Validate the certificate's signature
    if (isValid != 1) {
        printf("Certificate signature is not valid\n");
        // Clean up
        X509_free(cert);
        X509_free(issuer);
        X509_free(root);
        BIO_free_all(certificateBio);
        BIO_free_all(intermed);
        BIO_free_all(rootCert);
        X509_STORE_free(store);
        sk_X509_pop_free(issuers, X509_free);
        return -1;
    } else {
        printf("Certificate signature is valid\n");
        //Load publickey
        EVP_PKEY *publicKeyCert = X509_get_pubkey(cert);
        if (publicKeyCert == NULL) {
            printf("Error getting public key from certificate\n");
            return -1;
        }
        PrintInfo(publicKeyCert);
        // Clean up
        X509_free(cert);
        X509_free(issuer);
        X509_free(root);
        BIO_free_all(certificateBio);
        BIO_free_all(intermed);
        BIO_free_all(rootCert);
        X509_STORE_free(store);
        sk_X509_pop_free(issuers, X509_free);
        return 1;
    }
}

int main(int argc, char**argv) {
    if(argc != 5){
        printf("Usage: %s <Type of certificate per(-p) or der(-d)> <certificate> <intermediate> <root>\n", argv[0]);
        exit(0);
    }
    int choice;
    if(string(argv[1]) == "-p") choice = 1;
    else choice = 2;
    ValidOrNot(argv[2], argv[3], argv[4], choice);
    return 0;
}
