#include <iostream>
#include <iomanip> 

using namespace std;

int main() {
    
    // Input real/decimal value
    double value;

    cout << "Enter a real/decimal value:\n";
    cin >> value;

    // Print the value with 6 decimal precisions
    cout << fixed << setprecision(6)<<"Value with 6 decimal precisions:\n" << value << endl;

    return 0;
}
