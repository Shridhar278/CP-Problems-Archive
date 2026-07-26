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

int opr(int stg, int x, int y) {
    if (stg%2) {
        return x|y;
    } else {
        return x^y;
    }
}

void generate(vi q, int n, vvi& tree) {
    int idx=q[0]-1;
    tree[0][idx]=q[1];
    loop(1, n+1) {
        tree[i][idx/2]=opr(i, tree[i-1][idx],
             tree[i-1][idx+1-2*(idx%2)]);
        idx/=2;
    }
}

#define check 1
void solve() {
    int n, m; cin >> n >> m;
    int l = ((int)1<<n);
    vi arr(l); loop(0, l) cin >> arr[i];
    vvi query(m, vi(2));
    loop(0, m) {
        cin >> query[i][0] >> query[i][1];
    }
    // __init__
    vvi stages(n+1);
    loop(0, l) {
        stages[0].push_back(arr[i]);
    }
    // stages
    loop(1, n+1) {
        for(int j=0;j<(int)1<<(n-i);j++) {
            stages[i].push_back(opr(i, stages[i-1][2*j],
                 stages[i-1][2*j+1]));
        }
    }

    // query handling
    loop(0, m) {
        generate(query[i], n, stages);
        cout<<stages[n][0]<<endl;
    }
}

int32_t main() {
    fast_io();
    solve();
    return 0;
}