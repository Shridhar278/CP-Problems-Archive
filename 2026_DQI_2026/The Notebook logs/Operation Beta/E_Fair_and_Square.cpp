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
template<class T> void _print(vector<T> v) {
    cout << "[ ";
    for (auto i : v) {
        _print(i);
        cout << " ";
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
void dfs(int node, int prev, vvi& adj,
     set<int>& sqs, int& count, vector<map<int, int>>& childs, int& n) {
    count++;
    int totals=0;
    for (auto ele : adj[node]) {
        if (ele!=prev) {
            int curr=-1;
            if (sqs.count(node)) {
                curr=count;
            }
            dfs(ele, node, adj, sqs, count, childs, n);
            if (curr!=-1) {
                totals+=count-curr;
                childs[node][ele]=count-curr;
            }
        }
    }
    if (sqs.count(node)) {
        childs[node][prev]=n-1-totals;
    }
}

int func(map<int, int> rep) {
    int a = 0, ab = 0, abc = 0;
    for (auto& [key, val] : rep) {
        a += val;
        ab += val * val;
        abc += val * val * val;
    }
    int e2 = (a * a - ab) / 2;
    int e3 = (a * a * a - 3 * a * ab + 2 * abc) / 6;
    return e2 + e3;
}

void solve() {
    int n; cin >> n;
    vi score(n); loop(0, n) cin >> score[i];
    vvi adj(n);
    int x, y;
    loop(0, n-1) {
        cin >> x >> y;
        adj[x-1].push_back(y-1);
        adj[y-1].push_back(x-1);
    }
    set<int> sqs;
    loop(0, n) {
        if (llround(sqrt(score[i]))*llround(sqrt(score[i]))==score[i]) {
            sqs.insert(i);
        }
    }
    int ans=0;
    vector<map<int, int>> childs(n); 
    for (auto ele : sqs) {
        for (auto kid : adj[ele]) {
            if (!childs[ele].count(kid)) {
                childs[ele][kid]=0;
                dfs(kid, ele, adj, sqs, childs[ele][kid], childs, n);
                debug(ele)
                debug(childs)
            }
        }
        ans+=func(childs[ele]);
    }
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