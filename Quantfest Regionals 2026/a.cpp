// typing my template
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
#define vi vector<int, int>
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
long long pos_mod(long long x) {
    return (x % MOD + MOD) % MOD;
}

long long pw(long long a, long long b) {
    long long r = 1;
    a = pos_mod(a);
    for (; b; b >>= 1, a = a * a % MOD) {
        if (b & 1) r = r * a % MOD;
    }
    return r;
}

long long inv(long long q) {
    return pw(q, MOD - 2);
}

void pre() {
    fact[0] = 1;
    D[0] = 1;

    for (int i = 1; i <= N; i++)
        fact[i] = fact[i - 1] * i % MOD;

    invfact[N] = inv(fact[N]);
    for (int i = N; i > 0; i–)
        invfact[i - 1] = invfact[i] * i % MOD;

    for (int i = 2; i <= N; i++)
        D[i] = (i - 1) * (D[i - 1] + D[i - 2]) % MOD;
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
    return nCr(2 * n, n) * inv(n + 1) % MOD;
}

long long stars_bars(int n, int k) {
    return nCr(n + k - 1, k - 1);
}

