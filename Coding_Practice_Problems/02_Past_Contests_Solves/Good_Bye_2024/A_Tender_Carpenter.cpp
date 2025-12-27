#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)(1e9+7)
#define EPS (double)1e-9

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    int n; cin >> n;
    vector<int> arr(n);
    for (int i=0;i<n;i++) {
        cin >> arr[i];
    }
    // contigous !
    // sort(arr.begin(), arr.end());
    for (int i=1;i<n;i++) {
        int mn = min(arr[i-1], arr[i]);
        int mx = max(arr[i-1], arr[i]);
        if (mx < 2*mn) {
            cout<<"YES"<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
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