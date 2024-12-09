# include <iostream>
using namespace std;

int main(){

    char ch;
    cout<<"Enter a character: ";
    cin>>ch;
    int var=(int)ch;
    if ((65<=var && var<=90)||(97<=var && var<=122))
    {
        if (var==65 || var==69 || var==73 || var ==79 || var==85)
        {
            cout<<"Vowel";
        }
        else if (var==97 || var==101 || var==105 || var ==111 || var==117)
        {
            cout<<"Vowel";
        }
        else cout<<"Consonant";
        
    }
    else cout<<"Invalid English alphabet";
    
    return 0;
}