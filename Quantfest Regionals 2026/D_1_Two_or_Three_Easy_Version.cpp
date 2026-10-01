// typing my template
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vpii vector<pair<int, int>>
#define ff first
#define ss second
#define endl '\n'

#define loop(i, a, b) for(int i=a;i<b;i++)
#define rloop(i, a, b) for(int i=a;i>=b;i--)

const int MOD = 998244353;
const int MAXN = 2e5+5;

int exp(int a, int b, int mod=MOD) {
    int res=1;
    a%=MOD;
    while(b>0) {
        if (b&1) res=(res*a)%MOD;
        a = (a*a)%MOD;
        b>>=1;
    }
    return res;
}

int invmod(int x) {
    return exp(x, MOD-2, MOD);
}

int fact[MAXN], invfact[MAXN];

void precomputeFactorials() {
    fact[0]=1;
    loop(i, 1, MAXN) (fact[i]=fact[i-1]*i)%MOD;
    invfact[MAXN-1] = exp(fact[MAXN-1], MOD-2);
    rloop(i, MAXN-1, 0) invfact[i]=(invfact[i+1]*(i+1))%MOD;
}

long long nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * invfact[r] % MOD * invfact[n - r] % MOD;
}

long long nPr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * invfact[n - r] % MOD;
}

long long catalan(int n) {
    return nCr(2 * n, n) * invmod(n + 1) % MOD;
}

long long stars_bars(int n, int k) {
    return nCr(n + k - 1, k - 1);
}

void solve() {
    int n; cin >> n;
    int d2=n/2, d3=n/3, d6=n/6;
    d2-=d6;
    d3-=d6;
    vvi (n+1, vi());
    // first is 2 second is 3
    int ans=0;
    loop(i, 0, n) {
        loop(j, 0, n) {
            int x=i+j;
            x*=()
            ans%=MOD;
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    precomputeFactorials();
    int t; cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}