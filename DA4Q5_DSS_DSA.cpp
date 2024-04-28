#include <iostream>
#include <math.h>

using namespace std;

int power(int b, int e, int m){
    b = b%m;
    int result = 1;
    while(e>0){
        if (e&1){
            result = (result*b)%m;
        }
        e = e>>1;
        b = (b*b)%m;
    }
    
    // result = ((result%m)+m)%m;
    
    return result;
}

int modinv(int a, int m){
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
        if (m==0){
            x = false;
        }
    }
    while(t1<0){
        t1+=m0;
    }
    return t1;
}

int main()
{
    int p=11,q=5,hm=54,h=2,x=3,k=3;
    int r,s,w,u1,u2,v;
    
    int g = power(h, (p-1)/q, p);
    
    r = power(g,k,p)%q;
    
    int kinv = modinv(k,q);
    
    s = (kinv*(hm+x*r))%q;
    
    w = modinv(s,q);
    u1 = (hm*w)%q;
    u2 = r*w%q;
    v = ((power(g,u1,q)*power(x,u2,p))%q)%p;
    
    cout<<r<<" "<<s<<" "<<w<<" "<<u1<<" "<<u2<<" "<<v;
    
    
    return 0;
}