#include <iostream>

using namespace std;

int power(int base, int exp, int mod)
{
    int result = 1;
    base = base % mod;
    while (exp > 0)
    {
        if (exp & 1)
            result = (result * base) % mod;
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}

int main()
{
    int base, exp, mod;

    cin >> base >> exp >> mod;

    int result = power(base, exp, mod);

    cout << result << endl;

    return 0;
}