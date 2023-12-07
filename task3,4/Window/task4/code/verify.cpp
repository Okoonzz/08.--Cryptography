#include <openssl/evp.h>
#include <openssl/pem.h>
#include <openssl/ec.h>
#include <openssl/bio.h>
#include <openssl/ec.h>
#include <openssl/sha.h>
#include <windows.h>
#include <fstream>
#include <vector>
#include <iterator>

extern "C" {
	__declspec(dllexport) bool verifySignature(const char* pathpub, const char* pathdata, const char* pathsig, int choice);
}

bool verifySignature(const char* pathpub, const char* pathdata, const char* pathsig, int choice) {
	BIO* bio = BIO_new(BIO_s_file());
	BIO_read_filename(bio, pathpub);
	switch (choice) {
	case 1: { //PEM
		EVP_PKEY* publicKey = PEM_read_bio_PUBKEY(bio, NULL, NULL, NULL);

		unsigned char hash[SHA256_DIGEST_LENGTH];
		std::ifstream pdfFile(pathdata, std::ios::binary);
		std::vector<unsigned char> pdfContents((std::istreambuf_iterator<char>(pdfFile)), std::istreambuf_iterator<char>());
		pdfFile.close();

		SHA256(&pdfContents[0], pdfContents.size(), hash);

		std::ifstream signatureFile(pathsig, std::ios::binary);
		std::vector<unsigned char> signature((std::istreambuf_iterator<char>(signatureFile)), std::istreambuf_iterator<char>());
		signatureFile.close();

		EVP_MD_CTX* ctx = EVP_MD_CTX_new();
		EVP_DigestVerifyInit(ctx, NULL, EVP_sha256(), NULL, publicKey);
		int result = EVP_DigestVerify(ctx, signature.data(), signature.size(), hash, SHA256_DIGEST_LENGTH);

		EVP_MD_CTX_free(ctx);
		EVP_PKEY_free(publicKey);

		return result == 1;
	}
	case 2: {
		EVP_PKEY* publicKey = d2i_PUBKEY_bio(bio, NULL);

		unsigned char hash[SHA256_DIGEST_LENGTH];
		std::ifstream pdfFile(pathdata, std::ios::binary);
		std::vector<unsigned char> pdfContents((std::istreambuf_iterator<char>(pdfFile)), std::istreambuf_iterator<char>());
		pdfFile.close();

		SHA256(&pdfContents[0], pdfContents.size(), hash);

		std::ifstream signatureFile(pathsig, std::ios::binary);
		std::vector<unsigned char> signature((std::istreambuf_iterator<char>(signatureFile)), std::istreambuf_iterator<char>());
		signatureFile.close();

		EVP_MD_CTX* ctx = EVP_MD_CTX_new();
		EVP_DigestVerifyInit(ctx, NULL, EVP_sha256(), NULL, publicKey);
		int result = EVP_DigestVerify(ctx, signature.data(), signature.size(), hash, SHA256_DIGEST_LENGTH);

		EVP_MD_CTX_free(ctx);
		EVP_PKEY_free(publicKey);

		return result == 1;
	}
	}
	return 0;
}

