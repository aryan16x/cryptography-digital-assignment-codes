#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;


int main()
{
    string str;
    string key;
    
    str = "Apple is fresh";
    key = "heal";
    
    string keydup = key;
    
    int row = str.length()/key.length() + 1;
    
    char mat[row][key.length()];
    
    int k=0;
    for (int i=0; i<row; i++){
        for (int j=0; j<key.length(); j++){
            mat[i][j] = str[k];
            k++;
        }
    }
    
    string CT = "";
    
    sort(key.begin(), key.end());
    
    int arr[key.length()];
    
    int p=0;
    for (int i=0; i<key.length(); i++){
        for (int j=0; j<key.length(); j++){
            if (key[i] == keydup[j]){
                arr[p] = j;
                p++;
            }
        }
    }

    for (int i=0; i<4; i++){
        for (int j=0; j<key.length(); j++){
            CT += mat[j][arr[i]];
        }
    }
    
    k=0;
    for (int i=0; i<row; i++){
        for (int j=0; j<key.length(); j++){
            cout<<mat[i][j]<<" ";
            k++;
        }
        cout<<endl;
    }
    
    cout<<CT<<" "<<CT.length();
    
    
    // Decryption
    cout<<endl<<"Decryption"<<endl;
    
    k=0;
    for (int i=0; i<row; i++){
        for (int j=0; j<key.length(); j++){
            mat[j][i] = CT[k];
            k++;
        }
    }
    
    string PT = "";
    
    k=0;
    for (int i=0; i<row; i++){
        for (int j=0; j<key.length(); j++){
            cout<<mat[i][j]<<" ";
            k++;
        }
        cout<<endl;
    }
    
    for (int i=0; i<4; i++){
        for (int j=0; j<key.length(); j++){
            PT += mat[i][arr[j]];
        }
    }
    
    cout<<PT;
    

    return 0;
}
