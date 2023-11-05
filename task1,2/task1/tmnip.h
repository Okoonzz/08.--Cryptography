#ifndef TMN_H
#define TMN_H

#include "icltemp.h"

CryptoPP::byte* ipKey(){
    CryptoPP::byte* key = new CryptoPP::byte[AES::DEFAULT_KEYLENGTH];
    string inputKey;
    cout << "Enter key: ";
    cin >> inputKey;
    cin.ignore();
    std::memcpy(key, inputKey.data(), AES::DEFAULT_KEYLENGTH);
    return key;
}


CryptoPP::byte* ipIV(){
    CryptoPP::byte* iv = new CryptoPP::byte[AES::BLOCKSIZE];
    string inputIV;
    cout << "Enter iv: ";
    cin >> inputIV;
    cin.ignore();
    std::memcpy(iv, inputIV.data(), AES::BLOCKSIZE);
    return iv;
}


CryptoPP::byte* inputIVhex() {
    CryptoPP::byte* iv = new CryptoPP::byte[AES::BLOCKSIZE];
    string hex;
    cout << "Enter iv: ";
    cin >> hex;
    cin.ignore();
    StringSource ss(hex, true, new HexDecoder(new ArraySink(iv, AES::BLOCKSIZE)));
    return iv;
}



CryptoPP::byte* inputkeyhex() {
    CryptoPP::byte* key = new CryptoPP::byte[AES::DEFAULT_KEYLENGTH];
    string hex ;
    cout << "Enter key: ";
    cin >> hex;
    cin.ignore();
    StringSource ss(hex, true, new HexDecoder(new ArraySink(key, AES::DEFAULT_KEYLENGTH)));
    return key;
}


// MODE CBC
string encIpCBC(CryptoPP::byte* key, CryptoPP::byte* iv, string plaintext) {
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

string decrIpCBC(CryptoPP::byte* key, CryptoPP::byte* iv, string cipher){
    string   recovered;
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
string encIpECB(CryptoPP::byte* key, string plaintext) {
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

string decrIpECB(CryptoPP::byte* key, string cipher){
    string recovered;
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
string encIpCFB(CryptoPP::byte* key, CryptoPP::byte* iv, string plaintext) {
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

string decrIpCFB(CryptoPP::byte* key, CryptoPP::byte* iv, string cipher){
    string recovered;
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
string encIpOFB(CryptoPP::byte* key, CryptoPP::byte* iv, string plaintext) {
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

string decrIpOFB(CryptoPP::byte* key, CryptoPP::byte* iv, string cipher){
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
string encIpCTR(CryptoPP::byte* key, CryptoPP::byte* iv, string plaintext) {
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

string decrIpCTR(CryptoPP::byte* key, CryptoPP::byte* iv, string cipher){
    string recovered;
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
string encIpXTS(CryptoPP::byte* key, CryptoPP::byte* iv, string plaintext) {
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

string decrIpXTS(CryptoPP::byte* key, CryptoPP::byte* iv, string cipher){
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
string encIpCCM(CryptoPP::byte* key, CryptoPP::byte* iv, string plaintext) {
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

string decrIpCCM(CryptoPP::byte* key, CryptoPP::byte* iv, string cipher){
    CryptoPP::byte iv_12[12];
    memcpy(iv_12, iv, 12);
    string   recovered;
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
string encIpGCM(CryptoPP::byte* key, CryptoPP::byte* iv, string plaintext) {
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

string decrIpGCM(CryptoPP::byte* key, CryptoPP::byte* iv, string cipher){
    string  recovered;
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