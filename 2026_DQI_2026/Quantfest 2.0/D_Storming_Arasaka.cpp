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

// no bifurcations

// 2->2
// 4->2,4
// 8->2,4,8
// 16->2,4,8,16
// 32->2,4,8,16,32
// 67->67
// 120->2,3,4,5,6,8,10,12,15,20,24,30,40,60,120
//          120->311
//     24    60    40
//   8  12, 12 20 30, 8 20
//   4  4 6 2 3 2 5 4 10 15 idk
// 5
// 3
// 2
// 33->3,11,33

// 2^3 3^2
//     32
//    22 31
// 12 21 30
// 02 11 20
//
//
//
// eazy, ITS ALWAYS POSSIBLE

#define check 1
void solve() {
    int n; cin >> n;
    int x=n, ttl=0, diff=0;
    map<int, int> facts;

    for (int i=2;x!=1;) {
        if (!(x%i)) {
            x/=i;
            facts[i]++;
        } else {
            i++;
            if (i*i>x) {
                facts[x]++;
                break;
            }
        }
    }
    for (auto & [key, val] : facts) {
        ttl+=val;
        diff++;
    }

    cout<<ttl-1+diff<<endl;
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