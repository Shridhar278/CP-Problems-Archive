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

#define check 0
void solve() {
    int n; cin >> n;
    int ans=0;
    vi arr(n); loop(0, n) cin >> arr[i];
    map<int, int> count;
    loop(0, n) {
        count[arr[i]]++;
    }
    int p1=1, p2=0, py=0, px=1;
    if (count[-1]) {
        p1 = fastModularExp(2, count[-1]-1, mod7);
    }
    p1%=mod7;
    debug(count);
    for (auto & [key, value] : count) {
        if (key!=-1) {
            px*=fastModularExp(2, value-1, mod7);
            px%=mod7;
        }
    }
    p1*=px;
    p1%=mod7;
    debug(p1)
    if (count[-1]) {
        p2 = fastModularExp(2, count[-1]-1, mod7);
    }
    p2%=mod7;
    int last1, last2;
    for (auto it = count.begin();it!=count.end();it++) {
        if ((*it).first!=-1) {
            if ((*it).first==last1+1) {
                py+=px;
                py%=mod7;
            }
            debug(py)
        }
        last1=(*it).first;
        last2=(*it).second;
    }
    debug(py)
    p2*=py;
    debug(p2)
    p2%=mod7;
    ans=p1+p2;
    ans%=mod7;
    cout<<ans<<endl;
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