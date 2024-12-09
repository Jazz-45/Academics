#include<cmath>
#include <iostream>

using namespace std;

int main() {
    // Define variables with assumed values
    double x = 2.0;
    double y = 3.0;
    double a = 5.0;
    double b = 1.0;
    double c = 2.0;
    double d = 4.0;
    double q = 1.0;
    double r = 3.0;
    double m = 2.0;
    double v = 1.0;
    double g = 2.0;

    // Evaluate expressions
    double A = ((pow(x, 2) + 10) * pow(x, 4)) / ((y - 4) * (y - 5));
    double B = ((pow(x-1,3)*(12))/(4*x))+(8*(pow(x+2,2))/(4*x))+((x+8)/(8*x))+(8/(8*x));
    double C = ((((8.8)*(pow(a+b,2)))/(c))-(0.5)+((2*a)/(q+r)))/((a+b)*(1/m));
    double D = (-b +(pow(b, 2)) + 2 * 4 * a * c) / (2 * a);
    double E = ((2*v) + (6.22*(c+d))) / (g + v);
    double F = ((((7.7)*(b)*((x*y)+a))/(c))-(0.8)+(2*b))/((x+a)*(1/y));

    // Display the results
    cout << "Z_a: " << A << endl;
    cout << "Z_b: " << B << endl;
    cout << "Z_c: " << C << endl;
    cout << "X_d: " << D << endl;
    cout << "X_e: " << E << endl;
    cout << "A_f: " << F << endl;

    return 0;
}
