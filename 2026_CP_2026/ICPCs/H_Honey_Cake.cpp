#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)(1e9+7)
#define EPS (double)1e-9

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    int w, h, d; cin >> w >> h >> d;
    int n; cin >> n;
    int w_parts, h_parts, d_parts;
    w_parts = __gcd(n, w);
    w /= w_parts;
    n /= w_parts;
    h_parts = __gcd(n, h);
    h /= h_parts;
    n /= h_parts;
    d_parts = __gcd(n, d);
    d /= d_parts;
    n /= d_parts;
    if (n==1) {
        cout<<w_parts-1<<" "<<h_parts-1<<" "<<d_parts-1<<endl;
    } else {
        cout<<-1<<endl;
    }
}

int32_t main() {
    fast_io();
    solve();
    return 0;
}