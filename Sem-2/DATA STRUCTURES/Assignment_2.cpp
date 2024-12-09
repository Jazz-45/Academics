# include <iostream>
using namespace std;

int main(){

    int n;
    cout<<"Enter order of the square matrix : "<<endl;
    cin>>n;

    int matrix[n][n];

    cout<<"Enter elements of matrix : "<<endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin>>matrix[i][j];
        }
        
    }
    
    

    return 0;
}