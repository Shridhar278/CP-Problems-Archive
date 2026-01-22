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
    int n; cin >> n;
    int ans=0;
    map<int, int> X;
    map<int, int> Y;
    map<int, int> XplusY;
    map<int, int> XminusY;
    int x, y;
    for (int i=0;i<n;i++) {
        cin >> x >> y;
        X[x]++; Y[y]++; XplusY[x+y]++; XminusY[x-y]++;
    }
    for (auto it: X) { ans+=(it.second)*(it.second-1); }
    for (auto it: Y) { ans+=(it.second)*(it.second-1); }
    for (auto it: XplusY) { ans+=(it.second)*(it.second-1); }
    for (auto it: XminusY) { ans+=(it.second)*(it.second-1); }
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