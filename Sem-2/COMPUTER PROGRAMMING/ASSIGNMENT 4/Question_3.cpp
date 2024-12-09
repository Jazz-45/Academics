# include <iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter a number : "<<endl;
    cin>>n;

    int fac=1;

    for (int i = 1; i <=n; i++)
    {
        fac=fac*i;
    }
    cout<<fac;
    
    return 0;
}