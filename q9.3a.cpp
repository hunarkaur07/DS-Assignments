#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {

    int n, m;
    cin >> n >> m;

    vector<pair<int,int>> adj[100];  // adjacency list

    for(int i = 0; i < m; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    vector<int> vis(n, 0);

    // min-heap: {weight, node}
    priority_queue< pair<int,int>,
                    vector<pair<int,int>>,
                    greater<pair<int,int>> > pq;

    pq.push({0, 0}); // start from node 0
    int totalCost = 0;

    while(!pq.empty()) {

        int wt = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if(vis[node])
            continue;

        vis[node] = 1;
        totalCost += wt;

        for(auto it : adj[node]) {
            int next = it.first;
            int w = it.second;

            if(!vis[next]) {
                pq.push({w, next});
            }
        }
    }

    cout << totalCost;
    return 0;
}
