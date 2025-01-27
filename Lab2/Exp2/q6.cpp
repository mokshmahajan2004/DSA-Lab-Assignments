#include <iostream>
#include <climits> // for INT_MAX
using namespace std;

int findMin(const int arr[], int size)
{
    if (size <= 0)
        return INT_MAX; // Return maximum possible integer for empty arrays
    int minVal = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] < minVal)
            minVal = arr[i];
    }
    return minVal;
}

int main()
{
    int myList[] = {10, 20, 30, 40, 50};
    int size = sizeof(myList) / sizeof(myList[0]);

    if (size > 0)
    {
        cout << "Minimum element: " << findMin(myList, size) << endl; // Output: 10
    }
    else
    {
        cout << "Array is empty" << endl;
    }

    return 0;
}
