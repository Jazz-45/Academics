#include <iostream>

using namespace std;

int main() {

    // Total population
    int total_population=80000;
    // Given percentages
    double percentageMen = 52.0;
    double totalLiteracy = 48.0;
    double literateMenPercentage = 35.0;

    // Calculate percentages for women
    double percentageWomen = 100 - percentageMen;
    double totalilliteracy = 100 - totalLiteracy;

    // Calculate number of men,women, literate and illiterate
    int total_men=(percentageMen/100)*total_population;
    int illiterate_population=(totalilliteracy/100)*total_population;
    int literate_men=(literateMenPercentage/100)*total_population;
    int illiterate_men=total_men-literate_men;
    int illiterate_women=illiterate_population-illiterate_men;


    // Output the results
    cout << "Total number of illiterate men: " << illiterate_men << endl;
    cout << "Total number of illiterate women: "<< illiterate_women << endl;

    return 0;
}

