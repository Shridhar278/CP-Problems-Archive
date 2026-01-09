#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MOD (int)(1e9+7)
#define EPS (double)1e-9

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

//ez

void solve() {
    int n, k; cin >> n >> k;
    vector<int> arr(n);
    for (int i=0;i<n;i++) {
        cin >> arr[i];
    }
    // first check
    int fail=-1;
    for (int i=1;i<=k;i++) {
        if (arr[i]<arr[i-1]/2+1) {
            fail=i;
        }
    }
    int count=0;
    if (fail==-1) {
        count++;
    }
    for (int j=k+1;j<n;j++) {
        if (arr[j]<arr[j-1]/2+1) {
            fail=j;
        } else if (j-k>=fail) {
            count++;
        }
    }
    cout<<count<<endl;
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