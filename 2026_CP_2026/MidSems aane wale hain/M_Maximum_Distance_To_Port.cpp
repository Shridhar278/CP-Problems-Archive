#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MOD (int)(1e9+7)
#define EPS (double)1e-9

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

// Redemption Time 
// Life COMES full circle
// ACCEPTED

// breadth first search // not depth first search
void traverse(vector<vector<int>>& distance, vector<vector<int>>& connections,
     vector<int> nodes, int level, int n, int count) {
    vector<int> new_nodes;
    for (auto node : nodes) {
        // cout<<node<<level<<endl;
        for (auto connection : connections[node]) {
            if (distance[connection][1]==0) {
                distance[connection][1]=1;
                distance[connection][0]=level+1;
                new_nodes.push_back(connection);
            }
        }
    }
    count+=(int)new_nodes.size();
    if (count==n) {
        return;
    } else {
        traverse(distance, connections, new_nodes, level+1, n, count);
    }
}

void solve() {
    int n, m, k; cin >> n >> m >> k;
    vector<int> vertices(n); // vertices 
    vector<vector<int>> connections(n, vector<int>()); // edges
    for (int i=0;i<n;i++) { // take vertices
        cin >> vertices[i];
    }
    int x, y;
    for (int i=0;i<m;i++) { // take edges
        cin >> x >> y;
        connections[x-1].push_back(y-1);
        connections[y-1].push_back(x-1);
    }
    // traverse Breadth-First-Search
    vector<vector<int>> distance(n, vector<int>(2, 0)); // distance // color
    distance[0][1]=1;
    traverse(distance, connections, {0}, 0, n, 1);
    vector<int> solution(k+1, (int)0);
    for (int i=0;i<n;i++) {
        solution[vertices[i]]=max(solution[vertices[i]], distance[i][0]);
    }
    for (int i=1;i<=k;i++) {
        cout<<solution[i]<<" ";
    }
    cout<<endl;
}

int32_t main() {
    fast_io();
    solve();
    return 0;
}