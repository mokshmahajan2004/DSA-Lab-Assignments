#include <iostream>
#include <chrono>
#include <cmath>
#include <iomanip>

using namespace std;
using namespace chrono;

// Recurrence 1: T(n) = T(n−1) + 1 → O(n)
int recurrence1(int n)
{
    if (n == 0)
        return 0;
    return recurrence1(n - 1) + 1;
}

// Recurrence 2: T(n) = T(n−1) + n → O(n²)
int recurrence2(int n)
{
    if (n == 0)
        return 0;
    return recurrence2(n - 1) + n;
}

// Recurrence 3: T(n) = T(n−1) + n² → O(n³)
int recurrence3(int n)
{
    if (n == 0)
        return 0;
    return recurrence3(n - 1) + (n * n);
}

// Recurrence 4: T(n) = T(n−1) + log(n) → O(n log n)
double recurrence4(int n)
{
    if (n == 0)
        return 0;
    return recurrence4(n - 1) + log2(n);
}

// Function to measure execution time (Running multiple iterations for accuracy)
template <typename Func>
void measureTime(Func func, int n, const string &label)
{
    const int iterations = 1000; // Run multiple times for better accuracy
    auto start = high_resolution_clock::now();

    for (int i = 0; i < iterations; i++)
    {
        func(n);
    }

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(end - start) / iterations; // Get average time

    // Print results in tabular format with proper alignment
    cout << left << setw(35) << label
         << setw(10) << right << n
         << setw(15) << right << func(n) // Compute T(n) once outside the loop
         << setw(15) << right << duration.count() << " ns" << endl;
}

int main()
{
    // Values of n for performance testing
    int test_values[] = {10, 50, 100, 150, 200};

    // Print table header with proper formatting
    cout << left << setw(35) << "Recurrence Relation"
         << setw(10) << "n"
         << setw(15) << "T(n)"
         << setw(15) << "Time (ns)" << endl;

    cout << string(75, '-') << endl;

    // Run experiments for each recurrence relation
    for (int n : test_values)
    {
        measureTime(recurrence1, n, "T(n) = T(n-1) + 1");
        measureTime(recurrence2, n, "T(n) = T(n-1) + n");
        measureTime(recurrence3, n, "T(n) = T(n-1) + n^2");
        measureTime(recurrence4, n, "T(n) = T(n-1) + log(n)");
        cout << string(75, '-') << endl;
    }

    return 0;
}
