# include <iostream>
# include <cmath>
using namespace std;

void print_array( double a[], int n){
    for (int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }
}

void double_array( double a[] , int n){
    for (int i = 0; i < n; i++){
        a[i]=a[i]*2;
    }
    print_array(a,n);
    cout<<endl;
}
void square_array(double a[], int n){
    for (int i = 0; i < n; i++){
        a[i]=pow(a[i],2);
    }
    print_array(a,n);
    cout<<endl;
}
void cuberoot_array(double a[], int n){
    for (int i = 0; i < n; i++){
        a[i]=cbrt(a[i]);
    }
    print_array(a,n);
    cout<<endl;
}

int main(){

    double arr1[5]={1,2,3,4,5};
    cout<<"Double of Array elements : "<<endl;
    double_array(arr1,5);

    double arr2[5]={1,2,3,4,5};
    cout<<"Square of Array elements : "<<endl;
    square_array(arr2,5);

    double arr3[5]={1,2,3,4,5};
    cout<<"Cube root of Array elements : "<<endl;
    cuberoot_array(arr3,5);

    return 0;

}