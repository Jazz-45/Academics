#include <iostream>
using namespace std;

int main() {
    int num1 = 60;
    float num2 = 60.0;
    char ch = 'J';
    string name = "Jayesh Sharma";
    long long int rollNo = 23115045;
    void* ptr;

    ptr = &num1;
    cout << "Void pointer pointing to integer: " << *(static_cast<int*>(ptr)) << endl;

    ptr = &num2;
    cout << "Void pointer pointing to float: " << *(static_cast<float*>(ptr)) << endl;

    ptr = &ch;
    cout << "Void pointer pointing to char: " << *(static_cast<char*>(ptr)) << endl;

    ptr = &name;
    cout << "Void pointer pointing to string: " << *(static_cast<string*>(ptr)) << endl;

    ptr = &rollNo;
    cout << "Void pointer pointing to long long int: " << *(static_cast<long long int*>(ptr)) << endl;

    return 0;
}
