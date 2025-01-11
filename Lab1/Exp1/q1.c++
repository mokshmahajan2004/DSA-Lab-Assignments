#include <iostream>
using namespace std;
int sum(int a, int b)
{
    int total = 0;
    for (int i = a; i <= b; i++)
    {
        total += i;
    }
    return total;
}
int main()
{
    // Write a program to compute and return the sum of all integers between first and
    //  last (inclusive).
    int num1, num2;
    cout << "Enter the first number " << endl;
    cin >> num1;
    cout << "Enter the second number " << endl;
    cin >> num2;
    cout << "Total sum is " << sum(num1, num2) << endl;
    return 0;
}