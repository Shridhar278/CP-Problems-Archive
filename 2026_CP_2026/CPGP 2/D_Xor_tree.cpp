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

void dfs(int node, vvi& kids, vi& now, vi& change, vi& list, int& num, int parity) {
    if (parity) {
        now[node]=1-now[node];
    }
    if (now[node]!=change[node]) {
        now[node]=change[node];
        num++;
        list.push_back(node);
        parity=1-parity;
    }
    for (auto& ngb : kids[node]) {
        for (auto& grand : kids[ngb]) {
            dfs(grand, kids, now, change, list, num, parity);
        }
    }
}

void solve() {
    int n; cin >> n;
    vvi adjList(n);
    loop(0, n-1) {
        int x, y;
        cin >> x >> y;
        adjList[x-1].push_back(y-1);
        adjList[y-1].push_back(x-1);
    }
    vvi kids(n);
    vi done(n, 0);
    queue<int> q;
    q.push(0);
    while(!q.empty()) {
        int vtx = q.front(); q.pop();
        done[vtx]=1;
        for (auto ngb : adjList[vtx]) {
            if (!done[ngb]) {
                kids[vtx].push_back(ngb);
                q.push(ngb);
            }
        }
    }
    debug(kids)
    vi arr(n); loop(0, n) cin >> arr[i]; 
    vi want(n); loop(0, n) cin >> want[i];
    vi change(n, 0); loop(0, n) if (arr[i]!= want[i]) change[i]++;
    vi now(n, 0);
    queue<int> operate;
    operate.push(0);
    int num=0;
    vi list;

    // can i do this without storing stuff ?
    // still getting TLE on this...
    // big ALGO fix NEEDED

    // ALGO FIX DONE ggs

    while(!operate.empty()) {
        int curr = operate.front(); operate.pop();
        if (change[curr]!=now[curr]) {
            dfs(curr, kids, now, change, list, num, 0);
        }
        for (auto& ele : kids[curr]) {
            operate.push(ele);
        }
    }
    cout<<num<<endl;
    loop(0, num) {
        cout<<list[i]+1<<endl;
    }
    cout<<endl;
}

int32_t main() {
    fast_io();
    solve();
    return 0;
}