#include <iostream>
#include <string>
using namespace std;

const string ALPHABET = "ABCDEFGHILMNOPQRSTUVZ";
const int M = 21;

// Find index of character in Italian alphabet
int charIndex(char c) 
{
    return ALPHABET.find(c);
}

// Modular inverse of a mod 21
int modInverse(int a) 
{
    for (int x = 1; x < M; x++) 
    {
        if ((a * x) % M == 1)
            return x;
    }
    return -1;
}

// Encrypt
string encrypt(string text, int a, int b) 
{
    string result = "";

    for (char c : text) {
        c = toupper(c);
        int x = charIndex(c);

        if (x != string::npos) {
            int enc = (a * x + b) % M;
            result += ALPHABET[enc];
        } else {
            result += c; // keep spaces and symbols
        }
    }
    return result;
}

// Decrypt
string decrypt(string text, int a, int b) 
{
    string result = "";
    int a_inv = modInverse(a);

    if (a_inv == -1)
        return "Invalid key 'a'";

    for (char c : text) {
        c = toupper(c);
        int y = charIndex(c);

        if (y != string::npos) 
        {
            int dec = (a_inv * (y - b + M)) % M;
            result += ALPHABET[dec];
        } 
        else 
        {
            result += c;
        }
    }
    return result;
}

int main() {
    int a, b;

    cout << "Enter key a (coprime with 21): ";
    cin >> a;

    if (modInverse(a) == -1) 
    {
        cout << "Invalid key 'a'. It must be coprime with 21." << endl;
        return 1; // exit program
    }

    cout << "Enter key b: ";
    cin >> b;

    int choice;
    cout << "Choose operation: 1 for Encrypt, 2 for Decrypt: ";
    cin >> choice;
    
    string text;
    cin.ignore(); // clear newline from input buffer
    cout << "Enter text: ";
    getline(cin, text);
    
    if(choice == 1)
    {
        string encrypted = encrypt(text, a, b);
        cout << "\nEncrypted: " << encrypted << endl;
    }
    else if (choice == 2)
    {
        string decrypted = decrypt(text, a, b);
        cout << "Decrypted: " << decrypted << endl;
    }
    return 0;
}
