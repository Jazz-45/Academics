# include <iostream>
using namespace std;

int main(){

    int upperbound,lowerbound;
    cout<<"Enter upper bound : "<<endl;
    cin>>upperbound;
    cout<<"Enter lower bound :"<<endl;
    cin>>lowerbound;

    for (int i = lowerbound; i <=upperbound; i++)
    {
        int count=0;
        for (int j = 2; j < i; j++)
        {
            if (i%j==0) count++;
        }
        if (count==0) cout<<i<<" ";
    }
    
    
    return 0;
}