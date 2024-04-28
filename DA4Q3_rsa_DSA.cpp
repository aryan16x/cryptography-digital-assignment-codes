#include <iostream>
#include <math.h>

using namespace std;

int modinv(int a, int m){
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
    
    return result;
}

int main()
{
    int p=7,q=13,e=5,w=35;
    
    int n=p*q,phi=(p-1)*(q-1);
    
    int d = modinv(e,phi);
    
    int t;
    
    t = pow(w,e);
    int s = t%n;
    
    int wx = power(s,d,n);
    
    cout<<s<<" "<<wx;
    
    
    return 0;
}