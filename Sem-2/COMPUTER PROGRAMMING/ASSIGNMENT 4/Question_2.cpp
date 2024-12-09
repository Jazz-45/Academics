# include <iostream>
using namespace std;

int main(){
    int i=0;
    while (i<=255)
    {
        char ch=(char)i;
        cout<<i<<" : "<<ch<<endl;
        i++;
    }
    return 0;
}