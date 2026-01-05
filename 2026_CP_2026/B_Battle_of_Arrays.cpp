#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)(1e9+7)
#define EPS (double)1e-9

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

// ICPC stand-BY

void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n);
    vector<int> b(m);
    for (int i=0;i<n;i++) {
        cin >> a[i];
    }
    for (int i=0;i<m;i++) {
        cin >> b[i];
    }
}

int32_t main() {
    fast_io();
    int test;
    cin >> test;
    while (test--) {
        solve();
    }
    return 0;
}