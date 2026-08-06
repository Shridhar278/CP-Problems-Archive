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
    int n; cin >> n;
    string s1, s2; cin >> s1 >> s2;
    int odds1=0, odds2=0, evens1=0, evens2=0;
    int oddpos1=0, oddpos2=0, evenpos1=0, evenpos2=0;
    vi o1, o2, e1, e2;
    debug(s1)
    debug(s2)
    loop(0, n) {
        if (i%2) {
            if (s1[i]-'0') {
                odds1++;
                o1.push_back(i);
            }
            if (s2[i]-'0') {
                odds2++;
                o2.push_back(i);
            }
            oddpos1+=odds1;
            oddpos2+=odds2;
            debug(odds1)
            debug(odds2)
            debug(oddpos1)
            debug(oddpos2)
        } else {
            if (s1[i]-'0') {
                evens1++;
                e1.push_back(i);
            }
            if (s2[i]-'0') {
                evens2++;
                e2.push_back(i);
            }
            evenpos1+=evens1;
            evenpos2+=evens2;
        }
    }
    //11011
    //01111
    //11010
    //01110
    debug(odds1)
    debug(odds2)
    debug(evens1)
    debug(evens2)
    debug(oddpos1)
    debug(oddpos2)
    debug(evenpos1)
    debug(evenpos2)
    if (odds1==odds2 && evens1==evens2) {
        int a1=0, a2=0;
        loop(0, odds2) {
            a1+=abs(o1[i]-o2[i]);
        }
        loop(0, evens2) {
            a2+=abs(e1[i]-e2[i]);
        }
        cout<<a1/2+a2/2<<endl;
    } else {
        cout<<-1<<endl;
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