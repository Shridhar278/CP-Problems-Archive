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
    int diff = 0, change = -INF;
    for (int i=0;i<n;i++) {
        if (i!=0) {
            diff += abs(arr[i]-arr[i-1]);
        }
        // can shorten this code
        if (i==0) {
            if (abs(arr[0]-arr[1]) > change) {
                change = abs(arr[0]-arr[1]);
            }
        } else if (i==n-1)  {
            if (abs(arr[n-1]-arr[n-2]) > change) {
                change = abs(arr[n-1]-arr[n-2]);
            }
        } else {
            if (abs(2*arr[i]-arr[i-1]-arr[i+1])-abs(arr[i-1]-arr[i+1]) > change) {
                change = abs(2*arr[i]-arr[i-1]-arr[i+1])-abs(arr[i-1]-arr[i+1]);
            }
        }
    }
    cout << diff - change << endl;
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