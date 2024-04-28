#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    string str;
    int key;
    
    getline(cin,str);
    cin>>key;
    
    string ct="",pt="";
    
    for (int i=0; i<str.length(); i++){
        if (str[i]==' '){
            ct += " ";
        }
        else{
            ct += char(str[i]+key);
        }
    }
    
    for (int i=0; i<ct.length(); i++){
        if (ct[i]==' '){
            pt += " ";
        }
        else{
            pt += char(ct[i]-key);
        }
    }
    
    cout<<ct<<endl<<pt;
    
    
    return 0;
}