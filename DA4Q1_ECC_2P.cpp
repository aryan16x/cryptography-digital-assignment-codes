#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int p=17,a=2,b=2,x=5,y=1,lambda,x2,y2;
    
    int t = (((3*pow(x,2))+a)/(2*y));
    
    lambda = t%p;
    
    t = (pow(lambda,2)-2*x);
    x2 = ((t%p)+p)%p;
    
    t = (lambda*(x2-x)-y);
    y2 = ((t%p)+p)%p;
    
    cout<<x2<<" "<<y2;

    return 0;
}