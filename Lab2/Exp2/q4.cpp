#include <iostream>
using namespace std;

void setElement(int arr[], int size, int index, int value)
{
    if (index < 0 || index >= size)
        throw out_of_range("Index out of bounds");
    arr[index] = value;
}

int main()
{
    int myList[] = {10, 20, 30, 40, 50};
    int size = sizeof(myList) / sizeof(myList[0]);

    try
    {
        setElement(myList, size, 2, 99);
        for (int i = 0; i < size; i++)
            cout << myList[i] << " "; // Output: 10 20 99 40 50
    }
    catch (const exception &e)
    {
        cout << e.what();
    }

    return 0;
}
