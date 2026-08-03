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
template<class T> void _print(set<T> v) {
    cout << "{ ";
    for (auto i : v) {
        _print(i);
        cout << " ";
    }
    cout << "}";
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

#define check 0
void solve() {
    int n, m; cin >> n >> m;
    vvi a(n, vi(m));
    vvi b(n, vi(m));
    vvi a_t(m, vi(n));
    vvi b_t(m, vi(n));
    set<set<int>> a_r;
    set<set<int>> a_c;
    set<set<int>> b_r;
    set<set<int>> b_c;


    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            cin >> a[i][j];
            a_t[j][i]=a[i][j];
        }
    }
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            cin >> b[i][j];
            b_t[j][i]=b[i][j];
        }
    }

    debug(a)
    debug(a_t)
    debug(b)
    debug(b_t)

    for (int i=0;i<n;i++) {
        a_r.insert(set<int>(a[i].begin(), a[i].end()));
    }
    for (int i=0;i<m;i++) {
        a_c.insert(set<int>(a_t[i].begin(), a_t[i].end()));
    }
    for (int i=0;i<n;i++) {
        b_r.insert(set<int>(b[i].begin(), b[i].end()));
    }
    for (int i=0;i<m;i++) {
        b_c.insert(set<int>(b_t[i].begin(), b_t[i].end()));      
    }

    debug(a_r)
    debug(a_c)
    debug(b_r)
    debug(b_c)
    if (a_r==b_r && a_c==b_c) {
        yes;
    } else {
        no;
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