/*
                                                                ███████  ████████  ███████
   ███████ ██   ██ ██████  ██ ██████  ██   ██  █████  ██████   ██     ██ ██    ██ ██     ██
   ██      ██   ██ ██   ██ ██ ██   ██ ██   ██ ██   ██ ██   ██         ██     ██   ██     ██
   ███████ ███████ ██████  ██ ██   ██ ███████ ███████ ██████    ███████     ██     ███████
        ██ ██   ██ ██   ██ ██ ██   ██ ██   ██ ██   ██ ██   ██  ██          ██     ██     ██
   ███████ ██   ██ ██   ██ ██ ██████  ██   ██ ██   ██ ██   ██  ██          ██     ██     ██
                                                               █████████   ██      ███████
*/

// #95 : S.SHRIDHAR

#include <bits/stdc++.h>
using namespace std;
long long fastModularExp(long long base, long long exp, long long mod) {
  long long res = 1;
  base %= mod;
  while (exp > 0) {
    if (exp & 1) res = (res * base) % mod;
    base = (base * base) % mod;
    exp >>= 1;
  }
  return res;
}
#define int  long long

void _print(int a) {
   cout << a;
}
void _print(string a) {
   cout << a;
}
void _print(char a) {
   cout << a;
}
template<class T> void _print(vector<T> v) {
    cout << "[ ";
    for (auto i : v) {
        _print(i);
        cout << " ";
    }
    cout << "]";
}
template<class T> void _print(map<T, T> v) {
    cout << "[ ";
    for (auto [i, j] : v) {
        cout << "{ ";
        _print(i);
        cout << " ";
        _print(j);
        cout << " }";
    }
    cout << "]";
}

#define debug(x) \
   do { \
        if (check) {\
            cout<<#x<<" = "; _print(x); cout<<endl; \
        } \
    } while(0);

#define loop(k, n) for(int i=k;i<n;i++)
#define precise(x) cout << fixed << setprecision(x)
#define vi vector<int>
#define vvi vector<vector<int>>
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define el cout<<endl;

const int mod7 = 1e9 + 7;
const int mod9 = 998244353;
const int INF = 1e18;
const double EPS = 1e-9;

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

// clean code here
// use multisets BE HAPPY

#define check 0
void solve() {
    int n, m; cin >> n >> m;
    vi a(n); loop(0, n) cin >> a[i];
    vvi mons(m, vi(2)); // mons[i] = {b_i, c_i}
    loop(0, m) cin >> mons[i][0];
    loop(0, m) cin >> mons[i][1];

    vvi renew, term;
    for (auto &mo : mons) {
        if (mo[1] > 0) renew.push_back(mo);
        else term.push_back(mo);
    }
    sort(renew.begin(), renew.end(), [](const vi& x, const vi& y){ return x[0] < y[0]; });
    sort(term.begin(),  term.end(),  [](const vi& x, const vi& y){ return x[0] < y[0]; });

    multiset<int> pool(a.begin(), a.end());
    int ans = 0;

    // Phase 1: kill every reachable renewable monster (ascending b, chain-upgrade).
    // Never harmful: pool size never shrinks, values never decrease.
    for (auto &mo : renew) {
        auto it = pool.lower_bound(mo[0]);
        if (it == pool.end()) continue;
        int x = *it;
        pool.erase(it);
        ans++;
        pool.insert(max(x, mo[1]));
    }

    // Phase 2: plain matching against terminal monsters with what's left.
    for (auto &mo : term) {
        auto it = pool.lower_bound(mo[0]);
        if (it == pool.end()) continue;
        pool.erase(it);
        ans++;
    }

    cout << ans << endl;
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