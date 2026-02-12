#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MOD (int)(1e9+7)
#define EPS (double)1e-9

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

// let's DO this

// int max_digit(int x) {
//     int maxi = -MOD;
//     while(x>0) {
//         maxi = max(maxi, x%10);
//         x/=10;
//     }
//     return maxi;
// }

void solve(int n) {
    vector<int> dp(n+1, MOD);
    dp[0]=0;
    for (int i=1;i<=n;i++) {
        vector<int> digits;
        int j=i*10;
        while ((j/=10) > 0) {
            digits.push_back(j%10);
        }
        for (int digit : digits) {
            dp[i]=min(dp[i], dp[i-digit]+1);
        }
    }
    cout<<dp[n]<<endl;
    
    // without dp // SIMPLE observation
    // int count=0;
    // while (n>0) {
    //     n -= max_digit(n);
    //     count++;
    // }
    // cout<<count<<endl;
}

int32_t main() {
    fast_io();
    int n; cin >> n;
    solve(n);
    return 0;
}