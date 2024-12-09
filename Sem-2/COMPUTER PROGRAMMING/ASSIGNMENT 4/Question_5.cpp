# include <iostream>
using namespace std;

int main(){

    int n;
    cin>>n;

    cout<<"The factors are : "<<endl;
    for (int i = 1; i < n; i++)
        if (n%i==0) cout<<i<<" ";
    return 0;
}