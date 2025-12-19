#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)(1e9+7)
#define EPS (double)1e-9

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve(int n, int a, int b) {
    int g = __gcd(b, n);
    cout << ((n-1-a)/g)*g+a << endl;
    // largest a+kg<=n-1 done.. cuz. 'g' period jumps
}

int32_t main() {
    fast_io();
    int test;
    cin >> test;
    while (test--) {
        int n, a, b; cin >> n >> a >> b;
        solve(n, a, b);
    }
    return 0;
}