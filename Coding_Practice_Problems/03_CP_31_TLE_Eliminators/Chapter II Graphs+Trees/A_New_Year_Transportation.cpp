#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)(1e9+7)
#define EPS (double)1e-9

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    
}

int32_t main() {
    fast_io();
    int test;
    cin >> test;
    while (test--) {
        int n, k; cin >> n >> k;
        vector<int> arr(n);
        for (int i=0;i<n;i++) {
            cin >> arr[i];
        }
        solve();
    }
    return 0;
}