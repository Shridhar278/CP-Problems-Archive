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
#define int long long

void _print(int a) {
   cout << a;
}
void _print(string a) {
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
#define check 0

void solve() {
    int n, m, w; cin >> n >> m >> w;
    vi score(n), risk(n);
    loop(0, n) {
        cin >> score[i] >> risk[i];
    }
    vi dont(n, 0);
    loop(0, m) {
        int a, b; cin >> a >> b;
        a--; b--;
        dont[a] += (1LL << b);
        dont[b] += (1LL << a);
    }

    int full = (1LL << n);
    vi totalScore(full, 0), totalRisk(full, 0);
    vector<bool> invalid(full, false);
    invalid[0] = false; // empty set is valid but contributes 0 (handled by ttl check below)

    int best = -INF;

    for (int mask = 1; mask < full; mask++) {
        int lb = __builtin_ctzll(mask);      // index of lowest set bit
        int prev = mask ^ (1LL << lb);        // mask without that item

        totalScore[mask] = totalScore[prev] + score[lb];
        totalRisk[mask]  = totalRisk[prev]  + risk[lb];
        // invalid if the smaller mask was already invalid,
        // or if item `lb` conflicts with anything already in `prev`
        invalid[mask] = invalid[prev] || ((dont[lb] & prev) != 0);

        debug(mask)
        debug(totalScore[mask])
        debug(totalRisk[mask])

        if (!invalid[mask] && totalRisk[mask] <= w) {
            best = max(best, totalScore[mask]);
        }
    }

    if (best == -INF) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        cout << best << endl;
    }
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