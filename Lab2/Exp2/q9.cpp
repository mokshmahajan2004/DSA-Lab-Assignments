#include <iostream>
using namespace std;

void rotateLeft(int arr[], int size)
{
    if (size <= 0)
        return;         // Handle empty array
    int first = arr[0]; // Store the first element
    for (int i = 0; i < size - 1; i++)
    {
        arr[i] = arr[i + 1]; // Shift elements to the left
    }
    arr[size - 1] = first; // Place the first element at the end
}

int main()
{
    int myList[] = {10, 20, 30, 40, 50};
    int size = sizeof(myList) / sizeof(myList[0]);

    rotateLeft(myList, size);

    cout << "Rotated array: ";
    for (int i = 0; i < size; i++)
    {
        cout << myList[i] << " ";
    }
    // Output: 20 30 40 50 10

    return 0;
}
