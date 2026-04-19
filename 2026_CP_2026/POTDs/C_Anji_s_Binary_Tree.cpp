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

void dfs(int level, int node, vector<pair<int, int>>& tree,
     vi& leaves, vvi& levels) {
    if (levels.begin()+level==levels.end()) {
        levels.push_back({});
    }
    levels[level].push_back(node);
    int count=0;
    if (tree[node].first==0) {
        count++;
    } else {
        dfs(level+1, tree[node].first, tree, leaves, levels);
    }
    if (tree[node].second==0) {
        count++;
    } else {
        dfs(level+1, tree[node].second, tree, leaves, levels);
    }
    if (count==2) {
        leaves.push_back(node);
    }
}

#define check 0
void solve() {
    int n; cin >> n;
    string symbol; cin >> symbol;
    vector<pair<int, int>> tree={{0, 0}};
    int x, y;
    loop(0, n) {
        cin >> x >> y;
        tree.push_back({x, y});
    }
    vi leaves;
    vvi levels;
    dfs(0, 1, tree, leaves, levels);
    debug(levels)
    debug(leaves)
    vi dp(n+1, INF);
    for (auto lf : leaves) {
        dp[lf]=0;
    }
    int curr = levels.size()-1;
    while(curr>=0) {
        vi now = levels[curr];
        for (int ele : now) {
            if (dp[ele]!=0) {
                debug(ele)
                if (symbol[ele-1]=='U') {
                    dp[ele]=min(dp[tree[ele].first], dp[tree[ele].second])+1;
                } else if (symbol[ele-1]=='L') {
                    if (dp[tree[ele].first]>dp[tree[ele].second]) {
                        dp[ele]=dp[tree[ele].second]+1;
                    } else {
                        dp[ele]=dp[tree[ele].first];
                    }
                } else {
                    if (dp[tree[ele].first]<dp[tree[ele].second]) {
                        dp[ele]=dp[tree[ele].first]+1;
                    } else {
                        dp[ele]=dp[tree[ele].second];
                    }
                }
            }
        }
        debug(dp)
        curr--;
    }
    cout<<dp[1]<<endl;
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