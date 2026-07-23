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
vvi sparse_table(int n, vi& diffs) {
    vvi ans(n-1, vi(ilogb(n-1)+1));
    loop(0, n-1) {
        ans[i][0]=diffs[i];
    }
    loop(1, ilogb(n-1)+1) {
        for(int j=0;j<n-1;j++) {
            ans[j][i]=__gcd(ans[j][i-1], ans[min(n-2, j+(1<<(i-1)))][i-1]);
        }
    }
    return ans;
}

int check_sparse(int n, vvi& sparse, int l, int r) {
    // l l+1 l+2 l+3 l+4
    //  l  l+1 l+2 l+3
    // 
    l--; r-=2;
    int ln = r-l+1;
    if (!ln) {
        return 0;
    }
    int x = ilogb(ln);
    int ans = __gcd(sparse[l][x], sparse[max(l, r+1-(1<<x))][x]);
    return abs(ans);
}

void solve() {
    int n, q; cin >> n >> q;
    vi arr(n); loop(0, n) cin >> arr[i];
    vector<pair<int, int>> query(q); 
    loop(0, q) cin >> query[i].first >> query[i].second;
    if (n==1) {
        loop(0, q) {
            cout<<0<<" ";
        }
        cout<<endl;
        return;
    }

    vi diffs(n-1); loop(0, n-1) diffs[i]=abs(arr[i+1]-arr[i]);
    vvi sparse = sparse_table(n, diffs);
    debug(diffs)
    debug(sparse)
    loop(0, q) {
        cout<<check_sparse(n, sparse, query[i].first, query[i].second)<<" ";
    }
    cout<<endl;
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