# include <iostream>
using namespace std;

int main(){

    int n;
    cout<<"Enter a number : ";
    cin>>n;
    int res=0;

    for (int i = 1; i < n; i++)
    {
        if (n%i==0) res+=i;
    }
    if(res==n) cout<<n<<" is a perfect number";
    else cout<<n<<" is not a perfect number";
    
    return 0;
}