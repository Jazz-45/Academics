#include <iostream>
#include <climits>
#include <cfloat>

using namespace std;

int main() {
    
    cout << "Range of short int: " << SHRT_MIN << " to " << SHRT_MAX << endl;
    cout << "Range of short signed int: " << SHRT_MIN << " to " << SHRT_MAX << endl;
    cout << "Range of short unsigned int: 0 to " << USHRT_MAX << endl;
    cout << "Range of int: " << INT_MIN << " to " << INT_MAX << endl;
    cout << "Range of signed int: " << INT_MIN << " to " << INT_MAX << endl;
    cout << "Range of unsigned int: 0 to " << UINT_MAX << endl;
    cout << "Range of long int: " << LONG_MIN << " to " << LONG_MAX << endl;
    cout << "Range of signed long int: " << LONG_MIN << " to " << LONG_MAX << endl;
    cout << "Range of unsigned long int: 0 to " << ULONG_MAX << endl;
    cout << "Range of long long int: " << LLONG_MIN << " to " << LLONG_MAX << endl;
    cout << "Range of signed long long int: " << LLONG_MIN << " to " << LLONG_MAX << endl;
    cout << "Range of unsigned long long int: 0 to " << ULLONG_MAX << endl;
    cout << "Range of char: " << SCHAR_MIN << " to " << SCHAR_MAX << endl;
    cout << "Range of unsigned char: 0 to " << UCHAR_MAX << endl;
    cout << "Range of signed char: " << SCHAR_MIN << " to " << SCHAR_MAX << endl;
    cout << "Range of float: " << FLT_MIN << " to " << FLT_MAX << endl;
    cout << "Range of double: " << DBL_MIN << " to " << DBL_MAX << endl;
    cout << "Range of long double: " << LDBL_MIN << " to " << LDBL_MAX << endl;
    cout << "Range of boolean: "<<0<<" to "<<1<< endl;
    cout << "Range of wide character: " <<0<<" to "<<65535<< endl;

    return 0;
}
