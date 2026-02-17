#include<bits/stdc++.h>
using namespace std;

int main(){
    string str;
    cin>>str;

    unordered_map<char,int> m;
    for(char c: str){
        m[c]++;
    }

    cout<<"Frequency of characters :- "<<endl;
    for(auto p: m){
        cout<<p.first<<" : "<<p.second<<endl;
    }
    return 0;
}