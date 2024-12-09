# include <iostream>
using namespace std;

int linear_search(int a[], int n, int key){
    for (int i = 0; i < n; i++){
        if(a[i]==key) return i;
    }
    return -1;
}

int main(){

    int n;
    cout<<"Enter no of elements in array : "<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter "<<n<<" elements"<<endl;
    for (int i = 0; i < n; i++){
        cin>>arr[i];
    }
    int key;
    cout<<"Enter the number to be searched : "<<endl;
    cin>>key;

    int ans=linear_search(arr,n,key);
    if (ans != -1) cout<<"The number is present at index no. "<<ans;
    else  cout<<"Entered no is not present in array";
    
    return 0;
}