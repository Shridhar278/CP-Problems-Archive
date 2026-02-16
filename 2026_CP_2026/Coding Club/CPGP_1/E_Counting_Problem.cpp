#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MOD 998244353
#define EPS (double)1e-9

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

// handling nCr ISSUES resolved
// inv modulo + binary exponentiation
// + take %MOD to avoid over OVERFLOW

// learning...

// comes HANDY // remember
int binpow(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a)%MOD;
        a = (a * a)%MOD;
        b >>= 1;
    }
    return res;
}

int invfact(int n, int facts[]) {
    // NEED FASTER invfact
    if (n<0) {
        return 0;
    }
    int facto = facts[n];
    // MAKE FASTER
    // binary exponentiation BS
    int inv = binpow(facto, MOD-2);
    return inv;
}

// okay TLE

void solve() {
    int n, m, l, r; cin >> n >> m >> l >> r;
    // ans is mC(n-1)*(n-2)*((n-3)c(l-2)+...+(n-3)c(r-2));
    // save time-101;
    int facts[m+1]={1};
    for (int i=1;i<=m;i++) {
        facts[i]=i*facts[i-1];
        facts[i]%=MOD;
    }
    int ans=0;
    for (int i=l-2;i<=r-2;i++) {
        int x = (facts[n-3]*invfact(i, facts))%MOD;
        x*=invfact(n-3-i, facts);
        x%=MOD;
        ans+=x;
        ans%=MOD;
    }
    ans*=(n-2);
    ans%=MOD;
    int ncr = (facts[m]*invfact(n-1, facts))%MOD;
    ncr*=invfact(m-n+1, facts);
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