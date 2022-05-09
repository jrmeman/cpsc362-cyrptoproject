/*  Name: Justin Meman
    CPSC 362 - Cyrpto Program
    Due: 3/3/2021

    A program that allows a user to input a string along 
    with a key to allow for encryption/decryption.
*/

#include "crypto.h"
using namespace std;

// Default constructor
Crypto::Crypto() {
    inputBuffer = new char[0];
    cryptoKey[0] = 0;
    cryptoMatrix[0] = 0;
    clearMatrix[0] = 0;
    inputSize = 0;
    keySize = 0;
}

// Class destructor
Crypto::~Crypto() {
    delete[] inputBuffer;
}

void Crypto::Encrypt(string input, string key) {
    int size = GetInputSize();
    inputBuffer = new char[size];
    // Converting string to char array
    strcpy(inputBuffer, input.c_str());

    // Converting key to char array
    strcpy(cryptoKey, key.c_str());

    cout << "-- PROGRAM ENCRYPTING STRING --\n";
    cout << "--  Press ENTER to continue  --";
    cin.get(); // Pause

    // Encryption process (XOR)
    int j = 0;
    for(int i = 0; i < size; i++) {
        if(j == 8)
            j = 0;

        char temp = inputBuffer[i] ^ cryptoKey[j];
        cryptoMatrix[i] = temp;

        j++;
    }

    // Display encrypted message
    cout << "Encrypted Message:\n\t";
    for(int i = 0; i < size; i++)
        cout << cryptoMatrix[i];
    cout << endl;
}

void Crypto::Decrypt(string key) {
    int size = strlen(inputBuffer);

    // Converting cryptoKey char array into string k
    string k;
    for(int i = 0; i < 8; i++) {
        k += cryptoKey[i];
    }

    // String k allows validity check to see if it's the "correct" key
    while(key != k) {
        cout << "\nERROR: Invalid Key - Try Again" << endl;
        cout << "Enter correct key: ";
        getline(cin, key);
    }
    cout << "\n-- CORRECT KEY INPUTTED --\n\n"; // Validity check passed

    cout << "-- PROGRAM DECRYPTING STRING --\n";
    cout << "--  Press ENTER to continue  --";
    cin.get(); // Pause

    // Displays currently encrypted message
    cout << "Stored Message:\n\t";
    for(int i = 0; i < size; i++)
        cout << cryptoMatrix[i];
    cout << endl;

    // Decryption process (XOR)
    int j = 0;
    for(int i = 0; i < size; i++) {
        if(j == 8)
            j = 0;

        char temp = cryptoMatrix[i] ^ cryptoKey[j];
        clearMatrix[i] = temp;

        j++;
    }

    // Display decrypted message
    cout << "Decrypted Message:\n\t";
    for(int i = 0; i < size; i++)
        cout << clearMatrix[i];
    cout << endl;
}

int main() {
    Crypto crypto;
    string input, key;  // Declare input variables
    int menuChoice;
    bool exit = false;  // Initilize exit bool

    do {
        cout << "\nMain Menu" << endl;
        cout << "\t1. Encrypt\n";
        cout << "\t2. Decrypt\n";
        cout << "\t3. Exit Program\n";
        cout << "Enter choice: ";
        cin >> menuChoice;

        switch(menuChoice){
            case 1:
                // User input string to be encrypted
                cout << "\nEnter string (Max 128 char): ";
                cin.ignore();
                getline(cin, input);

                // Validity check - making sure the user input string is < 128 char
                while (input.length() > 128){
                    cout << "\nERROR: 128 Max char - Try Again\n";
                    cout << "Enter string (Max 128 char): ";
                    getline(cin, input);
                }
                crypto.SetInputSize(input.length());
                cout << "SUCCESS - Inputted string length: " << input.length() << endl;

                // User input encryption key
                cout << "Enter encryption key (8 char Only): ";
                getline(cin, key);

                // Validity check - making sure the user input key is = 8 char
                while (key.length() != 8){
                    cout << "\nERROR: 8 char only - Try Again\n";
                    cout << "Enter encryption key (8 char Only): ";
                    getline(cin, key);
                }
                crypto.SetKeySize(key.length());

                crypto.Encrypt(input, key);
                break;

            case 2:
                // User input encryption key
                cout << "\nEnter encryption key (8 char Only): ";
                cin.ignore();
                getline(cin, key);

                // Validity check - making sure the user input key is = 8 char
                while (key.length() != 8){
                    cout << "\nERROR: 8 char only - Try Again\n";
                    cout << "Enter encryption key (8 char Only): ";
                    getline(cin, key);
                }
                crypto.Decrypt(key);
                break;  

            case 3:
                exit = true;
                break;

            default:
                cout << "\nERROR: Invalid input - Redirecting back to menu";
                cin.ignore();
                cin.get();
                exit = false;
        }
    } while(exit != true);
    cout << "Thank you for using the Encryption Program!";

    cin.ignore();
    cin.get();
    return 0;
}