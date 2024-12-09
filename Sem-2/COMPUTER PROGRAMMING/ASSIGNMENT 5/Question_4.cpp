# include <iostream>

using namespace std;

void largest(int a[], int n){
    int max=INT16_MIN;
    for (int i = 0; i < n; i++)
    {
        if(a[i]>max) max=a[i];
    }
    cout<<"The largest element is : "<<max;
}

int main(){

    int n;
    cout<<"Enter the size of array : "<<endl;
    cin>>n;

    int arr[n];
    cout<<"Enter the elements of array: "<<endl;
    for (int i = 0; i <n; i++) cin>>arr[i];
    largest(arr,n);
    
    return 0;
}