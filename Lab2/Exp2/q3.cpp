#include <iostream>
using namespace std;
// Function to input the array
void inputArray(int arr[], int &n)
{
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter elements: ";
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
}
// Function to retrieve an element by index
int getElement(int arr[], int n, int index)
{
    return (index >= 0 && index < n) ? arr[index] : -1;
}
int main()
{
    int arr[100], n, index;
    inputArray(arr, n);
    cout << "Enter index to retrieve: ";
    cin >> index;
    int result = getElement(arr, n, index);
    if (result != -1)
        cout << "Element at index " << index << " is " << result << ".\n";
    else
        cout << "Invalid index.\n";
    return 0;
}
