#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
struct Edge
{
    int u, v, w;
};
// ---------- Kruskal's Helper Functions ----------
bool cmp(Edge a, Edge b)
{
    return a.w < b.w;
}
int find(int u, vector<int> &parent)
{
    if (parent[u] != u)
        parent[u] = find(parent[u], parent);
    return parent[u];
}
void unionSet(int u, int v, vector<int> &parent, vector<int> &rank)
{
    int pu = find(u, parent);
    int pv = find(v, parent);
    if (pu != pv)
    {
        if (rank[pu] < rank[pv])
            parent[pu] = pv;
        else if (rank[pu] > rank[pv])
            parent[pv] = pu;
        else
        {
            parent[pv] = pu;
            rank[pu]++;
        }
    }
}
// ---------- Prim’s Algorithm ----------
void prim(int V, vector<vector<pair<int, int>>> &adj)
{
    vector<int> key(V, INT32_MAX);
    vector<bool> inMST(V, false);
    vector<int> parent(V, -1);
    key[0] = 0;
    for (int count = 0; count < V - 1; ++count)
    {
        int u = -1;
        for (int i = 0; i < V; ++i)
            if (!inMST[i] && (u == -1 || key[i] < key[u]))
                u = i;

        inMST[u] = true;
        for (auto &p : adj[u])
        {
            int v = p.first;
            int w = p.second;
            if (!inMST[v] && w < key[v])
            {
                key[v] = w;
                parent[v] = u;
            }
        }
    }
    cout << "\nPrim’s MST Edges:\n";
    int totalWeight = 0;
    for (int i = 1; i < V; ++i)
    {
        cout << parent[i] + 1 << " - " << i + 1 << endl;
        totalWeight += key[i];
    }
    cout << "Total Weight: " << totalWeight << endl;
}
// ---------- Kruskal’s Algorithm ----------
void kruskal(int V, vector<Edge> &edges)
{
    sort(edges.begin(), edges.end(), cmp);
    vector<int> parent(V), rank(V, 0);
    for (int i = 0; i < V; ++i)
        parent[i] = i;

    cout << "\nKruskal’s MST Edges:\n";
    int totalWeight = 0;
    for (auto &e : edges)
    {
        if (find(e.u, parent) != find(e.v, parent))
        {
            cout << e.u + 1 << " - " << e.v + 1 << endl;
            totalWeight += e.w;
            unionSet(e.u, e.v, parent, rank);
        }
    }
    cout << "Total Weight: " << totalWeight << endl;
}
int main()
{
    int V = 5;
    // Adjacency list for Prim's (0-indexed)
    vector<vector<pair<int, int>>> adj(V);
    adj[0].push_back({1, 5});
    adj[1].push_back({0, 5});
    adj[0].push_back({2, 2});
    adj[2].push_back({0, 2});
    adj[1].push_back({2, 4});
    adj[2].push_back({1, 4});
    adj[1].push_back({4, 1});
    adj[4].push_back({1, 1});
    adj[2].push_back({3, 6});
    adj[3].push_back({2, 6});
    adj[3].push_back({4, 3});
    adj[4].push_back({3, 3});
    // Edge list for Kruskal's
    vector<Edge> edges = {
        {0, 1, 5},
        {0, 2, 2},
        {1, 2, 4},
        {1, 4, 1},
        {2, 3, 6},
        {3, 4, 3}};
    prim(V, adj);
    kruskal(V, edges);
    return 0;
}
