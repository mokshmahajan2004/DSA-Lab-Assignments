#include <iostream>
using namespace std;
int main()
{
    int arr[4] = {4, 3, 5, 7};
    int revarr[4];
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "The size of an array is " << size << endl;
    int idx = 0;
    for (int i = size - 1; i >= 0; i--)
    {
        revarr[idx] = arr[i];
        idx++;
    }
    cout << "The Initial Array is ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl
         << "The Reversed Array is ";
    for (int i = 0; i < size; i++)
    {
        cout << revarr[i] << " ";
    }

    return 0;
}