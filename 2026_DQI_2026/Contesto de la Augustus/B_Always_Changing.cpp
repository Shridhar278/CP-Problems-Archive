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

#define check 0
void solve() {
    int x; cin >> x;
    string s; cin >> s;
    vvi blocks(2);
    blocks[s[0]-'0'].push_back(1);
    char curr = s[0];
    loop(1, x) {
        if (s[i]==curr) {
            blocks[curr-'0'].back()++;
        } else {
            blocks[s[i]-'0'].push_back(1);
        }
        curr = s[i];
    }
    int z=0, tz=0, o=0, to=0;
    if (s[0]=='0') {
        tz++;
    } else {
        to++;
    }
    if (s[x-1]=='0') {
        tz++;
    } else {
        to++;
    }
    int n = (int)blocks[0].size();
    int m = (int)blocks[1].size();
    for (int i=0;i<n;i++) {
        z+=blocks[0][i]-1;
    }
    for (int i=0;i<m;i++) {
        o+=blocks[1][i]-1;
    }
    debug(z)
    debug(o)
    debug(tz)
    debug(to)
    if (abs(z-o)<=1) {
        cout<<z+o<<endl;
    } else {
        if (z>o && abs(z-to-o)<=1) {
            cout<<2*z-1<<endl;
        } else if (o>z && abs(o-tz-z)<=1) {
            cout<<2*o-1<<endl;
        } else {
            cout<<-1<<endl;
        }
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