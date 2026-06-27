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

// remembering in-degrees my A**

// adj = [ 0[ 1 6 ] 1[ 2 3 5 8 10 25 ] 2[ 3 6 7 25 ] 3[ 0 4 5 7 10 14 23 ]
//          4[ 5 6 12 19 ] 5[ 6 17 ] 6[ 7 8 9 13 15 ] 7[ 8 9 11 12 15 18 ]
//       8[ 7 9 12 17 22 ] 9[ 10 12 14 15 22 ] 10[ 11 17 25 ] 11[ 12 ]
//      12[ 13 14 15 18 22 24 ] 13[ 1 14 15 16 20 21 ] 14[ 13 15 16 17 24 ]
//      15[ 13 16 20 ] 16[ 8 17 ] 17[ 0 18 23 24 ] 18[ 3 20 ] 19[ 16 17 20 24 ]
//      20[ 1 21 22 24 ] 21[ 22 23 ] 22[ 1 6 23 ] 23[ 8 11 24 ] 24[ 3 7 23 25 ] 25[ ] ]
// sol = [ ]

// unintentional MENTAL ISSUES

// saala break andar daal diya to hai to IGNORE karke aage chal diya tha

#define check 1
// employing Kahn's algorithm for topological Sort : calc. indegrees
bool topoSort(vi& sol, vvi& adj) {
    vector<int> indegree(26, 0);

    for (int u = 0; u < 26; u++) {
        for (int v : adj[u]) {
            indegree[v]++;
        }
    }

    queue<int> q;

    // choose toppers + singletons (cuz. nobody cares 'bout them)
    for (int i = 0; i < 26; i++) {
        if (indegree[i] == 0)
            q.push(i);
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        sol.push_back(u);

        for (int v : adj[u]) {
            // remove edge 
            indegree[v]--;

            // its TIME for you DRUM-ROLL : vertex UNLOCKED free from ots ancestors
            if (indegree[v] == 0)
                q.push(v);
        }

        //provable atleast one vertex freed at all times
        // if CYCLE => then untouched since- indegree(any ele) !=0 LEAVES
        // Kahn's algo you beauty...
    }

    if ((int)sol.size() != 26) // Cycle
        return false;

    return true;
}

void solve() {
    int n; cin >> n;
    vector<string> names(n); loop(0, n) cin >> names[i];
    set<pair<int, int>> graph; // smol->big
    // at the end CHECK for NO CYCLE
    for (int i=1;i<n;i++) {
        string prev=names[i-1];
        string curr=names[i];
        int delta=0; // any diff.
        for (int j=0;j<min((int)prev.size(),
         (int)curr.size());j++) {
            if (prev[j]!=curr[j]) {
                if (!graph.count({prev[j]-'a', curr[j]-'a'})) {
                    graph.insert({prev[j]-'a', curr[j]-'a'});
                }
                delta=1;
                break;
            }
        }
        if (!delta and (int)prev.size()>(int)curr.size()) {
            cout<<"Impossible"<<endl;
            return;
        }
    }

    // make adj == directed graph
    vvi adj(26);
    for (auto ele : graph) {
        adj[ele.first].push_back(ele.second);
    }
    // debug(adj)
    // do BFS-avoid DIAMOND issues -> NO CYCLE problem SOLVED

    // f-off : its TOPOLOGICAL SORTING in directed GRAPH - indegrees whole BS back OFF mind
    vi sol;
    if(!topoSort(sol, adj)) {
        cout<<"Impossible"<<endl;
        // if (n==100 and names[0][0]!='x') {
        //     debug(adj)
        //     debug(sol)
        // }
        return;
    }

    for (int i=0;i<26;i++) {
        cout<<(char)(sol[i]+'a');
    }
    cout<<endl;
}

int32_t main() {
    fast_io();
    solve();
    return 0;
}