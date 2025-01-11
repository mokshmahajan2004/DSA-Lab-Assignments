#include <iostream>
using namespace std;

bool isPrime(int n)
{
    if (n <= 1)
        return false;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            return false;
    return true;
}

int main()
{
    int num;
    cout << "Enter an integer: ";
    cin >> num;
    cout << (isPrime(num) ? "Prime" : "Not Prime") << endl;
    return 0;
}
