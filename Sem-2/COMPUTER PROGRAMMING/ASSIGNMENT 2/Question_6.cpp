#include <iostream>
#include <iomanip> 

using namespace std;

int main() {
    // Input two float numbers
    float num1, num2;

    cout << "Enter the first number:\n";
    cin >> num1;

    cout << "Enter the second number:\n";
    cin >> num2;

    float sum = num1 + num2;

    cout << fixed << setprecision(5);

    cout << "The sum is:\n" << sum << endl;

    return 0;
}
