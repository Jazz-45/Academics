# include<iostream>
# include<fstream>
using namespace std;

int main(){

    // Creating and opening
    ifstream file("Zoom.txt");

    string text;
    while(getline(file,text)){
        cout<<text;
    }
    
    return 0;
}