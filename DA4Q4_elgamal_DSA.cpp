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
    
    result = ((result%m)+m)%m;
    
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
    int q=19,r=10,xa=16,k=5,hm=14;
    
    int ya;
    
    ya = power(r,xa,q);
    
    int s1,s2,v1,v2;
    
    s1 = power(r,k,q);
    
    int kinv = modinv(k,q-1);
    
    s2 = (kinv*(hm-xa*s1))%(q-1);
    
    int u = q-1;
    
    s2 = ((s2%u)+u)%u;
    
    v1 = power(r,hm,q);
    
    v2 = (power(ya,s1,q)*power(s1,s2,q))%q;
    
    cout<<s1<<" "<<s2<<" "<<v1<<" "<<v2;
    
    
    return 0;
}