#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, wt;
};

int findParent(int node, vector<int> &parent) {
    if (parent[node] == node)
        return node;

    return parent[node] = findParent(parent[node], parent); 
}

void unionSet(int a, int b, vector<int> &parent, vector<int> &rank) {
    a = findParent(a, parent);
    b = findParent(b, parent);

    if (a == b) return;

    if (rank[a] < rank[b]) {
        parent[a] = b;
    }
    else if (rank[b] < rank[a]) {
        parent[b] = a;
    }
    else {
        parent[b] = a;
        rank[a]++;
    }
}

int main() {

    int n, m;
    cin >> n >> m;

    vector<Edge> edges;

    // input edges
    for (int i = 0; i < m; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;
        edges.push_back({u, v, wt});
    }

    // sort edges by weight
    sort(edges.begin(), edges.end(), 
        [](Edge &a, Edge &b) {
            return a.wt < b.wt;
        }
    );

    vector<int> parent(n), rank(n, 0);

    // initialize DSU
    for (int i = 0; i < n; i++)
        parent[i] = i;

    int totalCost = 0;

    for (auto &e : edges) {
        int pu = findParent(e.u, parent);
        int pv = findParent(e.v, parent);

        if (pu != pv) {
            totalCost += e.wt;
            unionSet(pu, pv, parent, rank);
        }
    }

    cout << totalCost;

    return 0;
}
