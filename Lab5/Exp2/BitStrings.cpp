#include <iostream>
using namespace std;
int bitstrings(int n)
{
    if (n == 1)
        return 2;
    if (n == 2)
        return 3;
    return bitstrings(n - 1) + bitstrings(n - 2);
}
int main()
{
    int n;
    cout << "Enter length of bitstring: ";
    cin >> n;
    cout << "Valid bitstrings of length " << n << ": " << bitstrings(n) << endl;
    return 0;
}