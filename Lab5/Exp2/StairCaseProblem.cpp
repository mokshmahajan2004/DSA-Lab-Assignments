#include <iostream>
using namespace std;
int staircase(int n)
{
    if (n <= 2)
        return n;
    return staircase(n - 1) + staircase(n - 2);
}
int main()
{
    int n;
    cout << "Enter number of steps: ";
    cin >> n;
    cout << "Ways to climb " << n << " steps: " << staircase(n) << endl;
    return 0;
}