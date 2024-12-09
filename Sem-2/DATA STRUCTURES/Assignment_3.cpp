#include <iostream>

using namespace std;

// Function to swap two numbers using call by value
void swapByValue(int num1, int num2) {
    int temp = num1;
    num1 = num2;
    num2 = temp;

    cout << "Inside swapByValue function:\n";
    cout << "Swapped values: num1 = " << num1 << ", num2 = " << num2 << "\n\n";
}

// Function to swap two numbers using call by reference
void swapByReference(int &num1, int &num2) {
    int temp = num1;
    num1 = num2;
    num2 = temp;

    cout << "Inside swapByReference function:\n";
    cout << "Swapped values: num1 = " << num1 << ", num2 = " << num2 << "\n\n";
}

int main() {
    int a=5, b=11;

    // // Input two numbers
    // cout << "Enter the value of a: ";
    // cin >> a;
    // cout << "Enter the value of b: ";
    // cin >> b;

    // Display original values
    cout << "\nOriginal values: a = " << a << ", b = " << b << "\n\n";

    // Swap by value
    swapByValue(a, b);

    // Display values after swap by value (values in the main function are not changed)
    cout << "Back in the main function (after swapByValue):\n";
    cout << "Original values: a = " << a << ", b = " << b << "\n\n";

    // Swap by reference
    swapByReference(a, b);

    // Display values after swap by reference (values in the main function are changed)
    cout << "Back in the main function (after swapByReference):\n";
    cout << "Swapped values: a = " << a << ", b = " << b << "\n";

    return 0;
}
