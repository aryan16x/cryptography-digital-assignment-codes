#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int rcon[4] = {0x84, 0x68, 0x2d, 0xe0};
    int srk[4][4] = {
        {0x56, 0xc7, 0x76, 0xa0},
        {0x08, 0x1a, 0x43, 0x3a},
        {0x20, 0xb1, 0x55, 0xf7},
        {0x07, 0x8f, 0x69, 0xfa}
    };
    
    // cin>>std:hex<<inx;
    
    int res[4][4];
    
    for (int i=0; i<4; i++){
        res[i][0] = srk[i][0]^rcon[i];
    }
    
    for (int i=0; i<4; i++){
        for (int j=1; j<4; j++){
            res[i][j] = srk[i][j]^res[i][j-1];
        }
    }
    
    for (int i=0; i<4; i++){
        for (int j=0; j<4; j++){
            // cout<<"0x"<<std::hex<<output[i][j];
            printf("0x%02X ", res[i][j]);
        }
        cout<<endl;
    }
    
    
    return 0;
}