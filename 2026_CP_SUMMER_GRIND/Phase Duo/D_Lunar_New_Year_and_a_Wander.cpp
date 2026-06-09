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

void dfs(int node, vector<set<int>>& adj, vi& visited, vi& order, set<int>& choices) {
    order.push_back(node);
    visited[node]=1;
    for (auto it = adj[node].begin(); it!=adj[node].end(); it++) {
        if (!visited[*it]) {
            choices.insert(*it);
        }
    } 
    if (choices.empty()) {
        return;
    }
    debug(order)
    int ele = *choices.begin();
    choices.erase(choices.begin());
    dfs(ele, adj, visited, order, choices);
}

void solve() {
    int n, m; cin >> n >> m;
    vector<set<int>> adj(n+1);
    int x, y;
    loop(0, m) {
        cin >> x >> y;
        adj[x].insert(y);
        adj[y].insert(x);
    }
    vi visited(n+1, 0);
    vi order;
    set<int> choices;
    dfs(1, adj, visited, order, choices);
    for (auto ele : order) {
        cout<<ele<<" ";
    }
    cout<<endl;
}

int32_t main() {
    fast_io();
    solve();
    return 0;
}