#include <iostream>
#include <math.h>

using namespace std;

int modinv(int a, int m){
    int m0 = m;
    
    int q,r,t1,t2,t;
    
    bool x=true;
    
    t1=1;
    t2=0;
    
    while(x){
        q = a/m;
        r = a%m;
        t = t1-t2*q;
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
    
    return t1;
}

int main()
{
    int p=97,a=2,b=3,x1=17,y1=10,x2=95,y2=31,lambda,x3,y3;
    
    int t;
    
    int m1,m2;
    
    m1 = (y2-y1)%p;
    m2 = modinv((x2-x1),p);
    
    lambda = (((m1*m2)%p)+p)%p;
    
    cout<<lambda<<endl;
    
    t = (pow(lambda,2)-x1-x2);
    x3 = ((t%p)+p)%p;
    
    t = (lambda*(x1-x3)-y1);
    y3 = ((t%p)+p)%p;
    
    cout<<x3<<" "<<y3;

    return 0;
}