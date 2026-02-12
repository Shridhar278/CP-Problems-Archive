#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MOD (int)(1e9+7)
#define EPS (double)1e-9

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

// Memory Problems
// will do

void solve() {
    int n, x; cin >> n >> x;
    vector<int> price(n); for (int& i: price) cin >> i;
    vector<int> pages(n); for (int& i: pages) cin >> i;
    // A GREEDY problematic DP
    // vector<vector<int>> dp(x+1, vector<int>(n+1, 0));
    // for (int i=1;i<=x;i++) {
    //     int best=dp[i-1][0]; int maxi=0;
    //     for (int j=1;j<n+1;j++) {
    //         if (i-price[j-1]<0) {
    //             continue;
    //         }
    //         if (dp[i-price[j-1]][j]==0) {
    //             if (best < dp[i-price[j-1]][0]+pages[j-1]) {
    //                 maxi = j;
    //                 best = dp[i-price[j-1]][0]+pages[j-1];
    //             }
    //         }
    //         // cout<<dp[i][j]<<endl;
    //     }
    //     if (maxi==0) {
    //         continue;
    //     }
    //     dp[i]=dp[i-price[maxi-1]];
    //     dp[i][maxi]=1;
    //     // cout<<"$"<<best[0]<<endl;
    // }
    // cout<<dp[x][0]<<endl;

    // understanding
    // DP
}

int32_t main() {
    fast_io();
    solve();
    return 0;
}