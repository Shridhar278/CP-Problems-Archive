#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)(1e9+7)
#define EPS (double)1e-9

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve(int n) {
    for (int k=2;k*k+k+1<=n;k++) {
        int power=3;
        int sums = k*k+k+1;
        while (sums <= n) {
            if (sums==n) {
                cout<<"YES"<<endl;
                return;
            }
            else {
                sums+=(int)pow(k, power);
                power++;
            }
        }
    }
    cout<<"NO"<<endl;
}

int32_t main() {
    fast_io();
    int test;
    cin >> test;
    while (test--) {
        int n; cin >> n;
        solve(n);
    }
    return 0;
}