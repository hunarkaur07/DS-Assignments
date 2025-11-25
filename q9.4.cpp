#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {

    int n, m;
    cin >> n >> m;

    vector<pair<int,int>> adj[100];

    for(int i = 0; i < m; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});   // remove for directed graph
    }

    int src;
    cin >> src;

    const int INF = 1000000000;
    vector<int> dist(n+1, INF);
    vector<int> vis(n+1, 0);

    // min-heap: {dist, node}
    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > pq;

    dist[src] = 0;
    pq.push({0, src});

    while(!pq.empty()) {

        int node = pq.top().second;
        pq.pop();

        if(vis[node]) continue;
        vis[node] = 1;

        for(auto it : adj[node]) {
            int next = it.first;
            int wt   = it.second;

            if(dist[node] + wt < dist[next]) {
                dist[next] = dist[node] + wt;
                pq.push({dist[next], next});
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        cout << "Distance from " << src << " to " 
             << i << " = " << dist[i] << endl;
    }

    return 0;
}
