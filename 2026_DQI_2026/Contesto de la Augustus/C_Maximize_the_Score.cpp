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
void divide(int st, int ed, vvi& span, int& score, int& ttl) {
    int x=st, i=st, mx=span[i][1]-span[i][0];
    for(;i<=ed;i++) {
        if (span[i][1]-span[i][0]>mx) {
            x=i;
            mx=span[i][1]-span[i][0];
        }
    }
    score+=(mx+1)*(mx+1);
    ttl-=mx+1;

    debug(span[x])
    debug(score)
    debug(mx+1)
    debug(ttl)

    if (st==ed) {
        return;
    }

    int j=st;
    for (;j<=x-1;j++) {
        if (span[j][1]>span[x][0]) {
            break;
        }
        debug(j)
    }
    j--;
    if (j>=st) {
        divide(st, j, span, score, ttl);
    }

    int k=x+1;
    for (;k<=ed;k++) {
        if (span[k][0]>span[x][1]) {
            break;
        }
    }
    debug(k)
    if (k<=ed) {
        divide(k, ed, span, score, ttl);
    }
}

void solve() {
    int n; cin >> n;
    vi arr(2*n); loop(0, 2*n) cin >> arr[i];
    vvi span(n);
    loop(0, 2*n) {
        span[arr[i]-1].push_back(i);
    }
    int score=0, ttl=2*n;
    sort(span.begin(), span.end());

    debug(span)
    divide(0, n-1, span, score, ttl);
    score+=ttl;
    cout<<score<<endl;
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