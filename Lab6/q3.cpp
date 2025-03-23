#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm> // for generating test cases

using namespace std;
using namespace chrono;

// Utility function to print arrays
void printArray(vector<int> &arr)
{
    for (int num : arr)
        cout << num << " ";
    cout << endl;
}

// Bubble Sort
void bubbleSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
}

// Selection Sort
void selectionSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        swap(arr[i], arr[minIndex]);
    }
}

// Insertion Sort
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

// Shell Sort
void shellSort(vector<int> &arr)
{
    int n = arr.size();
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i++)
        {
            int temp = arr[i], j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
            {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

// Quick Sort (Helper function)
int partition(vector<int> &arr, int low, int high)
{
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

// Merge Sort (Helper function)
void mergeArrays(vector<int> &arr, int l, int m, int r)
{
    int n1 = m - l + 1, n2 = r - m;
    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int i = 0; i < n2; i++)
        R[i] = arr[m + 1 + i];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
}
void mergeSort(vector<int> &arr, int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        mergeArrays(arr, l, m, r);
    }
}

// Heap Sort
void heapify(vector<int> &arr, int n, int i)
{
    int largest = i, left = 2 * i + 1, right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}
void heapSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

// Function to measure execution time
void testSortingAlgorithm(void (*sortFunc)(vector<int> &), vector<int> arr, string name)
{
    auto start = high_resolution_clock::now();
    sortFunc(arr);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);
    cout << name << " took " << duration.count() << " nanoseconds." << endl;
}

int main()
{
    vector<int> sizes = {10, 1000, 10000};
    for (int size : sizes)
    {
        cout << "\nTesting with " << size << " elements:" << endl;
        vector<int> arr(size);
        generate(arr.begin(), arr.end(), rand);

        testSortingAlgorithm(bubbleSort, arr, "Bubble Sort");
        testSortingAlgorithm(selectionSort, arr, "Selection Sort");
        testSortingAlgorithm(insertionSort, arr, "Insertion Sort");
        testSortingAlgorithm(shellSort, arr, "Shell Sort");
        testSortingAlgorithm([](vector<int> &a)
                             { quickSort(a, 0, a.size() - 1); }, arr, "Quick Sort");
        testSortingAlgorithm([](vector<int> &a)
                             { mergeSort(a, 0, a.size() - 1); }, arr, "Merge Sort");
        testSortingAlgorithm(heapSort, arr, "Heap Sort");
    }
    return 0;
}