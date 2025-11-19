#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){
    int n, m; //n = nodes, m = edges
    cin >> n;
    cin>> m;


    vector<int> adj[n + 1];   // adjacency list

    // input edges
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v); //add u to adj list of v
        adj[v].push_back(u);   // undirected
    }

    int start; //starting node
    cin >> start;              

    vector<int> vis(n + 1, 0); //visited array created of size n+1 initialized to 0, when 1 means visited
    queue<int> q;

    // start BFS
    vis[start] = 1;
    q.push(start);

    while(!q.empty()){
        int node = q.front();
        q.pop();

        cout << node << " ";   // print BFS order

        for(int x : adj[node]){
            if(vis[x] == 0){
                vis[x] = 1;
                q.push(x);
            }
        }
    }

    return 0;
}
