/////////////////////////////////////////////////////////////////////////////
// @@@@@  @   @  @@@@  @@@@@ @@@@   @   @   @@@   @@@@   @@@@@ @@@@@ @@@@@ //
// @      @   @  @   @   @   @   @  @   @  @   @  @   @      @    @  @   @ //
// @@@@@  @@@@@  @@@@    @   @   @  @@@@@  @@@@@  @@@@   @@@@@   @    @@@  //
//     @  @   @  @  @    @   @   @  @   @  @   @  @  @   @       @   @   @ //
// @@@@@  @   @  @   @ @@@@@ @@@@   @   @  @   @  @   @  @@@@@   @   @@@@@ //
/////////////////////////////////////////////////////////////////////////////
//smudge your eyes a little to see the trademark

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

// check this

#define check 1
bool checker(vi count, vi aval, int n) {
    int i=0;
    int backs=0;
    while(n>0) {
        if (backs) {
            if (count[i]) {
                aval[i]--;
                count[i]=0;
                backs=0;
            } else {
                count[i]=1;
            }
        }
        if (n%2 && !count[i]) {
            loop(i, 61) {
                if (!aval[i]) {
                    break;
                }
                if (count[i]) {
                    backs=1;
                    break;
                }
            }
            if (!backs) {
                return false;
            }
        }
        n/=2;
        i++;
    }
    return true;
}

void solve() {
    int n; cin >> n;
    vi aval(61);
    vi count(61);
    int x, y;
    loop(0, n) {
        cin >> x >> y;
        if (x==1) {
            count[y]++;
            aval[y]++;
            loop(y, 60) {
                if (count[i]==2) {
                    count[i]=0;
                    count[i+1]++;
                    aval[i+1]++;
                } else {
                    break;
                }
            }
        } else {
            if (checker(count, aval, y)) {
                yes;
            } else {
                no;
            }
        }
        debug(y)
        if (y==38) {
        debug(count[7])
        debug(aval[7])
        debug(count[6])
        debug(aval[6])
        debug(count[5])
        debug(aval[5])
        debug(count[4])
        debug(aval[4])
        debug(count[3])
        debug(aval[3])
        debug(count[2])
        debug(aval[2])
        debug(count[1])
        debug(aval[1])
        debug(count[0])
        debug(aval[0])
        }
    }
}

int32_t main() {
    fast_io();
    solve();
    return 0;
}