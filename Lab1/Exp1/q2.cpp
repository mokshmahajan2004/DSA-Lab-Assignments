#include <iostream>
using namespace std;

int findSmallestN(int goal)
{
    int sum = 0, n = 0;
    while (sum < goal)
        sum += ++n;
    return n;
}

int main()
{
    int goal;
    cout << "Enter the goal value: ";
    cin >> goal;
    if (goal > 0)
        cout << "The smallest n is " << findSmallestN(goal) << "." << endl;
    else
        cout << "Goal must be positive!" << endl;
    return 0;
}
