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
    for (int &i: coins) {
        cin >> i;
    }
    vector<int> min_coins(x+1, MOD);
    min_coins[0]=0;
    for (int i=1;i<=x;i++) {
        for (int coin : coins) {
            if (i-coin>=0) {
                min_coins[i]=min(min_coins[i-coin]+1, min_coins[i]);
            }
        }
    }
    if (min_coins[x]==MOD) {
        min_coins[x]=-1;
    }
    cout<<min_coins[x]<<endl;
}

int32_t main() {
    fast_io();
    solve();
    return 0;
}