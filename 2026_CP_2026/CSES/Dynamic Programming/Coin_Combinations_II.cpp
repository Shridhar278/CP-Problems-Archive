#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MOD (int)(1e9+7)
#define EPS (double)1e-9

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

// ok that's SMART
// gaining KNOWLEDGE

void solve() {
    int n, x; cin >> n >> x;
    vector<int> coins(n);
    for (int& i: coins) {
        cin >> i;
    }
    sort(coins.begin(), coins.end());
    // learning
    // do this
    vector<int> dp(x+1, 0);
    dp[0]=1;
    for (int coin : coins) {
        for (int s=coin;s<=x;s++) {
            dp[s]+=dp[s-coin];
            dp[s]%=MOD;
        }
    }
    cout<<dp[x]<<endl;
}

int32_t main() {
    fast_io();
    solve();
    return 0;
}