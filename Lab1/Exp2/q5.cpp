#include <iostream>
using namespace std;
void removeDuplicates(int arr[], int &n)
{
    int index = 0; // Pointer for the position of distinct integers

    for (int i = 0; i < n; ++i)
    {
        bool isDuplicate = false;
        // Check if arr[i] has already appeared in the array
        for (int j = 0; j < index; ++j)
        {
            if (arr[i] == arr[j])
            {
                isDuplicate = true;
                break;
            }
        }
        // If arr[i] is not a duplicate, move it to the left part of the array
        if (!isDuplicate)
        {
            arr[index++] = arr[i];
        }
    }
    // Update the size of the array to contain only unique elements
    n = index;
}
int main()
{
    int arr[] = {4, 2, 4, 3, 2, 5, 3, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Original array: ";
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    removeDuplicates(arr, n);
    cout << "Array after removing duplicates: ";
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
