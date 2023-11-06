#ifndef ENCCBC_H
#define ENCCBC_H

#include "icltemp.h"

CryptoPP::byte* genIV() {
    AutoSeededRandomPool prng;
    CryptoPP::byte* iv = new CryptoPP::byte[AES::BLOCKSIZE];
    prng.GenerateBlock(iv, AES::BLOCKSIZE);
    string encoded;
    StringSource(iv, AES::BLOCKSIZE, true,
		new HexEncoder(
			new StringSink(encoded)
		) 
	); 
    cout << "IV: " << encoded << endl;
    return iv;
}

CryptoPP::byte* genKey() {
    AutoSeededRandomPool prng;
    CryptoPP::byte* key = new CryptoPP::byte[AES::DEFAULT_KEYLENGTH];
    prng.GenerateBlock(key, AES::DEFAULT_KEYLENGTH);
    string encoded;
    StringSource(key, AES::DEFAULT_KEYLENGTH, true,
	    new HexEncoder(
			new StringSink(encoded)
		) 
	); 
    cout << "Key: " << encoded << endl;
    return key;
}


CryptoPP::byte *IVFile(string fn){
    CryptoPP::byte* iv = new CryptoPP::byte[AES::BLOCKSIZE];
    ifstream file(fn);
    if (file.fail()) {
        std::cerr << "Error: File does not exist.\n";
        exit(1); 
    }
    string tmp((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    std::memcpy(iv, tmp.data(), AES::DEFAULT_KEYLENGTH);
    return iv;
}


CryptoPP::byte *keyFile(string fn){
    CryptoPP::byte* key = new CryptoPP::byte[AES::DEFAULT_KEYLENGTH];
    ifstream file(fn);
    if (file.fail()) {
        std::cerr << "Error: File does not exist.\n";
        exit(1); 
    }
    file.open(fn);
    string tmp((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    std::memcpy(key, tmp.data(), AES::DEFAULT_KEYLENGTH);
    return key;
}


// MODE CBC
string encCBC(CryptoPP::byte* key, CryptoPP::byte* iv, string plaintext) {
    string cipher;
    CBC_Mode<AES>::Encryption e;
    e.SetKeyWithIV(key, AES::DEFAULT_KEYLENGTH, iv);
    StringSource(plaintext, true,
        new StreamTransformationFilter(e,
            new StringSink(cipher)
        )
    );
    return cipher;
}

string decrCBC(CryptoPP::byte* key, CryptoPP::byte* iv,string cipher){
    string recovered;
	CBC_Mode< AES >::Decryption d;
	d.SetKeyWithIV(key, AES::DEFAULT_KEYLENGTH, iv);
	StringSource s(cipher, true,
            new StreamTransformationFilter(d,
			    new StringSink(recovered)
		    ) 
    );
    return recovered;
}


// MODE ECB
string encECB(CryptoPP::byte* key, string plaintext) {
    string cipher;
    ECB_Mode<AES>::Encryption e;
    e.SetKey(key, AES::DEFAULT_KEYLENGTH);
    StringSource(plaintext, true,
        new StreamTransformationFilter(e,
            new StringSink(cipher)
        )
    );
    return cipher;
}

string decrECB(CryptoPP::byte* key, string cipher){
    string  recovered;
	ECB_Mode< AES >::Decryption d;
	d.SetKey(key, AES::DEFAULT_KEYLENGTH);
	StringSource s(cipher, true,
            new StreamTransformationFilter(d,
			    new StringSink(recovered)
		    ) 
    );
    return recovered;
}


// MODE CFB
string encCFB(CryptoPP::byte* key, CryptoPP::byte* iv, string plaintext) {
    string cipher;
    CFB_Mode<AES>::Encryption e;
    e.SetKeyWithIV(key, AES::DEFAULT_KEYLENGTH, iv);
    StringSource(plaintext, true,
        new StreamTransformationFilter(e,
            new StringSink(cipher)
        )
    );
    return cipher;
}

string decrCFB(CryptoPP::byte* key, CryptoPP::byte* iv,string cipher){
    string  recovered;
	CFB_Mode< AES >::Decryption d;
	d.SetKeyWithIV(key, AES::DEFAULT_KEYLENGTH, iv);
	StringSource s(cipher, true,
            new StreamTransformationFilter(d,
			    new StringSink(recovered)
		    ) 
    );
    return recovered;
}


// MODE OFB
string encOFB(CryptoPP::byte* key, CryptoPP::byte* iv, string plaintext) {
    string cipher;
    OFB_Mode<AES>::Encryption e;
    e.SetKeyWithIV(key, AES::DEFAULT_KEYLENGTH, iv);
    StringSource(plaintext, true,
        new StreamTransformationFilter(e,
            new StringSink(cipher)
        )
    );
    return cipher;
}

string decrOFB(CryptoPP::byte* key, CryptoPP::byte* iv,string cipher){
    string recovered;
	OFB_Mode< AES >::Decryption d;
	d.SetKeyWithIV(key, AES::DEFAULT_KEYLENGTH, iv);
	StringSource s(cipher, true,
            new StreamTransformationFilter(d,
			    new StringSink(recovered)
		    ) 
    );
    return recovered;
}


// MODE CTR
string encCTR(CryptoPP::byte* key, CryptoPP::byte* iv, string plaintext) {
    string cipher;
    CTR_Mode<AES>::Encryption e;
    e.SetKeyWithIV(key, AES::DEFAULT_KEYLENGTH, iv);
    StringSource(plaintext, true,
        new StreamTransformationFilter(e,
            new StringSink(cipher)
        )
    );
    return cipher;
}

string decrCTR(CryptoPP::byte* key, CryptoPP::byte* iv,string cipher){
    string  recovered;
	CTR_Mode< AES >::Decryption d;
	d.SetKeyWithIV(key, AES::DEFAULT_KEYLENGTH, iv);
	StringSource s(cipher, true,
            new StreamTransformationFilter(d,
			    new StringSink(recovered)
		    ) 
    );
    return recovered;
}


// MODE XTR
string encXTS(CryptoPP::byte* key, CryptoPP::byte* iv, string plaintext) {
    string cipher;
    XTS_Mode<AES>::Encryption e;
    e.SetKeyWithIV(key, AES::MAX_KEYLENGTH, iv);
    StringSource(plaintext, true,
        new StreamTransformationFilter(e,
            new StringSink(cipher),
            StreamTransformationFilter::NO_PADDING
        )
    );
    return cipher;
}

string decrXTS(CryptoPP::byte* key, CryptoPP::byte* iv,string cipher){
    string  recovered;
	XTS_Mode< AES >::Decryption d;
	d.SetKeyWithIV(key, AES::MAX_KEYLENGTH, iv);
	StringSource s(cipher, true,
            new StreamTransformationFilter(d,
			    new StringSink(recovered),
                StreamTransformationFilter::NO_PADDING
		    ) 
    );
    return recovered;
}


// MODE CCM
const int TAG_SIZE = 8;
string encCCM(CryptoPP::byte* key, CryptoPP::byte* iv, string plaintext) {
    CryptoPP:: byte iv_12[12];
    memcpy(iv_12, iv, 12);
    string cipher;
    CCM<AES, TAG_SIZE>::Encryption e;
    e.SetKeyWithIV(key, AES::DEFAULT_KEYLENGTH, iv_12, 12);
    e.SpecifyDataLengths(0, plaintext.size(), 0);
    StringSource(plaintext, true,
        new AuthenticatedEncryptionFilter(e,
            new StringSink(cipher)
        )
    );
    return cipher;
}

string decrCCM(CryptoPP::byte* key, CryptoPP::byte* iv, string cipher){
    string  recovered;
    CryptoPP::byte iv_12[12];
    memcpy(iv_12, iv, 12);

	CCM< AES, TAG_SIZE >::Decryption d;
	d.SetKeyWithIV(key, AES::DEFAULT_KEYLENGTH, iv_12, 12);
    d.SpecifyDataLengths(0, cipher.size()-TAG_SIZE, 0);

    AuthenticatedDecryptionFilter df(d, new StringSink(recovered));
	StringSource s(cipher, true,
        new Redirector(df)
	);
    return recovered;
}


// MODE GCM
string encGCM(CryptoPP::byte* key, CryptoPP::byte* iv, string plaintext) {
    string cipher;
    GCM<AES>::Encryption e;
    e.SetKeyWithIV(key, AES::DEFAULT_KEYLENGTH, iv);
    StringSource(plaintext, true,
        new AuthenticatedEncryptionFilter(e,
            new StringSink(cipher)
        )
    );
    return cipher;
}

string decrGCM(CryptoPP::byte* key, CryptoPP::byte* iv, string cipher){
    string recovered;
	GCM< AES >::Decryption d;
	d.SetKeyWithIV(key, AES::DEFAULT_KEYLENGTH, iv);
    StringSource(cipher, true,
                new AuthenticatedDecryptionFilter(d,
                    new StringSink(recovered)
                )
        );
    return recovered;
}

#endif 
