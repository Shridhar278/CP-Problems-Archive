#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MOD (int)(1e9+7)
#define EPS (double)1e-9

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

/* Now, for every index, we check if the prefix maximum is less than 
   or equal to the suffix minimum of the next element.
   If it is, then we can put a partition between those two elements.*/

// example
// 1 | 4 5 2 | 8 6 7 | 9
// 1   2 4 5   6 7 8   9

// will do

void solve() {
    
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