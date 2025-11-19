#include<iostream>
#include<vector>
using namespace std;

vector<int> adj[1001];   // adjacency list
int vis[1001];           // visited array

void dfs(int node){
    vis[node] = 1;
    cout << node << " ";   // print node

    // visit neighbors using traditional loop
    for(int i = 0; i < adj[node].size(); i++){
        int x = adj[node][i];
        if(vis[x] == 0){
            dfs(x);
        }
    }
}

int main(){
    int n, m;  // n = nodes, m = edges
    cin >> n >> m;

    // input edges (undirected)
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int start;
    cin >> start;  // starting node for DFS

    // initialize visited array with 0
    for(int i = 1; i <= n; i++){
        vis[i] = 0;
    }

    // call dfs
    dfs(start);

    return 0;
}
