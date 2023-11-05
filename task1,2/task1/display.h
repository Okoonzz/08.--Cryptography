#ifndef DISPLA_H
#define DISPLA_H

#include "icltemp.h"

void termin(string ret){
    cout << "Ciphertext: " << ret << endl;
}


void fl(string ret, string _f){
    ofstream f;
    f.open(_f);
    f << ret;
    cout << "Ciphertext has been written to " << _f << endl;
    f.close(); 
}

void termindec(string ret){
    cout << "Plaintext: " << ret << endl;
}


void fldec(string ret, string _f){
    ofstream f;
    f.open(_f);
    f << ret;
    cout << "Plaintext has been written to " << _f << endl;
    f.close(); 
}
#endif 