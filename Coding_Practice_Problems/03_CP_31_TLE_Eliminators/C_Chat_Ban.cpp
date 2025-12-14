#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)(1e9+7)
#define EPS (double)1e-9

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve(int k, int x) {
    //out of bounds
    if (x >= k*k) {
        cout<<2*k-1<<endl;
        return;
    } else if (x >= k*(k+1)/2) {
        
    }
}

int32_t main() {
    fast_io();
    int test;
    cin >> test;
    while (test--) {
        int k, x; cin >> k >> x;
        solve(k, x);
    }
    return 0;
}