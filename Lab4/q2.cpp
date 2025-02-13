#include <iostream>
#include <vector>
#include <string>
#include <chrono>

using namespace std;
using namespace chrono;

// Linear Search function
int linearSearch(const vector<string> &phoneBook, const string &target)
{
    for (int i = 0; i < phoneBook.size(); i++)
    {
        if (phoneBook[i] == target)
            return i; // Found at index i
    }
    return -1; // Not found
}

int main()
{
    vector<string> phoneBook = {
        "Amit", "Bhavesh", "Chirag", "Deepika", "Esha",
        "Farhan", "Gaurav", "Harshita", "Ishaan", "Jatin",
        "Kavita", "Laxmi", "Manish", "Neha", "Omkar",
        "Pooja", "Qasim", "Rohit", "Sneha", "Tarun"};

    string searchName;
    cout << "Enter contact name to search: ";
    cin >> searchName;

    auto start = high_resolution_clock::now();
    int index = linearSearch(phoneBook, searchName);
    auto end = high_resolution_clock::now();

    // Time taken for search
    auto duration = duration_cast<microseconds>(end - start);

    // Output result
    if (index != -1)
        cout << "Contact found at index " << index << endl;
    else
        cout << "Contact not found." << endl;

    cout << "Time taken: " << duration.count() << " microseconds" << endl;

    // Time Complexity Analysis
    cout << "\nTime Complexity Analysis:\n";
    cout << "Best Case: O(1) (First Contact)\n";
    cout << "Worst Case: O(n) (Last Contact or Not Found)\n";
    cout << "Average Case: O(n/2) ≈ O(n)\n";

    return 0;
}
