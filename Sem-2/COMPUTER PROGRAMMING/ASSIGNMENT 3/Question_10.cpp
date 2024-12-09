# include <iostream>
using namespace std;

int main(){

    double Hardness,Carbon_content,Tensile_strength;
    cout<<"Enter Hardness : "<<endl;
    cin>>Hardness;
    cout<<"Enter Carbon content : "<<endl;
    cin>>Carbon_content;
    cout<<"Enter Tensile strength : "<<endl;
    cin>>Tensile_strength;

    cout<<"The grade of steel is : ";

    if (Hardness>50){
        if (Carbon_content<0.7){
            if (Tensile_strength>5600) cout<<"10";
            else cout<<"9";
        }
        else {
            if (Tensile_strength>5600) cout<<"7";
            else cout<<"6";  
        }
    }
    else {
        if (Carbon_content<0.7){
            if (Tensile_strength>5600) cout<<"8";
            else cout<<"6";
        }
        else{
            if (Tensile_strength>5600) cout<<"6";
            else cout<<"5";
        }
    }
    return 0;
}