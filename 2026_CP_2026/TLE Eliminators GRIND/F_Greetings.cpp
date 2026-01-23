#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MOD (int)(1e9+7)
#define EPS (double)1e-9

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

bool isSubset(int a1, int b1, int a2, int b2) {
    if (a1<a2 and b2<b1) {
        return 1;
    } else {
        return 0;
    }
}

void solve() {
    int n; cin >> n;
    vector<vector<int>> relations;
    // sub-sets
    // graphs
    
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