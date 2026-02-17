#include<bits/stdc++.h>
using namespace std;

char mat[5][5];
map<char,pair<int,int>>pos;

// Generate matrix
void genMat(string key){
    string s="";
    set<char>used;

    for(char c:key){
        if(c=='J') c='I';
        if(!used.count(c)){
            used.insert(c);
            s+=c;
        }
    }

    for(char c='A';c<='Z';c++){
        if(c=='J') continue;
        if(!used.count(c)) s+=c;
    }

    int k=0;
    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++){
            mat[i][j]=s[k];
            pos[s[k]]={i,j};
            k++;
        }
}

// Encrypt
string encryptPF(string t){
    string c="";

    for(int i=0;i<t.size();i+=2){
        auto a=pos[t[i]], b=pos[t[i+1]];

        if(a.first==b.first){
            c+=mat[a.first][(a.second+1)%5];
            c+=mat[b.first][(b.second+1)%5];
        }
        else if(a.second==b.second){
            c+=mat[(a.first+1)%5][a.second];
            c+=mat[(b.first+1)%5][b.second];
        }
        else{
            c+=mat[a.first][b.second];
            c+=mat[b.first][a.second];
        }
    }
    return c;
}

// Decrypt
string decryptPF(string t){
    string p="";

    for(int i=0;i<t.size();i+=2){
        auto a=pos[t[i]], b=pos[t[i+1]];

        if(a.first==b.first){
            p+=mat[a.first][(a.second+4)%5];
            p+=mat[b.first][(b.second+4)%5];
        }
        else if(a.second==b.second){
            p+=mat[(a.first+4)%5][a.second];
            p+=mat[(b.first+4)%5][b.second];
        }
        else{
            p+=mat[a.first][b.second];
            p+=mat[b.first][a.second];
        }
    }
    return p;
}

int main(){
    string key,pt;
    cout<<"Key: ";
    cin>>key;
    cout<<"Plaintext: ";
    cin>>pt;

    genMat(key);

    string ct=encryptPF(pt);
    string dt=decryptPF(ct);

    cout<<"Encrypted: "<<ct<<endl;
    cout<<"Decrypted: "<<dt;
}
