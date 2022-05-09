#ifndef CRYPTO_H
#define CRYPTO_H

#include <iostream>
#include <string>
using namespace std;

const int MAXSIZE = 128;

class Crypto {
private:
    char *inputBuffer;
    char cryptoKey[8];
    int inputSize;
    int keySize;
    char cryptoMatrix[MAXSIZE];
    char clearMatrix[MAXSIZE];

public:
    Crypto();
    ~Crypto();
    void Encrypt(string, string);
    void Decrypt(string);
    void SetInputSize(int x) { inputSize = x; }
    void SetKeySize(int x) { keySize = x; } 
    int GetInputSize() { return inputSize; }
    int GetKeySize() { return keySize; }
};

#endif