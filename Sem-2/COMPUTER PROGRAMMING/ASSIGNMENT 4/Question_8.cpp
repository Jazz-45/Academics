# include <iostream>
using namespace std;

int main(){

    int base,power;
    cout<<"Enter Base : "<<endl;
    cin>>base;
    cout<<"Enter Power : "<<endl;
    cin>>power;
    int res=1;

    for (int i = 1; i <= power; i++) res*=base;
    
    cout<<res;
    
    return 0;
}