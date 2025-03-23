#include <iostream>
#include <algorithm> // For sort()
using namespace std;
// Function for Linear Search
int linearSearch(int arr[], int size, int target, int &comparisons)
{
    comparisons = 0;
    for (int i = 0; i < size; i++)
    {
        comparisons++;
        if (arr[i] == target)
            return i;
    }
    return -1;
}
// Function for Binary Search
int binarySearch(int arr[], int size, int target, int &comparisons)
{
    int left = 0, right = size - 1;
    comparisons = 0;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        comparisons++;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}
int main()
{
    int arr[] = {64, 25, 12, 22, 11, 90, 55, 43, 88, 19};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 88;
    int comparisons;
    // Linear Search
    int linearIndex = linearSearch(arr, size, target, comparisons);
    cout << "Linear Search: Element found at index " << linearIndex << " with " << comparisons << " comparisons.\n";
    // Sorting the array for Binary Search
    sort(arr, arr + size);
    // Binary Search
    int binaryIndex = binarySearch(arr, size, target, comparisons);
    cout << "Binary Search: Element found at index " << binaryIndex << " with " << comparisons << " comparisons.\n";
    return 0;
}
