#include <iostream>
#include <string.h>

using namespace std;

int invmod(int a, int m){
    int m0=m;
    int q,r,t1=1,t2=0,t;
    bool x=true;
    
    while(x){
        q = a/m;
        r = a%m;
        t = t1-t2*q;
        a = m;
        m = r;
        t1 = t2;
        t2 = t;
        if (m==0){
            x = false;;
        }
    }
    
    while(t1<0){
        t1 += m0;
    }
    
    return t1;
}

int main()
{
    
    int a1,a2,a3,k1,k2,k3,x,M,m1,m2,m3,invm1,invm2,invm3;
    
    a1=3;
    a2=4;
    a3=5;
    k1=5;
    k2=11;
    k3=7;
    
    M = k1*k2*k3;
    
    m1 = M/k1;
    m2 = M/k2;
    m3 = M/k3;
    
    invm1 = invmod(m1,k1);
    invm2 = invmod(m2,k2);
    invm3 = invmod(m3,k3);
    
    x = (a1*m1*invm1 + a2*m2*invm2 + a3*m3*invm3)%M;
    
    cout<<x<<endl;
    

    return 0;
}