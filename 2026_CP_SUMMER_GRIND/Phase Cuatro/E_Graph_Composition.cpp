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
void dfs_encode(int node, vvi& adj, vi& codes, int curr) {
    if (codes[node]!=0) {
        return;
    }
    codes[node]=curr;
    for (auto ele : adj[node]) {
        dfs_encode(ele, adj, codes, curr);
    }
} 

void dfs_ignore(int node, vvi& adj, vi& codes, vi& covered, int& score) {
    if (covered[node]!=0) {
        return;
    }
    covered[node]=1;
    for (auto ele : adj[node]) {
        if (codes[ele]==codes[node]) {
            dfs_ignore(ele, adj, codes, covered, score);
        } else {
            if (!covered[ele]) {
                score++;
            }
        }
    }
}

void solve() {
    int n, m1, m2; cin >> n >> m1 >> m2;
    vvi adjF(n+1), adjG(n+1);
    int x, y;

    for (int i=0;i<m1;i++) {
        cin >> x >> y;
        adjF[x].push_back(y);
        adjF[y].push_back(x);
    }

    for (int i=0;i<m2;i++) {
        cin >> x >> y;
        adjG[x].push_back(y);
        adjG[y].push_back(x);
    }

    // G's CCs
    vi codes(n+1, 0);
    int curr=0;
    for (int i=1;i<=n;i++) {
        if (codes[i]==0) {
            curr++;
            dfs_encode(i, adjG, codes, curr);
        }
    }

    // delete F == make NEW F

    // will NOT require hopefully
    vvi adjNEW(n+1);

    int score=0;
    vi code2count(n+1); // max. codes == n (null graph)
    vi covered(n+1, 0);
    debug(codes)
    debug(adjG);
    debug(adjF);
    for (int i=1;i<=n;i++) {
        if (covered[i]==0) {
            code2count[codes[i]]++;
            dfs_ignore(i, adjF, codes, covered, score);
        }
    }
    // join F == append NEW F
    // just custom accumulate

    for (auto count : code2count) {
        if (count>0) {
            score+=count-1;
        }
    }

    cout<<score<<endl;
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