#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MOD (int)(1e9+7)
#define EPS (double)1e-9

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

// HAVING a GOOD DAY
// intution : check sub-arrays of length 2&3 only;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> arr(n);
    for (int i=0;i<n;i++) {
        cin >> arr[i];
    }
    int best=-1;
    for (int i=0;i<n-1;i++) {
        best = max(best, min(arr[i], arr[i+1]));
    }
    for (int i=0;i<n-2;i++) {
        int least = min({arr[i], arr[i+1], arr[i+2]});
        int limit = arr[i]+arr[i+1]+arr[i+2]-max({arr[i], arr[i+1], arr[i+2]})-least;
        best = max(best, min(limit, least+k));
    }
    cout<<best<<endl;
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