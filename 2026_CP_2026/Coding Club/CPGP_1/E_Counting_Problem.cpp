#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MOD 998244353
#define EPS (double)1e-9

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

int fact(int n, int r) {
    int ans=1;
    for (int i=r+1;i<=n;i++) {
        ans*=i;
        ans%=MOD;
    }
    return ans;
}

int invfact(int n) {
    int facto = fact(n, 0);
    int inv = 1;
    int temp;
    for (;inv<MOD;inv++) {
        temp = facto*inv;
        temp%=MOD;
        if (temp==1) {
            break;
        }
    }
    return inv;
}

void solve() {
    int n, m, l, r; cin >> n >> m >> l >> r;
    // ans is mC(n-1)*(n-2)*2^(n-3);
    int ans=0;
    if (n>3) {
        for (int i=l-2;i<=r-2;i++) {
            ans+=fact(n-3, n-3-i)*invfact(i);
            ans%=MOD;
        }
    } else {
        ans=1;
        if (l==r && l!=2) {
            cout<<0<<endl;
            return;
        }
    }
    ans*=(n-2);
    ans%=MOD;
    int ncr = fact(m, m-n+1)*invfact(n-1);
    ncr%=MOD;
    ans*=ncr;
    ans%=MOD;
    cout<<ans<<endl;
}

int32_t main() {
    fast_io();
    solve();
    return 0;
}