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

// REST continue on 11th of April

void bfs(int x, int y, vvi& grid, vvi&visited, vi&path) {
    queue<pair<int, int>> q;
    q.push({x, y});
    while(!q.empty()) {

    }
}

#define check 1
void solve() {
    int n, m; cin >> n >> m;
    vi path;
    vvi visited(n, vi(m, 0));
    vvi grid(n, vi(m));
    int x, y;
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            char c; cin >> c;
            if (c=='#') {
                grid[i][j]=-1;
            } else if (c=='.') {
                grid[i][j]=0;
            } else if (c=='S') {
                grid[i][j]=1;
                x=i;
                y=j;
            } else {
                grid[i][j]=2;
            }
        }
    }
    bfs(x, y, grid, visited, path);
}

int32_t main() {
    fast_io();
    solve();
    return 0;
}