#include <iostream>
#include <vector>
using namespace std;

vector<int> adj[1001];
int vis[1001];

void dfs(int node) {
    vis[node] = 1;
    // Traverse neighbors
    for (int neighbor : adj[node]) {
        if (!vis[neighbor]) {
            dfs(neighbor);
        }
    }
}

int main() {
    int V, E;
    cin >> V >> E;

    // dfs
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // vis array
    for (int i = 0; i < V; i++)  vis[i] = 0;
        int components = 0;
        
        
    for (int i = 0; i < V; i++) {
        // If node 'i' is not visited, it is the start of a NEW component
        if (vis[i] == 0) {
            components++; // Found a new component
            dfs(i);       // Visit all nodes in this component
        }
    }

    cout << components << endl;
    return 0;
}