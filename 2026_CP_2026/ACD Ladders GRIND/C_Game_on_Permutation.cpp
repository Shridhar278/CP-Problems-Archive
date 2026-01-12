#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MOD (int)(1e9+7)
#define EPS (double)1e-9

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

// Happy New Year EZ

void solve() {
    int n; cin >> n;
    vector<int> permut(n);
    for (int i=0;i<n;i++) {
        cin >> permut[i];
    }
    int loss_min=permut[0], win_min=MOD;
    int wins=0;
    for (int i=1;i<n;i++) {
        if (permut[i]>win_min) {
            //redundant
            // loss_min = min(loss_min, permut[0]);
        } else if (permut[i]>loss_min) {
            win_min = permut[i];
            wins++;
        } else {
            loss_min = permut[i];
        }
    }
    cout<<wins<<endl;
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