#include <iostream>
#include <vector>
#include <limits>
using namespace std;
const int INF = numeric_limits<int>::max();
// Function to find the nearest unvisited city
int findNearestCity(int currentCity, const vector<vector<int>> &dist, const vector<bool> &visited)
{
    int nearestCity = -1;
    int minDist = INF;
    for (int i = 0; i < dist.size(); i++)
    {
        if (!visited[i] && dist[currentCity][i] < minDist)
        {
            minDist = dist[currentCity][i];
            nearestCity = i;
        }
    }
    return nearestCity;
}
int main()
{
    // City labels (optional, for output)
    vector<char> cities = {'A', 'B', 'C', 'D'};
    // Distance matrix
    vector<vector<int>> dist = {
        {0, 1, 3, 4},
        {1, 0, 2, 6},
        {3, 2, 0, 5},
        {4, 6, 5, 0}};
    int n = dist.size();
    vector<bool> visited(n, false);
    vector<int> path;
    int start = 0; // Starting from city A
    int currentCity = start;
    int totalCost = 0;
    visited[currentCity] = true;
    path.push_back(currentCity);
    // Apply nearest neighbor heuristic
    for (int i = 1; i < n; i++)
    {
        int nextCity = findNearestCity(currentCity, dist, visited);
        totalCost += dist[currentCity][nextCity];
        currentCity = nextCity;
        visited[currentCity] = true;
        path.push_back(currentCity);
    }
    // Return to the starting city
    totalCost += dist[currentCity][start];
    path.push_back(start);
    // Output the cycle and cost
    cout << "Hamiltonian Cycle: ";
    for (int i = 0; i < path.size(); i++)
    {
        cout << cities[path[i]];
        if (i != path.size() - 1)
            cout << " -> ";
    }
    cout << endl;
    cout << "Total Cost: " << totalCost << endl;
    return 0;
}