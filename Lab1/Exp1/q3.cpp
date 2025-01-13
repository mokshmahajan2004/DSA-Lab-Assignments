#include <iostream>
using namespace std;
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    else
    {
        return gcd(b, a % b);
    }
}
int main()
{
    cout << "GCD of 10 and 7 is " << gcd(10, 7) << endl;
    return 0;
}