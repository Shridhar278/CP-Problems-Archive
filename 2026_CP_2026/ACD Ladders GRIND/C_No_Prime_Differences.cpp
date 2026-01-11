#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MOD (int)(1e9+7)
#define EPS (double)1e-9

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

// watching editorial

// CORRECT instincts
// 1-2-3-4-5
// 3-1-4-2-5
// 1-2-3-4-5-6-7
// 4-1-5-2-6-3-7
// NICEE

void solve() {
    int n, m; cin >> n >> m;
    int start;
    for (int i=1;i<=n;i++) {
        if (i%2) {
            start=(n/2+i/2)*m;
            for (int j=1;j<=m;j++) {
                cout<<start+j<<" ";
            }
        } else {
            start=(i/2-1)*m;
            for (int j=1;j<=m;j++) {
                cout<<start+j<<" ";
            }
        }
        cout<<endl;
    }
    cout<<endl;
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