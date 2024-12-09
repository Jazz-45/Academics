#include <iostream>

using namespace std;

int main() {
    // Given dimensions
    double length = 11.0;  // in centimeters
    double width = 21.0;   // in centimeters
    double height = 31.0;  // in centimeters

    // Calculating volume and surface area
    double volume = length * width * height;
    double surfaceArea = 2 * (length * width + length * height + width * height);

    // Displaying the results
    cout << "Volume of the cuboid: " << volume << " cubic centimeters" << endl;
    cout << "Surface area of the cuboid: " << surfaceArea << " square centimeters" << endl;

    return 0;
}
