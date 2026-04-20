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

#define check 0

void dfs(int node, vvi& adj, vi& cats, int level, vi& rank, int m, int& ans) {
    if (cats[node]) {
        level++;
    } else {
        level=0;
    }
    if (level<=m) {
        rank[node]=1;
    } else {
        rank[node]=0;
    }
    int count=0;
    debug(rank)
    if (rank[node]) {
        for (auto ele: adj[node]) {
            if (rank[ele]==-1) {
                dfs(ele, adj, cats, level, rank, m, ans);
                count++;
            }
        }
    }
    if (!count) {
        if (rank[node]) {
            ans++;
        }
    }
}
void solve() {
    int n, m; cin >> n >> m;
    vi cats(n); loop(0, n) cin >> cats[i];
    // dfs
    vvi adj(n, vector<int>());
    int x, y;
    loop(0, n-1) {
        cin >> x >> y;
        adj[x-1].push_back(y-1);
        adj[y-1].push_back(x-1);
    } 
    vi rank(n, -1);
    debug(adj)
    int ans=0;
    dfs(0, adj, cats, 0, rank, m, ans);
    cout<<ans<<endl;
}

int32_t main() {
    fast_io();
    solve();
    return 0;
}