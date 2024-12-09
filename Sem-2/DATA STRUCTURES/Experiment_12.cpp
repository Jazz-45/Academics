#include <iostream>
#include <limits> // for numeric_limits

using namespace std;
struct Car {
    string carId;
    string model;
    float rentPerDay;
};

int main() {
    Car cars[3];

    // Input details for each car
    for (int i = 0; i < 3; ++i) {
        cout << "Enter details for Car " << i + 1 << ":\n";
        cout << "Car ID: ";
        getline(cin, cars[i].carId);
        cout << "Model: ";
        cin.ignore();
        getline(cin, cars[i].model);
        cout << "Rent per Day: ";
        cin >> cars[i].rentPerDay;
        cin.ignore(); // to consume the newline character left in the input buffer
        cout << endl;
    }

    // // Display details for each car
    // for (int i = 0; i < 3; ++i) {
    //     cout << "Details for Car " << i + 1 << ":\n";
    //     cout << "Car ID: " << cars[i].carId << "\nModel: " << cars[i].model << "\nRent per Day: $" << cars[i].rentPerDay << "\n\n";
    // }

    // Ask the user to select a car
    int selectedCar;
    do {
        cout << "Select a car (1-" << 3 << "): ";
        cin >> selectedCar;
    } while (selectedCar < 1 || selectedCar > 3);

    // Ask the user to choose the number of days
    int numDays;
    cout << "Enter the number of days for rental: ";
    cin >> numDays;

    // Calculate and display the total cost for the selected car
    float totalCost = cars[selectedCar - 1].rentPerDay * numDays;
    cout << "\nTotal Cost for Car " << selectedCar << " for " << numDays << " days: $" << totalCost << "\n";

    return 0;
}

