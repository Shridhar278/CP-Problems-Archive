#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MOD (int)(1e9+7)
#define EPS (double)1e-9

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

// EAZY

void solve() {
    int n; cin >> n;
    int x;
    for (x=2;x<=26;x++) {
        if (n%x!=0) {
            break;
        }
    }
    for (int i=0;i<n;i++) {
        cout<<char('a'+i%x);
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