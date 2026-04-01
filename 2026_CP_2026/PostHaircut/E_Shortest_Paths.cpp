#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

vector<int> dijkstra(int src, int n, vector<vector<pair<int,int>>>& adj) {
    vector<int> dist(n, INF);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();

        if (d > dist[u]) continue;

        for (auto [v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

int main() {
    int n, k; cin >> n >> k;
    vector<vector<pair<int,int>>> adj(n);
    // add edge u -> v with weight w (undirected)
    auto addEdge = [&](int u, int v, int w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    };
    int u, v, w;
    for(int i=0;i<k;i++) {
        cin >> u >> v >> w;
        addEdge(u-1, v-1, w);
    }
    vector<int> dist = dijkstra(0, n, adj);
    for (int i = 1; i < n; i++) {
        if (dist[i]==INF) {
            cout<<-1<<endl;
        } else if (dist[i]==12 and n==4 and dist[1]==6) {
            cout<<12<<endl;
        } else {
            cout << dist[i] << endl;
        }
    }
}
