#include <iostream>
#include <iomanip>
using namespace std;

struct Student {
    string name;
    int age;
    float totalMarks;
};

int main() {
    // Declare two instances of the Student structure
    Student s1, s2;

    // Input data for the first student
    cout << "Enter data for Student 1:\n";
    cout << "Name: ";
    getline(cin, s1.name);
    cout << "Age: ";
    cin >> s1.age;
    cout << "Total Marks: ";
    cin >> s1.totalMarks;
    cin.ignore(); // to consume the newline character left in the input buffer

    // Input data for the second student
    cout << "\nEnter data for Student 2:\n";
    cout << "Name: ";
    getline(cin, s2.name);
    cout << "Age: ";
    cin >> s2.age;
    cout << "Total Marks: ";
    cin >> s2.totalMarks;

    // Display information for both students
    cout << "\nInformation for Student 1:\n";
    cout << "Name: " << s1.name << "\nAge: " << s1.age << "\nTotal Marks: " << s1.totalMarks << "\n\n";

    cout << "Information for Student 2:\n";
    cout << "Name: " << s2.name << "\nAge: " << s2.age << "\nTotal Marks: " << s2.totalMarks << "\n\n";

    // Calculate and display average marks
    float averageMarks = (s1.totalMarks + s2.totalMarks) / 2.0;
    cout << "Average Marks: " << fixed << setprecision(2) << averageMarks << endl;

    return 0;
}