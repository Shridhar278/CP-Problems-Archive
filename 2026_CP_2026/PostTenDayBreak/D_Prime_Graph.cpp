#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MOD (int)(1e9+7)
#define EPS (double)1e-9

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

// IT WORKS...
// there always exists a prime between n and n+n/2 for n belongs 3,4,5,...,1000 

void solve() {
    int n; cin >> n;
    vector<vector<int>> edges;
    for (int i=1;i<=n;i++) {
        edges.push_back({i, i == n-1 ? n : (i+1)%n});
    }
    int i;
    int prime;
    for (i=n;i<n+n/2;i++) {
        prime=1;
        for (int j=2;j<=sqrt(i);j++) {
            if (i%j==0) {
                prime=0;
                break;
            }
        }
        edges.push_back({(i+1)%n, (i+1)%n + n/2});
        if (prime) {
            break;
        }
    }
    if (prime==0) {
        cout<<-1<<endl;
    }
    cout<<i<<endl;
    for (int j=0;j<i;j++) {
        cout<<edges[j][0]<<" "<<edges[j][1]<<endl;
    }
}

int32_t main() {
    fast_io();
    solve();
    return 0;
}