#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// Depth First Search
void dfs(int node, vector<vector<int>> &adjMatrix, vector<bool> &visited)
{
    visited[node] = true;
    for (int i = 0; i < adjMatrix.size(); i++)
    {
        if (adjMatrix[node][i] == 1 && !visited[i])
        {
            dfs(i, adjMatrix, visited);
        }
    }
}
// Breadth First Search
void bfs(int start, vector<vector<int>> &adjMatrix, vector<bool> &visited)
{
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

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
int countComponentsDFS(vector<vector<int>> &adjMatrix)
{
    int n = adjMatrix.size();
    vector<bool> visited(n, false);
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs(i, adjMatrix, visited);
            count++;
        }
    }
    return count;
}
int countComponentsBFS(vector<vector<int>> &adjMatrix)
{
    int n = adjMatrix.size();
    vector<bool> visited(n, false);
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            bfs(i, adjMatrix, visited);
            count++;
        }
    }
    return count;
}
int main()
{
    int n = 7;
    vector<vector<int>> adjMatrix = {
        {0, 1, 0, 1, 0, 0, 0}, // Node 0 (Vertex 1)
        {1, 0, 1, 0, 0, 0, 0}, // Node 1 (Vertex 2)
        {0, 1, 0, 1, 1, 0, 0}, // Node 2 (Vertex 3)
        {1, 0, 1, 0, 0, 0, 0}, // Node 3 (Vertex 4)
        {0, 0, 1, 0, 0, 1, 1}, // Node 4 (Vertex 5)
        {0, 0, 0, 0, 1, 0, 0}, // Node 5 (Vertex 6)
        {0, 0, 0, 0, 1, 0, 0}  // Node 6 (Vertex 7)
    };
    cout << "Number of connected components (DFS): " << countComponentsDFS(adjMatrix) << endl;
    cout << "Number of connected components (BFS): " << countComponentsBFS(adjMatrix) << endl;
    return 0;
}
