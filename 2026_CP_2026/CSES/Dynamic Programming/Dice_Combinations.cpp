#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MOD (int)(1e9+7)
#define EPS (double)1e-9

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

// dp PRACTICE

void solve() {
    int n; cin >> n;
    int dice[6] = {1,2,3,4,5,6};
    vector<int> ways(n+1, 0);
    ways[0]=1; // 1 way do nothing
    for (int i=1;i<=n;i++) {
        for (int val : dice) {
            if (i-val>=0) {
                ways[i]+=ways[i-val];
                ways[i]%=MOD;
            }
        }
    }
    cout<<ways[n]<<endl;
}

int32_t main() {
    fast_io();
    solve();
    return 0;
}