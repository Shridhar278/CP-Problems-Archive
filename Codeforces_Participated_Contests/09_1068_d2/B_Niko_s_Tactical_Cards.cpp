#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e9+7
#define EPS (double)1e-9

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

// BIG and SMALL follow through the arrays
// using these two to calc BIGGEST and SMALLEST at each step
// hence, FOOLPROOF cuz. covering all range of values at each step
// and finally getting the LARGEST at the END

int32_t main() {
    fast_io();
    int test;
    cin >> test;
    while (test--) {
        int n; cin >> n;
        vector<int> a(n);
        vector<int> b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        int big = 0, small = 0;
        int new_big, new_small;
        for (int i = 0; i < n; i++) {
            // calculating INDEPENDTLY so in step value of BIG/SMALL does not change
            new_big = max(big - a[i],  - small + b[i]);
            new_small = min(small - a[i], - big + b[i]);
            big = new_big;
            small = new_small;
        }
        cout << big << endl;
    }
    return 0;
}