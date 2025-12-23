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
    // can get SHORTER code from EDITORIAL !
    int n; cin >> n;
    // like this
    // 111
    // 011
    // 001
    // 101 .. a bit complicated
    // 000
    // ... then incr order

    // the pre ZERO phase
    for (int bits=n;bits>=1;bits--) {
        if (bits==n) {
            cout<<(1<<n)-1<<" ";
        } else {
            for (int count=0;count<(int)pow(2, n-bits);count++) {
                if (count%2==0) {
                    cout<<(count<<bits)+(1<<bits)-1<<" ";
                }
            }
        }
    }
    // ZERO
    cout<<0<<" ";
    // post ZERO
    for (int i=2;i<(1<<n);i++) {
        if (i%2==0) {
            cout<<i<<" ";
        }
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