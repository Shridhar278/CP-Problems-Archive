#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MOD (int)(1e9+7)
#define EPS (double)1e-9

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

// feels EZ
// it is EZ

void solve() {
    int n; cin >> n;
    vector<int> f(n);
    for (auto& i : f) cin >> i;
    if (n==2) {
        cout<<f[1]<<" "<<f[0]<<endl;
        return;
    }
    vector<int> a(n, 0);
    for (int i=0;i<n-2;i++) {
        a[i+1]=((f[i+2]-f[i+1])-(f[i+1]-f[i]))/2;
    }
    // an
    a[n-1]=f[0];
    for (int i=0;i<n-1;i++) {
        a[n-1]-=i*a[i];
    }
    a[n-1]/=n-1;
    //a0
    a[0]=f[n-1];
    for (int i=1;i<n;i++) {
        a[0]-=(n-1-i)*a[i];
    }
    a[0]/=n-1;
    // 0 1 2
    // 1 0 1
    // 2 1 0
    // +1 -1 -1
    // +1 +1 -1
    // +2
    for (int i=0;i<n;i++) {
        cout<<a[i]<<" ";
    }
    cout<<endl;
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