#include <iostream>
#include <iomanip> // for setprecision

using namespace std;

// Define the structure
struct Book {
    string title;
    string author;
    float price;
};

int main() {
    Book books[3];

    for (int i = 0; i < 3; ++i) {
        cout << "Enter details for Book " << i + 1 << ":\n";
        cout << "Title: ";
        getline(cin, books[i].title);
        cout << "Author: ";
        getline(cin, books[i].author);
        cout << "Price: ";
        cin >> books[i].price;
        cin.ignore(); // to consume the newline character left in the input buffer
        cout << endl;
    }

    // Display details for each book
    // for (int i = 0; i < 3; ++i) {
    //     cout << "Details for Book " << i + 1 << ":\n";
    //     cout << "Title: " << books[i].title << "\nAuthor: " << books[i].author << "\nPrice: $" << fixed << setprecision(2) << books[i].price << "\n\n";
    // }

    int mostExpensiveIndex = 0, cheapestIndex = 0;
    for (int i = 1; i < 3; ++i) {
        if (books[i].price > books[mostExpensiveIndex].price) {
            mostExpensiveIndex = i;
        }
        if (books[i].price < books[cheapestIndex].price) {
            cheapestIndex = i;
        }
    }

    // Display the most expensive and cheapest books
    cout << "Most Expensive Book:\n";
    cout << "Title: " << books[mostExpensiveIndex].title << "\nAuthor: " << books[mostExpensiveIndex].author
         << "\nPrice: $" << fixed << setprecision(2) << books[mostExpensiveIndex].price << "\n\n";

    cout << "Cheapest Book:\n";
    cout << "Title: " << books[cheapestIndex].title << "\nAuthor: " << books[cheapestIndex].author
         << "\nPrice: $" << fixed << setprecision(2) << books[cheapestIndex].price << "\n\n";

    return 0;
}

