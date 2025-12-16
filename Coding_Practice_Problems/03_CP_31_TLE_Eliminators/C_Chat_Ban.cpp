#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)(1e9+7)
#define EPS (double)1e-9

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

// just an O(1)
// FIND formula achieved
// PERFECT formula GOT IT

// hmmmm..... think 'bout it

// other APPROACH think...
void math_solve(int k, int x) {
    if (x > k*k) {
        //out of bounds
        cout<<2*k-1<<endl;
    } else if (x > k*(k+1)/2) {
        // decrease
        x = k*k-x;
        int ans = 2*k - 1 - floor((sqrt(1+8*x)-1)/2);
         // approximational ERRORS ? // not good for big vals
        cout<<ans<<endl;
    } else {
        // increase
        int ans = ceil((sqrt(1+8*x)-1)/2);
        cout<<ans<<endl;
    }
}

int32_t main() {
    fast_io();
    int test;
    cin >> test;
    while (test--) {
        int k, x; cin >> k >> x;
        math_solve(k, x);
    }
    return 0;
}