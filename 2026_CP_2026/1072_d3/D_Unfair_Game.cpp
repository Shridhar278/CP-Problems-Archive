#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MOD (int)(1e9+7)
#define EPS (double)1e-9

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

// logic error

void solve() {
    int n, k; cin >> n >> k;
    vector<int> seq={1, 2, 4};
    int i=2;
    if (i+1>k) {
        cout<<max(n-seq[k-1], (int)0)<<endl;
        return;
    }
    while (seq[i] < n) {
        if (i+1==k) {
            cout<<n-seq[k-1]<<endl;
            return;
        }
        seq.push_back(2*seq[i]-seq[i-2]);
        i++;
    }
    cout<<0<<endl;
    return;
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