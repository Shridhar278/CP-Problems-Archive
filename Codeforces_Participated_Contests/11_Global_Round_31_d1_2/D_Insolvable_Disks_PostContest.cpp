#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)(1e9+7)
#define EPS (double)1e-9

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve(int n, vector<int> disk) {
    // may be out OF my league RIGHT NOW est. 1700-1800
    
}

int32_t main() {
    fast_io();
    int test;
    cin >> test;
    while (test--) {
        int n; cin >> n;
        vector<int> disk(n);
        for (int i=0;i<n;i++) {
            cin>>disk[i];
        }
        solve(n, disk);
    }
    return 0;
}