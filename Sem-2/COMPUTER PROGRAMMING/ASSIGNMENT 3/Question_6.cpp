#include <iostream>

using namespace std;

int main() {
    int fiveDigitNumber;

    // Input a five-digit number
    cout << "Enter a five-digit number: ";
    cin >> fiveDigitNumber;

    // Ensure the input is a five-digit number

        // Calculate the sum of the digits without using a loop
        int digit5 = fiveDigitNumber % 10;
        fiveDigitNumber /= 10;
        int digit4 = fiveDigitNumber % 10;
        fiveDigitNumber /= 10;
        int digit3 = fiveDigitNumber % 10;
        fiveDigitNumber /= 10;
        int digit2 = fiveDigitNumber % 10;
        fiveDigitNumber /= 10;
        int digit1 = fiveDigitNumber % 10;

        // Calculate the sum of the digits
        int sum = digit1 + digit2 + digit3 + digit4 + digit5;

        // Output the result
        cout << "Sum of the digits: " << sum << endl;
    

    return 0;
}
