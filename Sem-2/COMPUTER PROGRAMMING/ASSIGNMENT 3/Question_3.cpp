#include <iostream>

using namespace std;

int main() {
    // Assume Celsius value
    double celsius = 30.0;

    // Convert Celsius to Fahrenheit
    double fahrenheit = (celsius * 9.0 / 5.0) + 32;

    // Display the result
    cout << "Celsius: " << celsius << " C" << endl;
    cout << "Fahrenheit: " << fahrenheit << " F" << endl;

    return 0;
}
