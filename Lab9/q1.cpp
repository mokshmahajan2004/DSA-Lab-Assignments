#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
bool isSubsetSum(vector<int> &set, int n, int sum)
{
    // Total number of subsets: 2^n
    int total = pow(2, n);
    for (int i = 0; i < total; i++)
    {
        int subsetSum = 0;
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
            {
                subsetSum += set[j];
            }
        }
        if (subsetSum == sum)
            return true;
    }
    return false;
}
int main()
{
    vector<int> set = {3, 34, 4, 12, 5, 2};
    int sum = 9;
    cout << (isSubsetSum(set, set.size(), sum) ? "True" : "False") << endl;
    return 0;
}
