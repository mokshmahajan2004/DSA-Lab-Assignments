#include <iostream>
#include <vector>
#include <algorithm> // Include for std::generate
#include <chrono>
#include <cstdlib> // Include for rand()
using namespace std;
using namespace chrono;
// Quick Sort with Random Pivot Selection
int partition(vector<int> &arr, int low, int high)
{
    int pivotIndex = low + rand() % (high - low + 1); // Random pivot
    swap(arr[pivotIndex], arr[high]);
    int pivot = arr[high], i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
            swap(arr[++i], arr[j]);
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}
void quickSort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
// Function to test sorting performance
void testSortingAlgorithm(void (*sortFunc)(vector<int> &, int, int), vector<int> arr, string name)
{
    auto start = high_resolution_clock::now();
    sortFunc(arr, 0, arr.size() - 1);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << name << " took " << duration.count() << " ms." << endl;
}
// Main function
int main()
{
    int n = 1000000; // Large dataset
    vector<int> arr(n);
    // Use std::generate correctly
    generate(arr.begin(), arr.end(), rand); // Fill array with random numbers
    // Test Quick Sort on large data
    testSortingAlgorithm(quickSort, arr, "Quick Sort");
    return 0;
}
