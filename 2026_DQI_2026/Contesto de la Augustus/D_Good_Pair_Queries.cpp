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
    int n, q; cin >> n >> q;
    string s, t; cin >> s >> t;
    vi count11(n+1);
    vi count10(n+1);
    vi count01(n+1);
    vi count00(n+1);
    loop(0, n) {
        count11[i+1]=count11[i];
        count10[i+1]=count10[i];
        count01[i+1]=count01[i];
        count00[i+1]=count00[i];

        if (s[i]=='1' && t[i]=='1') {
            count11[i+1]++;
        }
        if (s[i]=='1' && t[i]=='0') {
            count10[i+1]++;            
        }
        if (s[i]=='0' && t[i]=='1') {
            count01[i+1]++;            
        }
        if (s[i]=='0' && t[i]=='0') {
            count00[i+1]++;          
        }
    }


    debug(count00)
    debug(count01)
    debug(count10)
    debug(count11)

    int x, y;
    loop(0, q) {
        cin >> x >> y;
        int a = count11[y]-count11[x-1];
        int b = count00[y]-count00[x-1];
        int c = count10[y]-count10[x-1];
        int d = count01[y]-count01[x-1];

        debug(a)
        debug(b)
        debug(c)
        debug(d)
        debug(a+b+c+d)

        if (max(a, b)>=max(c, d)-min(c, d)) {
            yes;
        } else {
            no;
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