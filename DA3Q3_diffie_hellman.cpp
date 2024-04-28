#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int q,r,a,b;
    
    q=7;
    r=3;
    a=4;
    b=5;
    
    int ya,yb,ka,kb;
    
    int tmp;
    
    tmp = pow(r,a);
    ya = tmp%q;
    
    tmp = pow(r,b);
    yb = tmp%q;
    
    tmp = pow(yb,a);
    ka = tmp%q;
    
    tmp = pow(ya,b);
    kb = tmp%q;
    
    cout<<ya<<" "<<yb<<" "<<ka<<" "<<kb;

    return 0;
}