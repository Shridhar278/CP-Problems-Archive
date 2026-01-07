#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)(1e9+7)
#define EPS (double)1e-9

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

// NICE reverse ENGINEERING

// straight way is GREAT too
// n = n- n/y; x times
// do binary search as MONOTONIC (fantastic thought)

void solve() {
    int x, y, k; cin >> x >> y >> k;
    int ans = k, extra=0;
    if (y==1) {
        cout<<-1<<endl;
        return;1
    }
    for (int i=0;i<x;i++) {
        if (ans%(y-1)==0) {
            extra=1;
        }
        ans = (ans/(y-1))*y+ans%(y-1);
        ans-=extra;
        extra=0;
        if (ans > pow(10, 12)) {
            cout<<-1<<endl;
            return;
        }
    }
    cout<<ans<<endl;
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