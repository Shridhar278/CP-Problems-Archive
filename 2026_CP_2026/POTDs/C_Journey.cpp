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
#define map map<int, int>
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

// find cute dp
// instead of calc 1<<1000 terms
// took average from down #NICE

// nice DP takes average to up with equal WEIGHT to all child nodes
// nice no. of cases managed

double dfs(int node, int p, int count, vvi& adj) {
    int kids=(int)adj[node].size()-1;
    double exp=0;
    for (auto ngb : adj[node]) {
        if (ngb!=p) {
            exp+=dfs(ngb, node, count+1, adj);
        }
    }
    if (kids) {
        exp/=kids;
    } else {
        exp=count;
    }
    return exp;
}

#define check 1
void solve() {
    int n; cin >> n;
    vvi adj(n+1);
    adj[1].push_back(0);
    int x, y;
    loop(0, n-1) {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    cout<<fixed<<setprecision(6)<<dfs(1, 0, 0, adj)<<endl;
}

int32_t main() {
    fast_io();
    solve();
    return 0;
}