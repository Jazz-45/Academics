#include<bits/stdc++.h>
using namespace std;

string encryp(string& str){
    string result="";
    for(char c: str){
        result+=char((c-'a' + 3)%26+'a');
    }
    return result;
}

string decrypt(string& str){
    string result="";
    for(char c: str){
        result+=char((c-'a'-3+26)%26+'a');
    }
    return result;
}

int main(){
    string str;
    cout<<"Enter a string to encode :-"<<endl;
    cin>>str;

    string encrypted=encryp(str);
    cout<<"Encrypted String: "<<encrypted<<endl;

    string decrypted=decrypt(encrypted);
    cout<<"Decrypted String: "<<decrypted<<endl;
    
    return 0;
}