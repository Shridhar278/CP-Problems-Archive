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
void solve() {
    int n; cin >> n;
    vi cords(n+2), height(n+2); 
    cords[0]=-INF; height[0]=0;
    cords[n+1]=INF; height[0]=0;
    loop(0, n) cin >> cords[i+1] >> height[i+1];
    vvi dp(n+1, vi(3)); dp[0]=vi({0, 0, 0});
    for (int i=1;i<=n;i++) {
        int x = max(dp[i-1][0], dp[i-1][1]);
        int y = dp[i-1][2];
        
        // [0]
        if (cords[i]-height[i]>cords[i-1]) {
            dp[i][0]=x+1;
        } else {
            dp[i][0]=-1;
        }

        if (cords[i]-height[i]>cords[i-1]+height[i-1]) {
            dp[i][0]=max(dp[i][0], y+1);
        } else {
            // leave
        }

        // [1]
        dp[i][1]=max(x, y);

        // [2]
        if (cords[i]+height[i]<cords[i+1]) {
            dp[i][2]=max(x, y)+1;
        } else {
            dp[i][2]=-1;
        }

        debug(dp[i]);
    }

    cout<<*max_element(dp[n].begin(), dp[n].end())<<endl;
}

int32_t main() {
    fast_io();
    solve();
    return 0;
}