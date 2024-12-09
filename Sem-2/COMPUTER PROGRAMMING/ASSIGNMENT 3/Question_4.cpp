#include <iostream>
#include <iomanip>  // To set the precision for displaying currency values

using namespace std;

int main() {
    // Input Ramesh's basic salary
    double basicSalary;
    cout << "Enter Ramesh's basic salary in Rupees: ";
    cin >> basicSalary;

    // Calculate dearness allowance (40% of basic salary)
    double dearnessAllowance = 0.4 * basicSalary;

    // Calculate house rent allowance (20% of basic salary)
    double houseRentAllowance = 0.2 * basicSalary;

    // Calculate gross salary
    double grossSalary = basicSalary + dearnessAllowance + houseRentAllowance;

    // Set precision for displaying currency values
    
    cout << "Gross Salary: Rs " << grossSalary << endl;

    return 0;
}
