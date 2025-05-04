#include <iostream>
#include <vector>
using namespace std;
void knapsack(int W, vector<int> &wt, vector<int> &val, int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    // Build table dp[][] bottom-up
    for (int i = 1; i <= n; i++)
    {
        for (int w = 0; w <= W; w++)
        {
            if (wt[i - 1] <= w)
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }
    // Output the max value
    cout << "Max Value: " << dp[n][W] << endl;
    // Backtrack to find selected items
    int w = W;
    vector<int> selected;
    for (int i = n; i > 0 && w > 0; i--)
    {
        if (dp[i][w] != dp[i - 1][w])
        {
            selected.push_back(i); // Store item index (1-based)
            w -= wt[i - 1];
        }
    }
    cout << "Selected item indices: ";
    for (int i = selected.size() - 1; i >= 0; i--)
        cout << selected[i] << " ";
    cout << endl;
}
int main()
{
    vector<int> weights = {10, 20, 30};
    vector<int> values = {60, 100, 120};
    int capacity = 50;
    knapsack(capacity, weights, values, weights.size());
    return 0;
}
