#include <iostream>
using namespace std;
int main()
{
    int arr1[] = {1, 2, 3, 4};
    int arr2[] = {5, 6, 7, 8};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    int merged[size1 + size2];
    // Merge the arrays
    for (int i = 0; i < size1 + size2; ++i)
    {
        merged[i] = (i < size1) ? arr1[i] : arr2[i - size1];
    }
    // Output the merged array
    cout << "Merged array: ";
    for (int i = 0; i < size1 + size2; ++i)
    {
        cout << merged[i] << " ";
    }
    cout << endl;
    return 0;
}
