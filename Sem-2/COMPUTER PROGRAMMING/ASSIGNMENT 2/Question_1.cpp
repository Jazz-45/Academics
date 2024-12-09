#include <iostream>
using namespace std;

int main() {
    
    cout << "Size of short int: " << sizeof(short int) << " bytes\n";
    cout << "Size of short signed int: " << sizeof(short signed int) << " bytes\n";
    cout << "Size of short unsigned int: " << sizeof(short unsigned int) << " bytes\n";
    cout << "Size of int: " << sizeof(int) << " bytes\n";
    cout << "Size of signed int: " << sizeof(signed int) << " bytes\n";
    cout << "Size of unsigned int: " << sizeof(unsigned int) << " bytes\n";
    cout << "Size of long int: " << sizeof(long int) << " bytes\n";
    cout << "Size of signed long int: " << sizeof(signed long int) << " bytes\n";
    cout << "Size of unsigned long int: " << sizeof(unsigned long int) << " bytes\n";
    cout << "Size of long long int: " << sizeof(long long int) << " bytes\n";
    cout << "Size of signed long long int: " << sizeof(signed long long int) << " bytes\n";
    cout << "Size of unsigned long long int: " << sizeof(unsigned long long int) << " bytes\n";
    cout << "Size of char: " << sizeof(char) << " bytes\n";
    cout << "Size of unsigned char: " << sizeof(unsigned char) << " bytes\n";
    cout << "Size of signed char: " << sizeof(signed char) << " bytes\n";
    cout << "Size of float: " << sizeof(float) << " bytes\n";
    cout << "Size of double: " << sizeof(double) << " bytes\n";
    cout << "Size of long double: " << sizeof(long double) << " bytes\n";
    cout << "Size of boolean: " << sizeof(bool) << " bytes\n";
    cout << "Size of wide character: " << sizeof(wchar_t) << " bytes\n";

    return 0;
}
