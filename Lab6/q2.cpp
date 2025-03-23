#include <iostream>
#include <vector>
using namespace std;
// Swap function
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
// Bubble Sort
void bubbleSort(vector<int> arr)
{
    int n = arr.size(), comparisons = 0, swaps = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            comparisons++;
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swaps++;
            }
        }
    }
    cout << "Bubble Sort: Comparisons = " << comparisons << ", Swaps = " << swaps << "\n";
}
// Selection Sort
void selectionSort(vector<int> arr)
{
    int n = arr.size(), comparisons = 0, swaps = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            comparisons++;
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        if (minIndex != i)
        {
            swap(arr[i], arr[minIndex]);
            swaps++;
        }
    }
    cout << "Selection Sort: Comparisons = " << comparisons << ", Swaps = " << swaps << "\n";
}
// Insertion Sort
void insertionSort(vector<int> arr)
{
    int n = arr.size(), comparisons = 0, swaps = 0;
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
            comparisons++;
            swaps++;
        }
        arr[j + 1] = key;
    }
    cout << "Insertion Sort: Comparisons = " << comparisons << ", Swaps = " << swaps << "\n";
}
// Quick Sort
int partition(vector<int> &arr, int low, int high, int &comparisons, int &swaps)
{
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        comparisons++;
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
            swaps++;
        }
    }
    swap(arr[i + 1], arr[high]);
    swaps++;
    return i + 1;
}
void quickSort(vector<int> &arr, int low, int high, int &comparisons, int &swaps)
{
    if (low < high)
    {
        int pi = partition(arr, low, high, comparisons, swaps);
        quickSort(arr, low, pi - 1, comparisons, swaps);
        quickSort(arr, pi + 1, high, comparisons, swaps);
    }
}
void quickSortWrapper(vector<int> arr)
{
    int comparisons = 0, swaps = 0;
    quickSort(arr, 0, arr.size() - 1, comparisons, swaps);
    cout << "Quick Sort: Comparisons = " << comparisons << ", Swaps = " << swaps << "\n";
}
// Shell Sort
void shellSort(vector<int> arr)
{
    int n = arr.size(), comparisons = 0, swaps = 0;
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i++)
        {
            int temp = arr[i], j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
            {
                arr[j] = arr[j - gap];
                comparisons++;
                swaps++;
            }
            arr[j] = temp;
        }
    }
    cout << "Shell Sort: Comparisons = " << comparisons << ", Swaps = " << swaps << "\n";
}
// Merge Sort
void merge(vector<int> &arr, int left, int mid, int right, int &comparisons)
{
    vector<int> temp;
    int i = left, j = mid + 1;
    while (i <= mid && j <= right)
    {
        comparisons++;
        if (arr[i] <= arr[j])
            temp.push_back(arr[i++]);
        else
            temp.push_back(arr[j++]);
    }
    while (i <= mid)
        temp.push_back(arr[i++]);
    while (j <= right)
        temp.push_back(arr[j++]);
    copy(temp.begin(), temp.end(), arr.begin() + left);
}
void mergeSort(vector<int> &arr, int left, int right, int &comparisons)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid, comparisons);
        mergeSort(arr, mid + 1, right, comparisons);
        merge(arr, left, mid, right, comparisons);
    }
}
void mergeSortWrapper(vector<int> arr)
{
    int comparisons = 0;
    mergeSort(arr, 0, arr.size() - 1, comparisons);
    cout << "Merge Sort: Comparisons = " << comparisons << "\n";
}
int main()
{
    vector<int> arr = {64, 25, 12, 22, 11, 90, 55, 43, 88, 19};

    bubbleSort(arr);
    selectionSort(arr);
    insertionSort(arr);
    quickSortWrapper(arr);
    shellSort(arr);
    mergeSortWrapper(arr);
    return 0;
}