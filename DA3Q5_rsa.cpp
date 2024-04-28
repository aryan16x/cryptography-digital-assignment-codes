#include <iostream>
#include <math.h>

using namespace std;

int invm(int a, int m){
    int q,r,t1=1,t2=0,t,m0=m;
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
            x = false;
        }
    }
    
    while(t1<0){
        t1 += m0;
    }
    
    return t1;
}

int main()
{
    int m=4,p=3,q=5,e=5,d,phi,n,ct,pt;
    
    n = p*q;
    phi = (p-1)*(q-1);
    d = invm(e,phi);
    
    int t;
    
    t = pow(m,e);
    ct = t%n;
    
    t = pow(ct,d);
    pt = t%n;
    
    cout<<ct<<" "<<pt;

    return 0;
}