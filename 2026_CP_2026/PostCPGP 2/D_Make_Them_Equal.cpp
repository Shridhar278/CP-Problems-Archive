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

// NEED to LEARN KNAPSACK algo & code by the BOOK

#define check 0
void solve() {
    int n, k; cin >> n >> k;
    vi b(n); loop(0, n) cin >> b[i];
    vi c(n); loop(0, n) cin >> c[i];
    int maxi = *max_element(b.begin(), b.end());
    vi dp(maxi+1, INF); dp[0]=0; dp[1]=0;
    for(int i=1;i<=maxi;i++) {
        for(int j=1;j<=i;j++) {
            if (i+i/j<=maxi) {
                dp[i+i/j]=min(dp[i+i/j], dp[i]+1);
            }
        }
    }
    debug(dp)
    vi want(n); loop(0, n) want[i]=dp[b[i]];
    // total k ways
    // need to collect AT MOST coins dp;
    // REVISING knapsack
    debug(want)
    debug(c)

    // self-SOLUTION for knapsack

    // vector<vector<vector<int>>> knapsack(n+1, vector<vector<int>>(k+1, vector<int>(2, 0)));
    // optimizing space in knapstack

    // O(nk) = 10^9 slow
    // k grows very slowly max. val 12 at 1000 hence, we don't need k > 12*n TOO MUCH

    // GENIUS TO RESTRICT k to CONVEY knap-sack
    // A MUST-NEEDED reduction to COVER time-complexity

    // hence, SMART MOVE

    // hence, not at high max. weight < 12n (dp)
    // hence only from 1 to min(k, 12n)
    vector<vector<int>> old_sack(min(k,12*n)+1, vector<int>(2, 0));
    vector<vector<int>> new_sack(min(k,12*n)+1, vector<int>(2, 0));
    for (int ele=1;ele<=n;ele++) {
        new_sack[0][0]=old_sack[0][0];
        if (want[ele-1]==0) {
            new_sack[0][0]+=c[ele-1];
            new_sack[0][1]=1;
        }
        for (int take=1;take<=min(k, 12*n);take++) {
            if (old_sack[take][0]>new_sack[take-1][0]) {
                new_sack[take][0]=old_sack[take][0];
                new_sack[take][1]=0;
            } else {
                new_sack[take]=new_sack[take-1];
                new_sack[take][1]=new_sack[take-1][1];
            }
            if (take>=want[ele-1]) {
                if (new_sack[take-want[ele-1]][1]==0) {
                    if (new_sack[take][0]<new_sack[take-want[ele-1]][0]+c[ele-1]) {
                        new_sack[take][0]=new_sack[take-want[ele-1]][0]+c[ele-1];
                        new_sack[take][1]=1;
                    }
                }
                if (new_sack[take][0]<old_sack[take-want[ele-1]][0]+c[ele-1]) {
                    new_sack[take][0]=old_sack[take-want[ele-1]][0]+c[ele-1];
                    new_sack[take][1]=1;
                }
            }
        }
        debug(new_sack)
        old_sack=new_sack;
        new_sack=vector<vector<int>>(min(12*n,k)+1, vector<int>(2, 0));
    }
    int ans=old_sack[min(12*n, k)][0];
    cout<<ans<<endl;
}

int32_t main() {
    fast_io();
    vi dp(1001, INF); dp[0]=0; dp[1]=0;
    for(int i=1;i<=1000;i++) {
        for(int j=1;j<=i;j++) {
            if (i+i/j<=1000) {
                dp[i+i/j]=min(dp[i+i/j], dp[i]+1);
            }
        }
    }
    for (int i=1;i<=1000;i++) {
        cout<<i<<" "<<dp[i]<<" "<<endl;
    }
    cout<<endl;
    int test;
    cin >> test;
    while (test--) {
        solve();
    }
    return 0;
}