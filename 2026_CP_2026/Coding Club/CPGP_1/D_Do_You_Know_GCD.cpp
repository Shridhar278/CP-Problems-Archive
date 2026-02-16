#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MOD (int)(1e9+7)
#define EPS (double)1e-9

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

// SIMPLE observation for SWAP

void solve() {
    int n; cin >> n;
    vector<int> arr(n);
    int mini = MOD;
    for (int i=0;i<n;i++) {
        cin >> arr[i];
        mini = min(mini, arr[i]);
    }
    vector<int> sorted=arr;
    sort(sorted.begin(), sorted.end());
    int possible=1;
    for (int i=0;i<n;i++) {
        if (arr[i]!=sorted[i]) {
            if (sorted[i]%mini!=0) {
                possible=0;
            }
        }
    }
    if (possible) {
        cout<<"YES"<<endl;
    } else {
        cout<<"NO"<<endl;
    }
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