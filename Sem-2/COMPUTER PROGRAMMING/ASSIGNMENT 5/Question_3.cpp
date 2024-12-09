# include <iostream>
using namespace std;

int expo(int a, int b){
    if(b==0) return 1;
    else if(a==0) return 0;
    else return a*expo(a,b-1);
}

int main(){

    int base,power;
    cout<<"Enter base : "<<endl;
    cin>>base;
    cout<<"Enter power: "<<endl;
    cin>>power;

    cout<<"The exponent is: "<<expo(base, power);
    return 0;
}