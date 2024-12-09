#include <iostream>
using namespace std;

int main() {

    int m, n;
    cout << "Enter number of rows of the  matrix: ";
    cin >> m;
    cout << "Enter number of columns of the matrix: ";
    cin >> n;

    int matrix[m][n];
    cout << "Enter elements of  matrix:" << endl;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }

    
    cout << "The Transpose matrix is:" << endl;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cout<< matrix[j][i]<<" ";
        }
        cout<<endl;
    }

    return 0;
}