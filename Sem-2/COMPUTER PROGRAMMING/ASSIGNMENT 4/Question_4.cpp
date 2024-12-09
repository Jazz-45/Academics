# include <iostream>
using namespace std;

int main(){

    int n;
    cout<<"Enter a number : "<<endl;
    cin>>n;
    int m=n;
    int reverse=0;
    while (n!=0)
    {
        int digit=n % 10;
        reverse=(reverse*10)+digit;
        n=n/10;
    }
    if (reverse==m)
    {
        cout<<"The number is a palindrome";
    }
    else cout<<"The number is not a palindrome";

    return 0;
}