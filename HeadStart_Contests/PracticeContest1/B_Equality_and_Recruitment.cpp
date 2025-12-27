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
    double avg = 0;
    vector<int> arr(n);
    for (int i=0;i<n;i++) {
        cin >> arr[i];
        avg += arr[i];
    }
    avg /= n;
    for (int i=0;i<n;i++) {
        if (arr[i]==avg) {
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