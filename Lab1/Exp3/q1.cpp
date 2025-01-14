#include <iostream>
using namespace std;

int sum(int arr[], int size)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        count += arr[i];
    }
    return count;
}
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}
int main()
{
    int arr[4] = {10, 5, 4, 7};
    int size = sizeof(arr) / sizeof(arr[0]);
    printArray(arr, size);
    cout << endl;
    cout << "The sum of elements of Array is " << sum(arr, size);

    return 0;
}