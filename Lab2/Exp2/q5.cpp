#include <iostream>
#include <climits> // for INT_MIN
using namespace std;

int findMax(const int arr[], int size)
{
    if (size <= 0)
        return INT_MIN; // Return minimum possible integer for empty arrays
    int maxVal = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > maxVal)
            maxVal = arr[i];
    }
    return maxVal;
}

int main()
{
    int myList[] = {10, 20, 30, 40, 50};
    int size = sizeof(myList) / sizeof(myList[0]);

    if (size > 0)
    {
        cout << "Maximum element: " << findMax(myList, size) << endl; // Output: 50
    }
    else
    {
        cout << "Array is empty" << endl;
    }

    return 0;
}
