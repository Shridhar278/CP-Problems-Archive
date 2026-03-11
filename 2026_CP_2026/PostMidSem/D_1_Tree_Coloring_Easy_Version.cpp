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

// copying huge data each recursion call takes time
// using iteratively : SAVE TIME
// void search(vvi edges, vi& parents, vi &levels, int num, int level) {
//     levels[num]=level;
//     int contri=0;
//     for (auto kid : edges[num]) {
//         if (levels[kid]==-1) {
//             contri++;
//             search(edges, parents, levels, kid, level+1);
//         }
//     }
//     if (contri!=0) {
//         parents[level]++;
//     }
// }

// used BFS, iteratively
// no recursion NO cpying vvi again and again -> TLE GONEE

#define check 0
void solve() {
    int n, x, y; cin >> n;
    vvi edges(n+1, vi());
    vi levels(n+1, -1); levels[1]=1;
    loop(0, n-1) {
        cin >> x >> y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    vi parents(n+1, 0);
    // search(edges, parents, levels, 1, 1);
    // iterative BFS for the WIN
    vi curr={1};
    vi new_curr;
    int checked=1;
    int level=1;
    while(checked!=n) {
        debug(curr)
        debug(new_curr)
        debug(level)
        int parent=0;
        for (auto node : curr) {
            int ithas=0;
            for (auto kid : edges[node]) {
                if (levels[kid]==-1) {
                    ithas++;
                    checked++;
                    levels[kid]=level+1;
                    new_curr.push_back(kid);
                }
            }
            if (ithas!=0) {
                parent++;
            }
        }
        parents[level]=parent;
        debug(curr)
        debug(new_curr)
        debug(level)
        curr=move(new_curr);
        new_curr.clear();
        level++;
    }
    vi freq_level(n+1, 0);
    loop(1, n+1) {
        freq_level[levels[i]]++;
    }
    int ans = *max_element(freq_level.begin(), freq_level.end());
    int fail = 0;
    loop(1, n+1) {
        if (parents[i]==1) {
            if (i+1<=n) {
                if (freq_level[i+1]==ans) {
                    fail++;
                }
            }
        }
    }
    if (fail) {
        cout<<ans+1<<endl;
    } else {
        cout<<ans<<endl;
    }
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