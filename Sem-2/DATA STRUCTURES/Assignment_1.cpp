#include <iostream>
using namespace std;

int main() {

    int m, n;

    // Input for the dimensions of matrices
    cout << "Enter number of rows of the matrices: ";
    cin >> m;
    cout << "Enter number of columns of the matrices: ";
    cin >> n;

    // Declaration of matrices
    int matrix1[m][n], matrix2[m][n];

    // Input for the first matrix
    cout << "Enter elements of first matrix:" << endl;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix1[i][j];
        }
    }

    // Input for the second matrix
    cout << "Enter elements of second matrix:" << endl;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix2[i][j];
        }
    }

    // Matrix subtraction and direct printing
    cout << "Difference of the matrices:" << endl;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matrix1[i][j] - matrix2[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

