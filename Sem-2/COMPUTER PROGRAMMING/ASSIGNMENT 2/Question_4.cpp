#include <iostream>
using namespace std;

int main() {
    
    double distances[4] = {5.0, 10.0, 15.0, 50.0};
    double meters[4],centimeters[4],feet[4],inches[4];

    for (int i=0; i<4; i++)
    {
        meters[i]=distances[i]*1000;
        centimeters[i]=distances[i]*1000*100;
        feet[i]=distances[i]*3280.839;
        inches[i]=distances[i]*39370.078;
    }
    
    for (int i=0; i<4; i++)
    {
        cout<<"Distance in kilometers: "<<distances[i]<<endl;
        cout<<"Distance in meters: "<<meters[i]<<endl;
        cout<<"Distance in centimeters: "<<centimeters[i]<<endl;
        cout<<"Distance in feet: "<<feet[i]<<endl;
        cout<<"Distance in inches: "<<inches[i]<<endl<<endl;
    }
    

    return 0;
}
