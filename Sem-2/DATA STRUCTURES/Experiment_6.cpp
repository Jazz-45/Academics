#include <iostream>
using namespace std;

int main() {

    int m, n;
    cout << "Enter number of rows of matrix: ";
    cin >> m;
    cout << "Enter number of columns of matrix: ";
    cin >> n;
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

    // Matrix addition and direct printing
    cout << "Sum of the matrices:" << endl;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matrix1[i][j] + matrix2[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
