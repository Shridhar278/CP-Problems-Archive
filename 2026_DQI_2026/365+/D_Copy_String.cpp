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
   cerr << a;
}
void _print(string a) {
   cerr << a;
}
void _print(char a) {
   cerr << a;
}
template<class T> void _print(vector<T> v) {
    cerr << "[ ";
    for (auto i : v) {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template<class T> void _print(map<T, T> v) {
    cerr << "[ ";
    for (auto [i, j] : v) {
        cerr << "{ ";
        _print(i);
        cerr << " ";
        _print(j);
        cerr << " }";
    }
    cerr << "]";
}

#define debug(x) \
   do { \
        if (check) {\
            cerr<<#x<<" = "; _print(x); cerr<<endl; \
        } \
    } while(0);

#define loop(k, n) for(int i=k;i<n;i++)
#define precise(x) cout << fixed << setprecision(x)
#define vi vector<int>
#define vvi vector<vector<int>>
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define endl "\n";

const int mod7 = 1e9 + 7;
const int mod9 = 998244353;
const int INF = 1e18;
const double EPS = 1e-9;

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

// finally compact code FORMED
// via forming queue from the BACK

// beautiful beautiful beautiful

#define check 0
void solve() {
    int n, k; cin >> n >> k;
    string s, t; cin >> s >> t;
    vi starts(26, -1);
    vvi create; // # st # size # char
    int mx = 0;
    vi change(n);
    int i=n-1;
    // edge case where
    // axysaeqtcabb
    // aaaaaaaaaaca
    queue<pair<int, int>> q; 
    while(i>=0) {
        if ((q.empty() && s[i]!=t[i]) ||
            (!q.empty() && q.back().first!=t[i])) {
            q.push({t[i], i});  
        }
        if (!q.empty() && s[i]==q.front().first) {
            create.push_back(vi({i,
                q.front().second-i, s[i]}));
            mx = max(q.front().second-i, mx);
            q.pop();
        }
        if (!q.empty()) {
            change[i]=1;
        }
        i--;
    }
    if (!q.empty() || mx>k) {
        cout<<-1<<endl;
        return;
    }
    cout<<mx<<endl;
    string x = s;
    for (int i=1;i<=mx;i++) {
        for (auto ele : create) {
            if (i<=ele[1]) {
                x[ele[0]+i]=ele[2];
            }
        }
        cout<<x<<endl;
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