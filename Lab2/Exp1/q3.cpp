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
void insertElement(int arr[], int &n, int index, int element)
{
    if (index < 0 || index > n)
    {
        cout << "Invalid index." << endl;
        return;
    }
    for (int i = n; i > index; --i)
    {
        arr[i] = arr[i - 1];
    }
    arr[index] = element;
    ++n;
}
void printArray(const int arr[], int n)
{
    cout << "Updated array: ";
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    int arr[100], n, index, element;
    inputArray(arr, n);
    cout << "Enter index and element to insert: ";
    cin >> index >> element;
    insertElement(arr, n, index, element);
    printArray(arr, n);
    return 0;
}
