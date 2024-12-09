#include <iostream>

using namespace std;

// Define the structure
struct Employee {
    string name;
    int id;
    float salary;
};

int main() {
    Employee employees[3];

    // Input details for each employee
    for (int i = 0; i < 3; ++i) {
        cout << "Enter details for Employee " << i + 1 << ":\n";
        cout << "Name: ";
        getline(cin, employees[i].name);
        cout << "ID: ";
        cin >> employees[i].id;
        cout << "Salary: $";
        cin >> employees[i].salary;
        cin.ignore(); // to consume the newline character left in the input buffer
        cout << endl;
    }

    // // Display details for each employee
    // for (int i = 0; i < 3; ++i) {
    //     cout << "Details for Employee " << i + 1 << ":\n";
    //     cout << "Name: " << employees[i].name << "\nID: " << employees[i].id << "\nSalary: $" << employees[i].salary << "\n\n";
    // }

    // Find the employee with the highest salary
    int high = 0;
    for (int i = 1; i < 3; ++i) {
        if (employees[i].salary > employees[high].salary) {
            high = i;
        }
    }

    // Display information for the employee with the highest salary
    cout << "Employee with the Highest Salary:\n";
    cout << "Name: " << employees[high].name << "\nID: " << employees[high].id
         << "\nSalary: $" << employees[high].salary << "\n";

    return 0;
}
