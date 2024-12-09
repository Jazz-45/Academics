# include <iostream>
using namespace std;

int main(){

    char ch;
    cout<<"Enter a character: ";
    cin>>ch;
    int var=(int)ch;
    if(65<= var && var<=90) cout<<"Upper Case";
    else if(97<=var && var<=122) cout<<"Lower case";
    else cout<<"Invalid English alphabet";
    return 0;
}