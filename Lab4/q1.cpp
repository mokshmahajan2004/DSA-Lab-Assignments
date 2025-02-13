#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>

using namespace std;

// Complexity functions
double constant_time() { return 1; }
double logarithmic_time(int n) { return log2(n); }
double sqrt_time(int n) { return sqrt(n); }
double linear_time(int n) { return n; }
double linearithmic_time(int n) { return n * log2(n); }
double quadratic_time(int n) { return n * n; }
double cubic_time(int n) { return n * n * n; }
double exponential_time(int n) { return pow(2, n); }

double factorial_time(int n)
{
    double fact = 1;
    for (int i = 1; i <= n; ++i)
        fact *= i;
    return fact;
}

// Function to write results to CSV
void save_to_csv(const string &filename, vector<vector<double>> &data)
{
    ofstream file(filename);
    if (!file)
    {
        cerr << "Error opening file!";
        return;
    }

    for (const auto &row : data)
    {
        for (const auto &value : row)
            file << value << ",";
        file << "\n";
    }
    file.close();
}

int main()
{
    vector<int> n_values = {1, 2, 3, 5, 10};
    vector<vector<double>> results;

    for (int n : n_values)
    {
        results.push_back({(double)n,
                           constant_time(),
                           logarithmic_time(n),
                           sqrt_time(n),
                           linear_time(n),
                           linearithmic_time(n),
                           quadratic_time(n),
                           cubic_time(n),
                           exponential_time(n),
                           factorial_time(n)});
    }

    save_to_csv("complexity_results.csv", results);
    cout << "CSV generated!" << endl;
    return 0;
}
