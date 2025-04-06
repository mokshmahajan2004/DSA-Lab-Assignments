#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;
void dijkstra(int src, int dest, vector<vector<pii>> &adj, int V)
{
    vector<int> dist(V, INT_MAX);
    vector<int> parent(V, -1);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[src] = 0;
    pq.push({0, src});
    while (!pq.empty())
    {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        if (u == dest)
            break; // Early stop if destination is reached
        for (auto &p : adj[u])
        {
            int v = p.first;
            int w = p.second;
            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }
    if (dist[dest] == INT_MAX)
    {
        cout << "No path from " << src << " to " << dest << endl;
        return;
    }
    // Reconstruct path
    vector<int> path;
    for (int at = dest; at != -1; at = parent[at])
        path.push_back(at);
    reverse(path.begin(), path.end());
    cout << "Shortest path from " << src << " to " << dest << ": ";
    for (int node : path)
        cout << node << " ";
    cout << "\nTotal distance: " << dist[dest] << endl;
}
int main()
{
    int V = 7;
    vector<vector<pii>> adj(V);
    // Add edges (undirected graph)
    adj[0].push_back({1, 2});
    adj[1].push_back({0, 2});
    adj[0].push_back({2, 6});
    adj[2].push_back({0, 6});
    adj[1].push_back({3, 5});
    adj[3].push_back({1, 5});
    adj[2].push_back({3, 8});
    adj[3].push_back({2, 8});
    adj[3].push_back({4, 10});
    adj[4].push_back({3, 10});
    adj[3].push_back({5, 15});
    adj[5].push_back({3, 15});
    adj[4].push_back({6, 2});
    adj[6].push_back({4, 2});
    adj[5].push_back({6, 6});
    adj[6].push_back({5, 6});
    int source = 1, destination = 6;
    dijkstra(source, destination, adj, V);
    return 0;
}
