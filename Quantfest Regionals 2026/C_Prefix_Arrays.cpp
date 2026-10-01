// typing my template
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>>
#define vpii vector<pair<int, int>>
#define ff first
#define ss second
#define endl '\n'

#define loop(i, a, b) for(int i=a;i<b;i++)
#define rloop(i, a, b) for(int i=a;i>=b;i--)

const long long MOD = 998244353;
const int N = 1000000;

long long fact[N + 1], ifact[N + 1], D[N + 1];

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

    ifact[N] = inv(fact[N]);
    for (int i = N; i > 0; i--)
        ifact[i - 1] = ifact[i] * i % MOD;

    for (int i = 2; i <= N; i++)
        D[i] = (i - 1) * (D[i - 1] + D[i - 2]) % MOD;
}

long long nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return (((fact[n] * ifact[r]) % MOD )* ifact[n - r] )% MOD;
}

long long nPr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * ifact[n - r] % MOD;
}

long long catalan(int n) {
    return nCr(2 * n, n) * inv(n + 1) % MOD;
}

long long stars_bars(int n, int k) {
    return nCr(n + k - 1, k - 1);
}

void solve() {
    int n; cin >> n;
    // last was 0, 1, 2
    vi dp(n+1, 0); dp[1]=1;
    // cout<<fact[2];
    loop(i, 2, n+1) {   
        dp[i]+=dp[i-1];
        dp[i]%=MOD;
        dp[i]+=catalan(i-1);
        dp[i]%=MOD;
        
    }
    cout<<dp[n]<<endl;
}

int32_t main() {
    pre();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}