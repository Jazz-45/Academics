#include <iostream>
#include <string>
using namespace std;

char mat[5][5];

// Create the 5x5 mat using the key
void createmat(string key) {
    bool used[26] = {false};
    used['J'-'A'] = true; // Treat J as I
    
    int row = 0, col = 0;
    
    // Add key characters to mat
    for (int i = 0; i < key.length(); i++) {
        char c = key[i];
        if (c == 'J') c = 'I';
        
        if (!used[c - 'A']) {
            mat[row][col] = c;
            used[c - 'A'] = true;
            col++;
            if (col == 5) {
                col = 0;
                row++;
            }
        }
    }
    
    // Fill remaining with unused letters
    for (char c = 'A'; c <= 'Z'; c++) {
        if (c == 'J') continue;
        if (!used[c - 'A']) {
            mat[row][col] = c;
            col++;
            if (col == 5) {
                col = 0;
                row++;
            }
        }
    }
}

// Display the 5x5 mat
void displaymat() {
    cout << "\nPlayfair mat:\n";
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// Find position of a character in mat
void findPosition(char c, int &row, int &col) {
    if (c == 'J') c = 'I';
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (mat[i][j] == c) {
                row = i;
                col = j;
                return;
            }
        }
    }
}

// Prepare text for encryption
string prepareText(string text) {
    string processed = "";
    
    // Add 'X' between duplicate letters
    for (int i = 0; i < text.length(); i++) {
        processed += text[i];
        if (i < text.length() - 1 && text[i] == text[i + 1]) {
            processed += 'X';
        }
    }
    
    // Add 'X' at end if odd length
    if (processed.length() % 2 != 0) {
        processed += 'X';
    }
    
    return processed;
}

// Encrypt the plaintext
string encrypt(string plaintext) {
    string prepared = prepareText(plaintext);
    string ciphertext = "";
    
    for (int i = 0; i < prepared.length(); i += 2) {
        char a = prepared[i];
        char b = prepared[i + 1];
        
        int row1, col1, row2, col2;
        findPosition(a, row1, col1);
        findPosition(b, row2, col2);
        
        if (row1 == row2) {
            // Same row - shift right
            ciphertext += mat[row1][(col1 + 1) % 5];
            ciphertext += mat[row2][(col2 + 1) % 5];
        } else if (col1 == col2) {
            // Same column - shift down
            ciphertext += mat[(row1 + 1) % 5][col1];
            ciphertext += mat[(row2 + 1) % 5][col2];
        } else {
            // Rectangle - swap columns
            ciphertext += mat[row1][col2];
            ciphertext += mat[row2][col1];
        }
    }
    
    return ciphertext;
}

// Decrypt the ciphertext
string decrypt(string ciphertext) {
    string plaintext = "";
    
    for (int i = 0; i < ciphertext.length(); i += 2) {
        char a = ciphertext[i];
        char b = ciphertext[i + 1];
        
        int row1, col1, row2, col2;
        findPosition(a, row1, col1);
        findPosition(b, row2, col2);
        
        if (row1 == row2) {
            // Same row - shift left
            plaintext += mat[row1][(col1 + 4) % 5];
            plaintext += mat[row2][(col2 + 4) % 5];
        } else if (col1 == col2) {
            // Same column - shift up
            plaintext += mat[(row1 + 4) % 5][col1];
            plaintext += mat[(row2 + 4) % 5][col2];
        } else {
            // Rectangle - swap columns
            plaintext += mat[row1][col2];
            plaintext += mat[row2][col1];
        }
    }
    
    return plaintext;
}

int main() {
    string key, plaintext;
    
    cout << "Code- Playfair Cipher     Name- Jayesh Sharma      Roll No.23115045 \n\n";
    
    cout << "Enter the key: "; cin >> key;
    
    cout << "Enter the plaintext: "; cin >> plaintext;
    
    createmat(key);
    displaymat();
    
    string encrypted = encrypt(plaintext);
    cout << "Encrypted text: " << encrypted << endl;
    
    string decrypted = decrypt(encrypted);
    cout << "Decrypted text: " << decrypted << endl;
    
    return 0;
}
