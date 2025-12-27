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
    int n, k, q; cin >> n >> k >> q;
    vector<int> temps(n);
    for (int i=0;i<n;i++) {
        cin >> temps[i];
    }
    int count=0;
    int x;
    int ways=0;
    for (int i=0;i<n;i++) {
        if (temps[i]<=q) {
            count++;
        } else {
            if (count>=k) {
                x=count-k+1;
                ways += (x*(x+1))/2;
            }
            count=0;
        }
    }
    if (count>=k) {
        x=count-k+1;
        ways += (x*(x+1))/2;
    }
    cout<<ways<<endl;
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