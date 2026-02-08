#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MOD (int)(1e9+7)
#define EPS (double)1e-9

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

int digits(int n) {
    int digit=0;
    while (n>0) {
        if (n%2==1) {
            digit++;
        }
        n/=2;
    }
    return digit;
}

void solve() {
    //complicated THINKING
    int n; cin >> n;
    int least=digits(n);
    // all COMBINATIONS of factorials NEED to be CHECKED
    // do it MONDAY
    cout<<least<<endl;
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