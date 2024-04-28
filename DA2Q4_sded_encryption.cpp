#include <iostream>
#include <vector>

using namespace std;

vector<int> ep = {4,1,2,3,2,3,4,1};
vector<int> ip = {2,6,3,1,4,8,5,7};
vector<int> p4 = {2,4,3,1};
vector<vector<int>> s0m = {{1, 0, 3, 2}, {3, 2, 1, 0}, {0, 2, 1, 3}, {3, 1, 3, 2}};
vector<vector<int>> s1m = {{0, 1, 2, 3}, {2, 0, 1, 3}, {3, 0, 1, 0}, {2, 1, 0, 3}};

vector<int> perip(vector<int> pt){
    vector<int> result;
    
    for (int i=0; i<8; i++){
        result.push_back(pt[ip[i]-1]);
    }
    
    return result;
}

vector<int> perep(vector<int> pt){
    vector<int> result;
    
    for (int i=0; i<8; i++){
        result.push_back(pt[ep[i]-1]);
    }
    
    return result;
}

vector<int> perp4(vector<int> pt){
    vector<int> result;
    
    for (int i=0; i<4; i++){
        result.push_back(pt[p4[i]-1]);
    }
    
    return result;
}

int gensval(int a, int b){
    if (a==0 & b==0){
        return 0;
    }
    else if (a==1 & b==0){
        return 2;
    }
    else if (a==0 & b==1){
        return 1;
    }
    else{
        return 3;
    }
    
    return 0;
}

int main()
{
    string str;
    string k1str,k2str;
    
    str = "00101000";
    k1str = "11101001";
    k2str = "10100111";
    
    vector<int> pt,k1,k2;
    
    for (int i=0; i<str.length(); i++){
        pt.push_back(int(str[i])-48);
        k1.push_back(int(k1str[i])-48);
        k2.push_back(int(k2str[i])-48);
    }
    
    vector<int> afip = perip(pt);
    
    int a=0,b=4,c=8;
    
    vector<int> afip1(afip.begin()+a, afip.begin()+b);
    vector<int> afip2(afip.begin()+b, afip.begin()+c);
    
    vector<int> afep = perep(afip2);
    
    vector<int> epk1;
    
    for (int i=0; i<8; i++){
        epk1.push_back(afep[i]^k1[i]);
    }
    
    vector<int> s0(epk1.begin()+a, epk1.begin()+b);
    vector<int> s1(epk1.begin()+b, epk1.begin()+c);
    
    int s0x[2],s1x[2];
    
    s0x[0] = gensval(s0[0],s0[3]);
    s0x[1] = gensval(s0[1],s0[2]);
    s1x[0] = gensval(s1[0],s1[3]);
    s1x[1] = gensval(s1[1],s1[2]);
    
    int s0d = s0m[s0x[0]][s0x[1]];
    int s1d = s1m[s0x[0]][s1x[1]];

    vector<int> s0s1;
    
    if (s0d==0){
        s0s1.push_back(0);
        s0s1.push_back(0);
    }
    else if (s0d==1){
        s0s1.push_back(0);
        s0s1.push_back(1);
    }
    else if (s0d==2){
        s0s1.push_back(1);
        s0s1.push_back(0);
    }
    else {
        s0s1.push_back(1);
        s0s1.push_back(1);
    }
    
    if (s1d==0){
        s0s1.push_back(0);
        s0s1.push_back(0);
    }
    else if (s1d==1){
        s0s1.push_back(0);
        s0s1.push_back(1);
    }
    else if (s1d==2){
        s0s1.push_back(1);
        s0s1.push_back(0);
    }
    else {
        s0s1.push_back(1);
        s0s1.push_back(1);
    }
    
    vector<int> afp4 = perp4(s0s1);

    vector<int> afp4xor;
    
    for (int i=0; i<4; i++){
        afp4xor.push_back(afp4[i]^s0s1[i]^afip1[i]);
    }
    
    vector<int> CT;
    
    for (int i=0; i<4; i++){
        CT.push_back(afip2[i]);
    }
    for (int i=0; i<4; i++){
        CT.push_back(afp4xor[i]);
    }
    
    for (int i=0; i<8; i++){
        cout<<CT[i]<<" ";
    }
    
    return 0;
}
