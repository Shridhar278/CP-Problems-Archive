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

template<class T> void _print(set<T> v) {
    cout << "{ ";
    for (auto i : v) {
        _print(i);
        cout << " ";
    }
    cout << "}";
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

// not cache-friendly BS | HIGH-LEVEL IGNORE NOW
// DSU shelved for NOW


// vector has random-access iterators | can do it+500
// set has bi-directional iterators | can't do it+500

// hence, std::binary_search on set is O(n), 
//                whereas O(logn) on vector contigous random access
// use set::find/lower_bound/upper_bound for O(logn) 
//                via R-B Trees traversal

#define check 0
void solve() {
    int n, m, k; cin >> n >> m >> k;

    vvi grid(n, vi(m));
    vector<set<int>> direcs(m);
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            cin >> grid[i][j];
            if (grid[i][j]!=2)  direcs[j].insert(i);            
        }
    }

    vi query(k); loop(0, k) cin >> query[i];
    loop(0, k) query[i]--;

    debug(grid)
    debug(query)
    debug(direcs)
    vi ans(k);
    for (int i=0;i<k;i++) {
        pair<int, int> pos={0, query[i]};
        while (true) {
            debug(pos.first)
            debug(pos.second)
            if (grid[pos.first][pos.second]==1) {
                direcs[pos.second].erase(pos.first);
                grid[pos.first][pos.second]=2;
                pos.second++;
            } else if (grid[pos.first][pos.second]==3) {
                direcs[pos.second].erase(pos.first);
                grid[pos.first][pos.second]=2;
                pos.second--;
            } else {
                // auto it=lower_bound(direcs[pos.second].begin(),
                //  direcs[pos.second].end(), pos.first);
                auto it = direcs[pos.second].lower_bound(pos.first);
                if (it==direcs[pos.second].end()) {
                    break;
                } else {
                    pos.first=*it;
                }
            }
        }
        ans[i]=pos.second+1;
    }

    loop(0, k) cout<<ans[i]<<" ";
    cout<<"\n";
}

int32_t main() {
    fast_io();
    solve();
    return 0;
}