#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)(1e9+7)
#define EPS (double)1e-9

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve(int n, int k) {
    if (k%2==1) {
        for (int i=0;i<n;i++) {
            if (i==n-1) {
                cout<<n-1<<" ";
                continue;
            }
            cout<<n<<" ";
        }
    } else {
        for (int i=0;i<n;i++) {
            if (i==n-2) {
                cout<<n<<" ";
                continue;
            }
            cout<<n-1<<" ";
        }
    }
    cout<<endl;
}

int32_t main() {
    fast_io();
    int test;
    cin >> test;
    while (test--) {
        int n, k; cin >> n >> k;
        solve(n, k);
    }
    return 0;
}