#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e9+7

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

int32_t main() {
    fast_io();
    int test;
    cin >> test;
    while (test--) {
        int r, x, d, n, rounds=0;
        cin>>r>>x>>d>>n;
        char curr;
        for (int i=0;i<n;i++) {
            cin>>curr;
            if (curr-'1') {
                if (r<x) {
                    rounds++;
                    r-=d;
                }
            } else {
                r-=d;
                rounds++;
            }
            if (r<0) {
                r=0;
            }
        }
        cout<<rounds<<endl;
    }
    return 0;
}