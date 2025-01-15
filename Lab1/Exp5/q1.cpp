#include <iostream>
using namespace std;
int linearSearch(int arr[], int size, int goal)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == goal)
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    int arr[] = {10, 6, 17, 56, 41};
    int goal = 17;
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << linearSearch(arr, size, goal);

    return 0;
}