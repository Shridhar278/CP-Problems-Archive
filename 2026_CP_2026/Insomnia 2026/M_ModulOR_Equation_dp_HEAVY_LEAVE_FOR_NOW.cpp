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
#define int long long

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

// DP++ leave

#define check 1
// learn_IT

// NEED cleaner CODE
/*For counting the number of pairs, we can iterate over all possible values of b
 from 1
 to n
 and find the number of sub-masks of b
 that are not more than m
 and have the same msb
. Now, we repeat the same process and find the number of pairs with a>b
.*/

// BIT_MASKS

int submasks(int i, int n) {

}

void solve() {
    int n, m; cin >> n >> m;
    int ans=0;
    loop(1, max(n, m)+1) {
        ans+=submasks(i, n)+submasks(i, m);
        debug(ans);
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