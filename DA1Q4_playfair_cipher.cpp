#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

int mat[5][5];

vector<int> findp(int a){
    vector<int> vec;
    for (int i=0; i<5; i++){
        for (int j=0; j<5; j++){
            if (mat[i][j]==a){
                vec.push_back(i);
                vec.push_back(j);
                return vec;
            }
        }
    }
    vec.push_back(0);
    vec.push_back(0);
    return vec;
}

int main()
{
    string str = "confidentiality";
    string key = "kite";

    int karr[key.length()];
    
    for (int i=0; i<key.length(); i++){
        karr[i] = key[i]-97;
    }
    
    vector<int> zarr;
    for (int i=0; i<9; i++){
        zarr.push_back(i);
    }
    for (int i=10; i<26; i++){
        zarr.push_back(i);
    }
    
    for (int i=0; i<9; i++){
        for (int j=0; j<key.length(); j++){
            if (karr[j]==i){
                zarr[i] = -1;
                break;
            }
        }
    }
    for (int i=10; i<26; i++){
        for (int j=0; j<key.length(); j++){
            if (karr[j]==i){
                zarr[i-1] = -1;
                break;
            }
        }
    }
    
    vector<int> arr;
    
    for (int i=0; i<key.length(); i++){
        arr.push_back(karr[i]);
    }
    
    for (int i=0; i<zarr.size(); i++){
        if (zarr[i]!=-1){
            arr.push_back(zarr[i]);
        }
    }
    
    int m=0;
    for (int i=0; i<5; i++){
        for (int j=0; j<5; j++){
            mat[i][j] = arr[m];
            m++;
        }   
    }
    
    if (str.length()%2==1){
        str += 'z';
    }
    
    string CT = "";
    
    for (int i=0; i<str.length()-1; i+=2){
        int e1=str[i]-97,e2=str[i+1]-97;
        vector<int> pos1,pos2;
        pos1 = findp(e1);
        pos2 = findp(e2);
        int ch;
        if (pos1[0]==pos2[0]){
            ch = 0;
            pos1[1]++;
            pos2[1]++;
            if (pos1[1]>4){
                pos1[1]=0;
            }
            if (pos2[1]>4){
                pos2[1]=0;
            }
        }
        else if(pos1[1]==pos2[1]){
            ch = 1;
            pos1[0]++;
            pos2[0]++;
            if (pos1[0]>4){
                pos1[0]=0;
            }
            if (pos2[0]>4){
                pos2[0]=0;
            }
        }
        else{
            ch = 2;
            int t=pos1[1];
            pos1[1] = pos2[1];
            pos2[1] = t;
        }
        CT += char(mat[pos1[0]][pos1[1]]+97);
        CT += char(mat[pos2[0]][pos2[1]]+97);
    }
    
    cout<<CT<<endl;

    // Decryption
    
    string PT = "";
    
    for (int i=0; i<CT.length()-1; i+=2){
        int e1=CT[i]-97,e2=CT[i+1]-97;
        vector<int> pos1,pos2;
        pos1 = findp(e1);
        pos2 = findp(e2);
        int ch;
        if (pos1[0]==pos2[0]){
            ch = 0;
            pos1[1]--;
            pos2[1]--;
            if (pos1[1]<0){
                pos1[1]=4;
            }
            if (pos2[1]<0){
                pos2[1]=4;
            }
        }
        else if(pos1[1]==pos2[1]){
            ch = 1;
            pos1[0]--;
            pos2[0]--;
            if (pos1[0]<0){
                pos1[0]=4;
            }
            if (pos2[0]<0){
                pos2[0]=4;
            }
        }
        else{
            ch = 2;
            int t=pos1[1];
            pos1[1] = pos2[1];
            pos2[1] = t;
        }
        PT += char(mat[pos1[0]][pos1[1]]+97);
        PT += char(mat[pos2[0]][pos2[1]]+97);
    }
    
    cout<<PT;
    
    return 0;
}