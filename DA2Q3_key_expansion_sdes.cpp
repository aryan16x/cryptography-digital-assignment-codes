#include <iostream>
#include <vector>

using namespace std;

vector<int> p10 = {3,5,2,7,4,10,1,9,8,6};
vector<int> p8 = {6,3,7,4,8,5,10,9};

vector<int> per10(vector<int> arr){
    vector<int> result;
    
    for (int i=0; i<10; i++){
        result.push_back(arr[p10[i]-1]);
    }
    
    return result;
}

vector<int> per8(vector<int> arr){
    vector<int> result;
    
    for (int i=0; i<8; i++){
        result.push_back(arr[p8[i]-1]);
    }
    
    return result;
}

vector<int> rotArr(vector<int> arr, int k){
    vector<int> result;
    
    for (int i=k; i<arr.size(); i++){
        result.push_back(arr[i]);
    }
    
    for (int i=0; i<k; i++){
        result.push_back(arr[i]);
    }
    
    return result;
}

int main()
{
    string str;
    
    str = "1100011110";
    
    vector<int> arr;
    
    for (int i=0; i<str.length(); i++){
        arr.push_back(int(str[i])-48);
    }
    
    vector<int> p10per = per10(arr);
    
    int a=0,b=5,c=10;
    
    vector<int> k1p1(p10per.begin()+a, p10per.begin()+b);
    vector<int> k1p2(p10per.begin()+b, p10per.begin()+c);
    
    vector<int> k1p1rot = rotArr(k1p1, 1);
    vector<int> k1p2rot = rotArr(k1p2, 1);
    
    vector<int> k1x;
    k1x.insert(k1x.end(), k1p1rot.begin(), k1p1rot.end());
    k1x.insert(k1x.end(), k1p2rot.begin(), k1p2rot.end());
    
    vector<int> k1 = per8(k1x);
    
    vector<int> k2p1(k1x.begin()+a, k1x.begin()+b);
    vector<int> k2p2(k1x.begin()+b, k1x.begin()+c);
    
    vector<int> k2p1rot = rotArr(k2p1, 2);
    vector<int> k2p2rot = rotArr(k2p2, 2);
    
    vector<int> k2x;
    k2x.insert(k2x.end(), k2p1rot.begin(), k2p1rot.end());
    k2x.insert(k2x.end(), k2p2rot.begin(), k2p2rot.end());
    
    vector<int> k2 = per8(k2x);
    
    for (int i=0; i<8; i++){
        cout<<k1[i];
    }
    cout<<endl;
    for (int i=0; i<8; i++){
        cout<<k2[i];
    }
    
    
    return 0;
}