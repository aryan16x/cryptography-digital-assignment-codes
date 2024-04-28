#include <iostream>
#include <string.h>

using namespace std;

string genkey(string key, int len){
    string genk="";
    for (int i=0; i<len; i++){
        for (int j=0; j<key.length() & genk.length()<len; j++){
            genk += key[j];
        }
    }
    
    return genk;
}

int main()
{
    string str;
    string key;
    
    // getline(cin,str);
    // getline(cin,key);
    
    str = "rendezvous";
    key = "ace";
    
    string cipher="";
    
    string genk = genkey(key,str.length());
    
    for (int i=0; i<str.length(); i++){
        int x1 = str[i]-97;
        int x2 = genk[i]-97;
        cipher += char(((x1+x2)%26)+97);
    }
    
    string dx="";
    str = cipher;
    
    for (int i=0; i<str.length(); i++){
        int x1 = str[i]-97;
        int x2 = genk[i]-97;
        int x = x1-x2;
        if (x<0){
            x =+ 26;
        }
        dx += char((x%26)+97);
    }
    
    cout<<"Generated Key: "<<genk<<endl;
    cout<<"Cipher: "<<cipher<<endl;
    cout<<"dx: "<<dx;

    return 0;
}
