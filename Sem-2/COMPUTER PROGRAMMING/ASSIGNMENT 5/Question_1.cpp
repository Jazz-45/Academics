# include <iostream>
using namespace std;

int gcd(int a, int b){
    if(b==0) return a;
    else return gcd(b,a%b);
}

int main(){

    int a,b;
    cout<<"Enter the number a and b : "<<endl;
    cin>>a>>b;

    cout<<"The GCD is : "<<gcd(a,b);
    return 0;
}