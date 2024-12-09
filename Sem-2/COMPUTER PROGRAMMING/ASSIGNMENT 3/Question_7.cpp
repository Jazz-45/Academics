#include <iostream>

using namespace std;

int main() {
    int fiveDigitNumber;

    // Input a five-digit number
    cout << "Enter a five-digit number: ";
    cin >> fiveDigitNumber;
    // Reverse the five-digit number without using a loop
    int digit5 = fiveDigitNumber % 10;
    fiveDigitNumber /= 10;
    int digit4 = fiveDigitNumber % 10;
    fiveDigitNumber /= 10;
    int digit3 = fiveDigitNumber % 10;
    fiveDigitNumber /= 10;
    int digit2 = fiveDigitNumber % 10;
    fiveDigitNumber /= 10;
    int digit1 = fiveDigitNumber % 10;

    // Calculate the reversed number
    int reversedNumber = digit5 * 10000 + digit4 * 1000 + digit3 * 100 + digit2 * 10 + digit1;

    // Output the reversed number
    cout << "Reversed number: " << reversedNumber << endl;
    

    return 0;
}
