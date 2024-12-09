# include <iostream>
using namespace std;

void sort(int a[], int n){

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[j]>a[j+1]) 
            {
                swap(a[j], a[j+1]);
            }
        }
    }
    
}

int main(){

    int n;
    cout<<"Enter no of elements in array : "<<endl;
    cin>>n;

    int arr[n];
    cout<<"Enter "<<n<<" elements"<<endl;
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    
    sort(arr,n);
    cout<<"Sorted array : "<<endl; 
    
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
    
}