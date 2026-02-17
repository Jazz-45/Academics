#include <iostream>
#include <string>
using namespace std;

// Function to generate repeated key
string generateKey(string text, string key) {
    int x = text.size();
    for (int i = 0; ; i++) {
        if (x == key.size())
            break;
        key.push_back(key[i]);
    }
    return key;
}

// Encryption function
string encryptVigenere(string text, string key) {
    string cipher = "";
    
    for (int i = 0; i < text.size(); i++) {
        char c = (text[i] + key[i]) % 26;
        c += 'A';
        cipher.push_back(c);
    }
    
    return cipher;
}

// Decryption function
string decryptVigenere(string cipher, string key) {
    string text = "";
    
    for (int i = 0; i < cipher.size(); i++) {
        char p = (cipher[i] - key[i] + 26) % 26;
        p += 'A';
        text.push_back(p);
    }
    
    return text;
}

int main() {
    string plaintext, key;
    
    cout << "Code- Vigenere Cipher     Name- Jayesh Sharma      Roll No.23115045 \n\n";
    
    cout << "Enter Plaintext : ";
    cin >> plaintext;
    
    cout << "Enter Key : ";
    cin >> key;
    
    // Generate repeated key
    string newKey = generateKey(plaintext, key);
    
    cout << "\nRepeated Key: " << newKey << endl;
    
    // Encryption
    string ciphertext = encryptVigenere(plaintext, newKey);
    cout << "\nEncrypted: " << ciphertext << endl;
    
    // Decryption
    string decryptedText = decryptVigenere(ciphertext, newKey);
    cout << "Decrypted: " << decryptedText << endl;
    
    return 0;
}