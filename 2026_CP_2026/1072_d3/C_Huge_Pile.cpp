#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MOD (int)(1e9+7)
#define EPS (double)1e-9

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

// elegant
// this and the solution with x=x/2 continously
// are identical cuz. binary representation.

void solve() {
    int n, k; cin >> n >> k;
    int x=n, r=0;
    int count=0;
    while (x >= k) {
        if (n%(1<<count)==0) {
            r=0;
        } else {
            r=1;
        }
        x = n/(1<<count);
        if (k==x or k==x+r) {
            cout<<count<<endl;
            return;
        }
        count++;
    }
    cout<<-1<<endl;
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