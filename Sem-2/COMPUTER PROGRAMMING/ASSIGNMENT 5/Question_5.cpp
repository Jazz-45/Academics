# include <iostream>
using namespace std;

int smallest(int a[], int n){
    int min=INT16_MAX;
    for (int i = 0; i < n; i++)
    {
        if(a[i]<min) min=a[i];
    }
    return min;
}

int main(){

    int n;
    cout<<"Enter the size of array : "<<endl;
    cin>>n;

    int arr[n];
    cout<<"Enter the elements of array: "<<endl;
    for (int i = 0; i <n; i++)
    {
        cin>>arr[i];
    }
    cout<<"The smallest elements is : "<<smallest(arr,n);
    
    return 0;
}