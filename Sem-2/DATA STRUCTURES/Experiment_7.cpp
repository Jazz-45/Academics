#include <iostream>
using namespace std;

int main() {

    int m, n, p,q;
    cout << "Enter number of rows of the first matrix: ";
    cin >> m;
    cout << "Enter number of columns of the first matrix: ";
    cin >> n;

    // Input for the dimensions of the second matrix
    cout << "Enter number of rows of the second matrix: ";
    cin >> p;
    cout<<"Enter number of columns of the second matrix: ";
    cin>>q;

    // Check if the number of columns in the first matrix is equal to the number of rows in the second matrix
    if (n != p) {
        cout << "Matrix multiplication is not possible." << endl;
    }
    else {
    int matrix1[m][n], matrix2[n][q], productMatrix[m][q];
    cout << "Enter elements of first matrix:" << endl;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix1[i][j];
        }
    }

    
    cout << "Enter elements of second matrix:" << endl;
    for (int i = 0; i < p; ++i) {
        for (int j = 0; j < q; ++j) {
            cin >> matrix2[i][j];
        }
    }

    
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < q; ++j) {
            productMatrix[i][j] = 0;
            for (int k = 0; k < n; ++k) {
                productMatrix[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    // Displaying the result
    cout << "Product of the matrices:" << endl;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < q; ++j) {
            cout << productMatrix[i][j] << " ";
        }
        cout << endl;
    }
    }

    return 0;
}
