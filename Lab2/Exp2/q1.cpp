#include <iostream>
using namespace std;
void inputArray(int arr[], int &n)
{
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter elements: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
}
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
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
int main()
{
    int arr[100], n, index, element;
    inputArray(arr, n);
    cout << "Enter element to search: ";
    cin >> element;
    cout << "Index: " << linearSearch(arr, n, element);

    return 0;
}