#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MOD (int)(1e9+7)
#define EPS (double)1e-9

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

// CODE : BLANK
// ACCEPTED

void solve() {
    int n; cin >> n;
    vector<int> arr(n);
    int maxi=-MOD, mini=MOD;
    for (int i=0;i<n;i++) {
        cin >> arr[i];
        maxi = max(arr[i], maxi);
        mini = min(arr[i], mini);
    }
    vector<int> sorted=arr;
    int best=MOD;
    sort(sorted.begin(), sorted.end());
    for (int i=0;i<n;i++) {
        int x = abs(arr[i]-mini), y = abs(arr[i]-maxi);
        if (sorted[i]!=arr[i]) {
            best = min(best, max(x, y));
        }
    }
    if (best==MOD or best < 1) {
        best=-1;
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