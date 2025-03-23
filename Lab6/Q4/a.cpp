#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm> // For random shuffling
using namespace std;
using namespace chrono;
// Function to generate a nearly sorted array
vector<int> generateNearlySortedArray(int n, int disorder = 5)
{
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        arr[i] = i + 1; // Sorted array
    }
    // Introduce minor disorder by swapping random elements
    for (int i = 0; i < disorder; i++)
    {
        int idx1 = rand() % n;
        int idx2 = rand() % n;
        swap(arr[idx1], arr[idx2]);
    }
    return arr;
}
// Insertion Sort (Efficient for nearly sorted data)
void insertionSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 1; i < n; i++)
    {
        int key = arr[i], j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
// Selection Sort (Inefficient for nearly sorted data)
void selectionSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}
// Function to test sorting algorithms and measure execution time
void testSortingAlgorithm(void (*sortFunc)(vector<int> &), vector<int> arr, string name)
{
    auto start = high_resolution_clock::now();
    sortFunc(arr);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << name << " took " << duration.count() << " microseconds." << endl;
}
// Main function
int main()
{
    int n = 1000;                                       // Size of nearly sorted array
    vector<int> arr = generateNearlySortedArray(n, 10); // 10 misplaced elements
    // Test sorting algorithms
    testSortingAlgorithm(insertionSort, arr, "Insertion Sort");
    testSortingAlgorithm(selectionSort, arr, "Selection Sort");
    return 0;
}
