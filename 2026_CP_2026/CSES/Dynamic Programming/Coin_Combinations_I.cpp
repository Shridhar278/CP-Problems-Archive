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
    int n, x; cin >> n >> x;
    vector<int> coins(n);
    for (int &i : coins) {
        cin >> i;
    }
    vector<int> ways(x+1, 0);
    ways[0]=1; // 1 way do nothing
    for (int i=1;i<=x;i++) {
        for (int val : coins) {
            if (i-val>=0) {
                ways[i]+=ways[i-val];
                ways[i]%=MOD;
            }
        }
    }
    cout<<ways[x]<<endl;
    
}

int32_t main() {
    fast_io();
    solve();
    return 0;
}