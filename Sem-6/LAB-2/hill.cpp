#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function to display key mat
void displayKeymat(vector<vector<int>>& keymat) {
    cout << "\nKey mat:" << endl;
    for (int i = 0; i < keymat.size(); i++) {
        cout << "[ ";
        for (int j = 0; j < keymat[i].size(); j++) {
            cout << keymat[i][j];
            if (j < keymat[i].size() - 1) cout << " ";
        }
        cout << " ]" << endl;
    }
}

// Function to calculate modular inverse
int modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1)
            return x;
    }
    return -1;
}
// Function to calculate determinant of 2x2 mat
int determinant(vector<vector<int>>& mat) {
    return (mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0]);
}
// Function to get inverse of key mat (for 2x2)
vector<vector<int>> getInversemat(vector<vector<int>>& keymat) {
    int det = determinant(keymat);
    det = (det % 26 + 26) % 26;
    
    int detInv = modInverse(det, 26);
    if (detInv == -1) {
        cout << "Key mat is not invertible!" << endl;
        return vector<vector<int>>();
    }
    
    vector<vector<int>> inverse(2, vector<int>(2));
    
    // For 2x2 mat: inverse = (1/det) * adjugate
    inverse[0][0] = (detInv * keymat[1][1] % 26 + 26) % 26;
    inverse[0][1] = (detInv * (-keymat[0][1]) % 26 + 26) % 26;
    inverse[1][0] = (detInv * (-keymat[1][0]) % 26 + 26) % 26;
    inverse[1][1] = (detInv * keymat[0][0] % 26 + 26) % 26;
    
    return inverse;
}
// Prepare text (pad with 'X' if length is odd)
string prepareText(string text) {
    if (text.length() % 2 != 0) {
        text += 'X';
    }
    return text;
}
// Encryption function
string encrypt(string plaintext, vector<vector<int>>& keymat) {
    plaintext = prepareText(plaintext);
    string ciphertext = "";
    int keySize = keymat.size();
    
    for (size_t i = 0; i < plaintext.length(); i += keySize) {
        vector<int> block(keySize);
        
        // Get block of characters
        for (int j = 0; j < keySize; j++) {
            block[j] = plaintext[i + j] - 'A';
        }
        
        // Multiply with key mat
        for (int j = 0; j < keySize; j++) {
            int sum = 0;
            for (int k = 0; k < keySize; k++) {
                sum += keymat[j][k] * block[k];
            }
            ciphertext += char((sum % 26) + 'A');
        }
    }
    return ciphertext;
}
// Decryption function
string decrypt(string ciphertext, vector<vector<int>>& keymat) {
    vector<vector<int>> inverseKey = getInversemat(keymat);
    if (inverseKey.empty()) {
        return "";
    }
    
    string plaintext = "";
    int keySize = keymat.size();
    
    for (size_t i = 0; i < ciphertext.length(); i += keySize) {
        vector<int> block(keySize);
        
        // Get block of characters
        for (int j = 0; j < keySize; j++) {
            block[j] = ciphertext[i + j] - 'A';
        }
        
        // Multiply with inverse key mat
        for (int j = 0; j < keySize; j++) {
            int sum = 0;
            for (int k = 0; k < keySize; k++) {
                sum += inverseKey[j][k] * block[k];
            }
            plaintext += char((sum % 26 + 26) % 26 + 'A');
        }
    }
    return plaintext;
}
int main() {
    vector<vector<int>> key = {{3, 3}, {2, 5}};
    
    string plaintext;
    cout << "Code- Hill     Name- Jayesh Sharma      Roll No.23115045 \n\n";
    
    cout << "Enter plaintext : ";
    cin >> plaintext;
    
    // Display key mat
    displayKeymat(key);
    
    string encrypted = encrypt(plaintext, key);
    cout << "\nEncrypted: " << encrypted << endl;
    
    string decrypted = decrypt(encrypted, key);
    cout << "Decrypted: " << decrypted << endl;
    
    return 0;
}