#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MOD (int)(1e9+7)
#define EPS (double)1e-9

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    int x; cin >> x;
    if (x<11) {
        cout<<"NO"<<endl;
    } else if (x<1111 and x/111<x%11) {
        cout<<"NO"<<endl;
    } else {
        cout<<"YES"<<endl;
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