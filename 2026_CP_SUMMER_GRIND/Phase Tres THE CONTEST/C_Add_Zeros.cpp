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

// We should use a map to store the graph, since the length of the array can grow up to ≈n2
//  and so the graph is very sparse. If we don't want to use a map, we can also take advantage of the fact that all edges are directed from ui
//  to vi
//  where ui<vi
//  and that all edges and nodes are fixed, so we can actually iterate through all ui
//  and maintain a boolean array of which vi
//  values are visited so far, updating it at any point using a binary search.

#define check 1
void solve() {
    int n; cin >> n;
    vi arr(n); loop(0, n) cin >> arr[i];
    vvi orders;
    for (int i=0;i<n;i++) {
        arr[i]-=(n-i);
        orders.push_back({arr[i], i});
    }
    sort(orders.begin(), orders.end());

    int limit=(n*(n-1))/2+1;
    // great dp click
    // since ITS SPARSE USE MAP !!!
    map dp;
    for (int i=0;i<n;i++) {
        if (orders[i][0]>=0) {
            if (orders[i][0]+orders[i][1]<limit and (orders[i][0]==0 or dp[orders[i][0]]!=0)) {
                dp[orders[i][0]+orders[i][1]] = dp[orders[i][0]]+orders[i][1];
            }
        }
    }
    // debug(dp)
    int ans=0;
    for (auto& [key, ele] : dp) {
        ans=max(ans, ele);
    }

    cout<<ans+n<<endl;
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