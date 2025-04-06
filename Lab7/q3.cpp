#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// DFS traversal
void dfs(int node, vector<vector<int>> &adjMatrix, vector<bool> &visited)
{
    visited[node] = true;
    cout << node + 1 << " "; // Convert to 1-based indexing for display
    for (int i = 0; i < adjMatrix.size(); i++)
    {
        if (adjMatrix[node][i] == 1 && !visited[i])
        {
            dfs(i, adjMatrix, visited);
        }
    }
}
// BFS traversal
void bfs(int start, vector<vector<int>> &adjMatrix, vector<bool> &visited)
{
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cout << node + 1 << " "; // Convert to 1-based indexing

        for (int i = 0; i < adjMatrix.size(); i++)
        {
            if (adjMatrix[node][i] == 1 && !visited[i])
            {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}
// Cycle detection using DFS in undirected graph
bool dfsCycleDetect(int node, int parent, vector<vector<int>> &adjMatrix, vector<bool> &visited)
{
    visited[node] = true;

    for (int i = 0; i < adjMatrix.size(); i++)
    {
        if (adjMatrix[node][i])
        {
            if (!visited[i])
            {
                if (dfsCycleDetect(i, node, adjMatrix, visited))
                    return true;
            }
            else if (i != parent)
            {
                return true; // Found a back edge (cycle)
            }
        }
    }
    return false;
}
bool containsCycle(vector<vector<int>> &adjMatrix)
{
    int n = adjMatrix.size();
    vector<bool> visited(n, false);

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            if (dfsCycleDetect(i, -1, adjMatrix, visited))
                return true;
        }
    }
    return false;
}
int main()
{
    int n = 7;
    vector<vector<int>> adjMatrix = {
        {0, 1, 0, 1, 0, 0, 0}, // Vertex 1
        {1, 0, 1, 0, 0, 0, 0}, // Vertex 2
        {0, 1, 0, 1, 1, 0, 0}, // Vertex 3
        {1, 0, 1, 0, 0, 0, 0}, // Vertex 4
        {0, 0, 1, 0, 0, 1, 1}, // Vertex 5
        {0, 0, 0, 0, 1, 0, 0}, // Vertex 6
        {0, 0, 0, 0, 1, 0, 0}  // Vertex 7
    };
    // DFS Traversal
    vector<bool> visitedDFS(n, false);
    cout << "DFS Traversal: ";
    dfs(0, adjMatrix, visitedDFS); // Start from vertex 1 (0-indexed)
    cout << endl;
    // BFS Traversal
    vector<bool> visitedBFS(n, false);
    cout << "BFS Traversal: ";
    bfs(0, adjMatrix, visitedBFS); // Start from vertex 1 (0-indexed)
    cout << endl;
    // Cycle Detection
    if (containsCycle(adjMatrix))
    {
        cout << "The graph contains a cycle." << endl;
    }
    else
    {
        cout << "The graph does not contain a cycle." << endl;
    }

    return 0;
}
