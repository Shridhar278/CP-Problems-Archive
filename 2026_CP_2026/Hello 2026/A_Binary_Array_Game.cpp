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
    int x=0;
    for (int i=0;i<n;i++) {
        cin >> arr[i];
        if (i==0 or i==n-1) {
            if (arr[i]==1) {
                x++;
            }
        }
    }
    if (x > 0) {
        cout<<"Alice"<<endl;
    } else {
        cout<<"Bob"<<endl;
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