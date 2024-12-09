# include<iostream>
# include<fstream>
using namespace std;

int main(){

    // Creating and opening
    ofstream file;
    file.open("Zoom.txt");

    // Writing
    file<<"Hello India\n";
    file.close();

    // readding;
    
    return 0;
}