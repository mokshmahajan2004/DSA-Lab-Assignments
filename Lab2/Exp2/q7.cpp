#include <iostream>
using namespace std;

void reverseArray(int arr[], int size)
{
    for (int i = 0; i < size / 2; i++)
    {
        swap(arr[i], arr[size - i - 1]); // Swap elements from both ends
    }
}

int main()
{
    int myList[] = {10, 20, 30, 40, 50};
    int size = sizeof(myList) / sizeof(myList[0]);

    reverseArray(myList, size);

    cout << "Reversed array: ";
    for (int i = 0; i < size; i++)
    {
        cout << myList[i] << " ";
    }
    // Output: 50 40 30 20 10

    return 0;
}
