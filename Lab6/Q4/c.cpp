#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Patient
{
    string name;
    int emergencyLevel;
};

void heapify(vector<Patient> &patients, int n, int i)
{
    int largest = i, left = 2 * i + 1, right = 2 * i + 2;
    if (left < n && patients[left].emergencyLevel > patients[largest].emergencyLevel)
        largest = left;
    if (right < n && patients[right].emergencyLevel > patients[largest].emergencyLevel)
        largest = right;
    if (largest != i)
    {
        swap(patients[i], patients[largest]);
        heapify(patients, n, largest);
    }
}

void heapSort(vector<Patient> &patients)
{
    int n = patients.size();
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(patients, n, i);
    for (int i = n - 1; i > 0; i--)
    {
        swap(patients[0], patients[i]);
        heapify(patients, i, 0);
    }
}

void displayPatients(const vector<Patient> &patients)
{
    cout << "\nSorted Patients by Priority:\n";
    for (const auto &p : patients)
        cout << p.name << " (Emergency: " << p.emergencyLevel << ")\n";
}

int main()
{
    vector<Patient> patients = {{"Alice", 3}, {"Bob", 5}, {"Charlie", 1}, {"David", 4}, {"Eve", 2}};
    cout << "Before Sorting:\n";
    for (const auto &p : patients)
        cout << p.name << " (Emergency: " << p.emergencyLevel << ")\n";
    heapSort(patients);
    displayPatients(patients);
    return 0;
}
