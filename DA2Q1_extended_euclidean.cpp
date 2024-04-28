#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    
    int a,m;
    
    a = 5;
    m = 3;
    int m0 = m;
    
    int q,r,t1,t2,t;
    
    bool x=true;
    
    t1=1;
    t2=0;
    
    while(x){
        q = a/m;
        r = a%m;
        t = t1-t2*q;
        cout<<q<<" "<<a<<" "<<m<<" "<<r<<" "<<t1<<" "<<t2<<" "<<t<<endl;
        a = m;
        m = r;
        t1 = t2;
        t2 = t;
        if (m==0){
            x=false;
        }
    }
    
    while(t1<0){
        t1 += m0;
    }
    
    cout<<"inv mod: "<<t1<<endl;
    

    return 0;
}