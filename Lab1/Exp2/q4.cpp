#include <iostream>
using namespace std;
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}
void shiftRight(int arr[], int size)
{
    int lastElement = arr[size - 1];
    for (int i = size - 1; i > 0; i--)
        arr[i] = arr[i - 1];
    arr[0] = lastElement;
}
int main()
{
    int arr[4] = {10, 6, 5, 4};
    int size = sizeof(arr) / sizeof(arr[0]);
    printArray(arr, size);
    cout << endl;
    shiftRight(arr, size);
    printArray(arr, size);
    return 0;
}