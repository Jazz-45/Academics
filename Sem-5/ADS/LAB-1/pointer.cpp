#include <iostream>
using namespace std;

int main() {
    int num1 = 60;
    float num2 = 60.0;
    void* ptr;

    ptr = &num1;
    cout << "Void pointer pointing to integer: " << *(static_cast<int*>(ptr)) << endl;

    ptr = &num2;
    cout << "Void pointer pointing to float: " << *(static_cast<float*>(ptr)) << endl;

    return 0;
}