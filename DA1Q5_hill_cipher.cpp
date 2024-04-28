#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    string str;
    
    str = "BCA";
    
    int kmat[3][3] = {
        {6, 24, 1},
        {13, 16, 10},
        {20, 17, 15}
    };
    
    int invkmat[3][3] = {
        {8, 5, 10},
        {21, 8, 21},
        {21, 12, 8}
    };
    
    int inarr[1][str.length()];
    
    for (int i=0; i<str.length(); i++){
        inarr[0][i] = (int)str[i]-65;
    }
    
    int CT[1][3];
    
    for (int i=0; i<3; i++){
        CT[0][i] = (inarr[0][0]*kmat[i][0] + inarr[0][1]*kmat[i][1] + inarr[0][2]*kmat[i][2])%26 + 65;
    }
    
    for (int i=0; i<str.length(); i++){
        cout<<char(CT[0][i]);
    }
    
    cout<<endl;
    
    int PT[1][3];
    
    for (int i=0; i<3; i++){
        PT[0][i] = ((CT[0][0]-65)*invkmat[i][0] + (CT[0][1]-65)*invkmat[i][1] + (CT[0][2]-65)*invkmat[i][2])%26 + 65;
    }
    
    for (int i=0; i<str.length(); i++){
        cout<<char(PT[0][i]);
    }
    
    return 0;
}