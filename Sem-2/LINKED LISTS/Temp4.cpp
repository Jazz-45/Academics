# include <iostream>
using namespace std;

int main(){

    int n;
    cout<<"Enter Dimension : ";
    cin>>n;

    int arr1[n][n];
    int arr2[n][n];

    cout<<"Enter Matrix 1: ";
    for (int i = 0; i < n; i++)
    {
        for(int j=0;j<n;j++){
            cin>>arr1[i][j];
        }
    }
    cout<<"Enter Matrix 2: ";
    for (int i = 0; i < n; i++)
    {
        for(int j=0;j<n;j++){
            cin>>arr2[i][j];
        }
    }

    int res1[n][n];
    for (int i = 0; i < n; i++)
    {
        for(int j=0;j<n;j++){
            res1[i][j]=arr1[i][j]+arr2[i][j];
        }
    }
    int res2[n][n];
    for (int i = 0; i < n; i++)
    {
        for(int j=0;j<n;j++){
            res2[i][j]=0;
            for(int k=0;k<n;k++){
                res2[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }
    cout<<"Addition of matrices are : ";
    for (int i = 0; i < n; i++)
    {
        for(int j=0;j<n;j++){
            cout<<res1[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"Multiplication of matrices are : ";
    for (int i = 0; i < n; i++)
    {
        for(int j=0;j<n;j++){
            cout<<res2[i][j]<<" ";
        }
        cout<<endl;
    }
     





    
    return 0;
}