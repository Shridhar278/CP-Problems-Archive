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
    cout<<endl;
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
    cout<<endl;
}

#define debug(x) \
   do { \
        if (check) { \
            cout<<#x<<" = "; _print(x); \
        } \
    } while(0)

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

// ACCEPTED ben stokes

#define check 0
void solve() {
    int n, Ax, Ay, Bx, By; cin >> n >> Ax >> Ay >> Bx >> By;
    vvi cords(n, vi(2));
    loop(0, n) {
        cin >> cords[i][0];
    }
    loop(0, n) {
        cin >> cords[i][1];
    }
    sort(cords.begin(), cords.end());
    int time=Bx-Ax;
    // 1,3 5,2
    // 3,5 3,1 4,4
    // ex.
    // 1,3 2,4 3,3 3,1 5,6 5,1 5,4 5,2
    // 3.4.31.614.2
    // 31.146.2879
    // exponential time complexity to linear = DP
    // trying DP
    debug(cords);
    vvi blocks={{Ay, Ay}};
    int a=1;
    if (cords[0][0]!=Ax) {
        blocks.push_back({cords[0][1], cords[0][1]});
        a++;
    } else {
        blocks.back()[0]=min(cords[0][1], blocks.front()[0]);
        blocks.back()[1]=max(cords[0][1], blocks.front()[1]);
    }
    loop(1, n) {
        if (cords[i][0]!=cords[i-1][0]) {
            blocks.push_back({cords[i][1], cords[i][1]});
            a++;
        } else {
            blocks.back()[0]=min(cords[i][1], blocks.back()[0]);
            blocks.back()[1]=max(cords[i][1], blocks.back()[1]);
        }
    }
    if (cords[n-1][0]!=Bx) {
        blocks.push_back({By, By});
        a++;
    } else {
        blocks.back()[0]=min(By, blocks.back()[0]);
        blocks.back()[1]=max(By, blocks.back()[1]);
    }
    debug(blocks);
    // high[0] 641
    // low[1] 146
    vvi dp(a, vi(2));
    dp[0][0]=blocks[0][1]-blocks[0][0];
    dp[0][1]=blocks[0][1]-blocks[0][0];
    for (int i=1;i<a;i++) {
        dp[i][0]=min(dp[i-1][1]+abs(blocks[i][0]-blocks[i-1][0]),
                     dp[i-1][0]+abs(blocks[i][0]-blocks[i-1][1]));
        dp[i][1]=min(dp[i-1][1]+abs(blocks[i][1]-blocks[i-1][0]),
                     dp[i-1][0]+abs(blocks[i][1]-blocks[i-1][1]));
        dp[i][0]+=blocks[i][1]-blocks[i][0];
        dp[i][1]+=blocks[i][1]-blocks[i][0];
        debug(dp);
    }
    time+=min(dp[a-1][0], dp[a-1][1]);
    cout<<time<<endl;
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