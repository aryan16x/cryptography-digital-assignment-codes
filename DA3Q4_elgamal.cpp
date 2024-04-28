#include <iostream>
#include <math.h>

using namespace std;

int pox(int a, int b){
    return pow(a,b);
}

int invm(int a, int m){
    int q,r,t1=1,t2=0,t,m0=m;
    bool x=true;
    
    while(x){
        q=a/m;
        r=a%m;
        t=t1-t2*q;
        
        a=m;
        m=r;
        t1=t2;
        t2=t;
        if (t1==0){
            x=false;
        }
    }
    
    while (t1<0){
        t1+=m0;
    }
    
    return t1;
}

int main()
{
    int q=11,r=2,m=8,a=5,b=6;
    
    int pua,pub,ct1,ct2,pt;
    
    pua = pox(r,a)%q;
    pub = pox(r,b)%q;
    
    int kb = pox(pua,b)%q;
    ct1 = pub;
    ct2 = (kb*m)%q;
    
    int ka = pox(ct1,a)%q;
    
    pt = (ka*ct2)%q;
    
    cout<<pua<<" "<<pub<<" "<<ct2<<" "<<pt;

    return 0;
}