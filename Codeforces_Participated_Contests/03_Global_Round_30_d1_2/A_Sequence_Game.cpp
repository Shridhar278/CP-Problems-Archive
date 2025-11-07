#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e9+7
#define EPS (double)1e-9

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

int32_t main() {
    fast_io();
    int test;
    cin >> test;
    while (test--) {
        int n, k, mx=-INF, mn=+INF;
        cin >> n;
        for (int i=0;i<n;i++) {
            cin>>k;
            if (k >= mx) {
                mx = k;
            }
            if (k <= mn) {
                mn = k;
            }
        }
        int x; cin >> x;
        if (x >= mn && x <= mx) {
            cout<<"YES"<<endl;
        } else {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}