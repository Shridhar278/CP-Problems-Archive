#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MOD (int)(1e9+7)
#define EPS (double)1e-9

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

// simple SIMULATION

void solve() {
    int n; cin >> n;
    vector<int> arr(n+1);
    for (int i=0;i<n;i++) {
        cin >> arr[i+1];
    }
    int gods=1, i=1, best=arr[i];
    while(i<=n) {
        best = max(best, arr[i]);
        if (best > i) {
            i++;
        } else {
            if (i==n) {
                break;
            }
            gods+=i+1-best;
            best = i+1;
            i++;
        }
    }
    cout<<gods<<endl;
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