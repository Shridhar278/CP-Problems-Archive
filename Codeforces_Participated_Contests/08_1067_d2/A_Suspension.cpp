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
        int n; cin >> n;
        int y, r; cin >> y >> r;
        if (r >= n) {
            cout<<n<<endl;
            continue;
        }
        if (y/2 >= n-r) {
            cout<<n<<endl;
            continue;
        }
        cout<<y/2+r<<endl;
    }
    return 0;
}