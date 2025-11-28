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
        if (n==1) {
            cout<<1<<endl;
            continue;
        }
        if (n==2) {
            cout<<9<<endl;
            continue;
        }
        int a = n*n + n*n-1 + n*n-n;
        int b = n*n-1 + n*n + n*n-2 + n*n-n-1;
        int c = n*n-n + n*n + n*n-2*n + n*n-n-1;
        int d = n*n-n-1 + n*n-n + n*n-n-2 + n*n-1 + n*n-2*n-1;
        cout << max({a, b, c, d}) << endl;
    }
    return 0;
}