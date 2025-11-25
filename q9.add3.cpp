#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {

    int n, m, k;
    cin >> n >> m >> k;

    vector<pair<int,int>> adj[n+1];  // directed

    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    const int INF = 1e9;
    vector<int> dist(n+1, INF);

    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > pq;

    dist[k] = 0;
    pq.push({0, k});

    while(!pq.empty()) {

        int timeTaken = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if(timeTaken > dist[node]) continue;

        for(auto it : adj[node]) {
            int next = it.first;
            int wt   = it.second;

            int newTime = timeTaken + wt;

            if(newTime < dist[next]) {
                dist[next] = newTime;
                pq.push({newTime, next});
            }
        }
    }

    int ans = 0;

    for(int i = 1; i <= n; i++) {
        if(dist[i] == INF) {
            cout << -1;
            return 0;
        }
        ans = max(ans, dist[i]);
    }

    cout << ans;
    return 0;
}
