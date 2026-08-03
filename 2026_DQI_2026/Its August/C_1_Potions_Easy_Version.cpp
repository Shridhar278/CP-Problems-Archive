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
    vi arr(n+1); loop(1, n+1) cin >> arr[i];
    // 2d DP
    vvi dp(n+1, vi(n+1)); // max.health = dp[total][potions drank] 

    for (int i=0;i<n+1;i++) {
        for (int j=i+1;j<n+1;j++) {
            dp[i][j]=-INF;
        }
    }

    for(int i=1;i<n+1;i++) {
        if (arr[i]>=0) {
            for (int j=1;j<n+1;j++) {
                if (dp[i-1][j-1]>=0) {
                    dp[i][j]=dp[i-1][j-1]+arr[i];
                } else {
                    dp[i][j]=-INF;
                }
                debug(dp[i][j])
            }
            continue;
        }

        for (int j=1;j<n+1;j++) {
            if (dp[i-1][j-1]+arr[i]>=0) {
                dp[i][j]=max(dp[i-1][j], dp[i-1][j-1]+arr[i]);
            } else {
                dp[i][j]=dp[i-1][j];
            }
            debug(dp[i][j])
        }
    }

    int ans=n;
    for (;ans>=0;ans--) {
        if (dp[n][ans]>=0) {
            break;
        }
    }
    cout<<ans<<endl;
}

int32_t main() {
    fast_io();
    solve();
    return 0;
}