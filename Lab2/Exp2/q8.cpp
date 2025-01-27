#include <iostream>
using namespace std;

void shiftLeft(int arr[], int size)
{
    if (size <= 0)
        return; // Handle empty array
    for (int i = 0; i < size - 1; i++)
    {
        arr[i] = arr[i + 1]; // Shift elements to the left
    }
    arr[size - 1] = 0; // Set the last element to 0
}

int main()
{
    int myList[] = {10, 20, 30, 40, 50};
    int size = sizeof(myList) / sizeof(myList[0]);

    shiftLeft(myList, size);

    cout << "Shifted array: ";
    for (int i = 0; i < size; i++)
    {
        cout << myList[i] << " ";
    }
    // Output: 20 30 40 50 0

    return 0;
}
