#include <iostream>

using namespace std;

int main() {
    int deepakAge, ajitAge, vivekAge;

    // Input ages from the keyboard
    cout << "Enter Deepak's age: ";
    cin >> deepakAge;

    cout << "Enter Ajit's age: ";
    cin >> ajitAge;

    cout << "Enter Vivek's age: ";
    cin >> vivekAge;

    // Determine the youngest among Deepak, Ajit, and Vivek
    if (deepakAge < ajitAge && deepakAge < vivekAge) {
        cout << "Deepak is the youngest." << endl;
    } else if (ajitAge < deepakAge && ajitAge < vivekAge) {
        cout << "Ajit is the youngest." << endl;
    } else {
        cout << "Vivek is the youngest." << endl;
    }

    return 0;
}
