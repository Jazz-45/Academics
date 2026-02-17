#include <iostream>
#include <vector>
#include <string>
using namespace std;

// ---------------- ENCRYPTION ----------------
string encryptRailFence(string text, int key) {
    if (key == 1) return text;
    
    vector<string> rail(key);
    int dir = 1, row = 0;
    
    for (char c : text) {
        rail[row].push_back(c);
        row += dir;
        if (row == 0 || row == key - 1)
            dir *= -1;
    }
    
    string cipher = "";
    for (string r : rail)
        cipher += r;
    
    return cipher;
}

// ---------------- DECRYPTION ----------------
string decryptRailFence(string cipher, int key) {
    if (key == 1) return cipher;
    
    int n = cipher.length();
    vector<vector<char>> rail(key, vector<char>(n, '\n'));
    
    // Mark zigzag pattern
    int dir = 1, row = 0;
    for (int col = 0; col < n; col++) {
        rail[row][col] = '*';
        row += dir;
        if (row == 0 || row == key - 1)
            dir *= -1;
    }
    
    // Fill characters row-wise
    int idx = 0;
    for (int i = 0; i < key; i++) {
        for (int j = 0; j < n; j++) {
            if (rail[i][j] == '*' && idx < n)
                rail[i][j] = cipher[idx++];
        }
    }
    
    // Read zigzag to get plaintext
    string text = "";
    dir = 1, row = 0;
    for (int col = 0; col < n; col++) {
        text.push_back(rail[row][col]);
        row += dir;
        if (row == 0 || row == key - 1)
            dir *= -1;
    }
    
    return text;
}

// ---------------- MAIN ----------------
int main() {
    string text;
    int key;
    
    cout << "Code- Rail Fence Cipher     Name- Jayesh Sharma      Roll No.23115045 \n\n";
    
    cout << "Enter Plaintext : "; cin >> text;
    
    cout << "Enter Number of Rails : ";cin >> key;
    
    string cipher = encryptRailFence(text, key);
    cout << "\nEncrypted: " << cipher << endl;
    
    string decrypted = decryptRailFence(cipher, key);
    cout << "Decrypted: " << decrypted << endl;
    
    return 0;
}