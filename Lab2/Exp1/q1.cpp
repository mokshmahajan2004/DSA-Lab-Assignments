#include <iostream>
using namespace std;
void insertAtBeginning(int arr[], int &n, int element)
{
    for (int i = n; i > 0; i--)
        arr[i] = arr[i - 1];
    arr[0] = element;
    n++;
}
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
int main()
{
    int arr[100], n, element;
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << "Enter element to insert: ";
    cin >> element;
    insertAtBeginning(arr, n, element);
    printArray(arr, n);
    return 0;
}
