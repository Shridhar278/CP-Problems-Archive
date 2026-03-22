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

// FIND FIX

#define check 1
void solve() {
    int n, m; cin >> n >> m;
    // check for odd cycles in connected components
    // visit every node of connected component
    // if has odd cycle -> 0
    // if not += no. of nodes
    int x, y;
    vvi adj(n+1, vi());
    vvi components(n+1, vi(2, 0));
    loop(0, m) {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int curr=1;
    int total=0;
    loop(1, n+1) {
        if (components[i][0]!=0) {
            continue;
        }
        components[i][0]=curr;
        int level=1;
        vi available = {i};
        vi new_avail;
        int this_one=1;
        while (available.size()!=0) {
            for (auto x : available) {
                for (auto y : adj[x]) {
                    if (components[y][0]==0) {
                        components[y][0]=curr;
                        components[y][1]=level;
                        new_avail.push_back(y);
                        this_one++;
                    } else {
                        if ((components[y][1]+level)%2==1) {
                            this_one=0;
                            new_avail.clear();
                            break;   
                        }
                    }
                }
            }
            available=new_avail;
            new_avail.clear();
            level++;
        }
        if (this_one!=1) {
            this_one/=2;
        }
        total+=this_one;
        curr++;
    }
    cout<<total<<endl;
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