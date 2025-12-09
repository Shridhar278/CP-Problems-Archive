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
        int n, k; cin >> n >> k;
        if (n%2==0) {
            cout << (k-1)%n + 1 << '\n'; // covers printing n when mod 0
        } else {
            // the shift
            int shift = (k-1)/(n/2);
            cout << (k-1 + shift)%n + 1 << '\n'; // covers printing n when mod 0
        }
    }
    return 0;
}