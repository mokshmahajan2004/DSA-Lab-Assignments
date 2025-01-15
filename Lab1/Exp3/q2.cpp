#include <iostream>
using namespace std;
int greatest(int arr[], int size)
{
    int index, num = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > num)
        {
            num = arr[i];
            index = i;
        }
    }
    return num;
}
int main()
{
    int arr[5] = {5, 10, 45, 23, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "The Greatest number in array is " << greatest(arr, size);
    return 0;
}