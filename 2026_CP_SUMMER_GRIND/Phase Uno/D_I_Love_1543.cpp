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
    int n, m; cin >> n >> m;
    vvi grid(n, vi(m));
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            char c; cin >> c;
            grid[i][j]=c-'0';
        }
    }
    int x=0;
    int ans=0;
    debug(grid);
    for (int a=0;x<n*m;a++) {
        // ->
        // down
        // <-
        // up
        x+=2*(n-2*a)+2*(m-2*a)-4;
        vi last4;
        for (int i=a;i<m-a;i++) {
            if (last4.size()==4) {
                last4.erase(last4.begin());
            }
            last4.push_back(grid[a][i]);
            if (last4==vi({1,5,4,3})) {
                ans++;
            }
            debug(last4);
        }
        for (int i=a+1;i<n-a;i++) {
            if (last4.size()==4) {
                last4.erase(last4.begin());
            }
            last4.push_back(grid[i][m-a-1]);
            if (last4==vi({1,5,4,3})) {
                ans++;
            }
            debug(last4);
        }
        for (int i=m-a-2;i>=a;i--) {
            if (last4.size()==4) {
                last4.erase(last4.begin());
            }
            last4.push_back(grid[n-a-1][i]);
            if (last4==vi({1,5,4,3})) {
                ans++;
            }
            debug(last4);
        }
        for (int i=n-a-2;i>=a;i--) {
            if (last4.size()==4) {
                last4.erase(last4.begin());
            }
            last4.push_back(grid[i][a]);
            if (last4==vi({1,5,4,3})) {
                ans++;
            }
            debug(last4);
        }
        for (int i=a+1;i<=a+2 and i<m-a;i++) {
            if (last4.size()==4) {
                last4.erase(last4.begin());
            }
            last4.push_back(grid[a][i]);
            if (last4==vi({1,5,4,3})) {
                ans++;
            }
            debug(last4);
        }
        for (int i=a+1;m==2*a+2 and i<a+2;i++) {
            if (last4.size()==4) {
                last4.erase(last4.begin());
            }
            last4.push_back(grid[i][m-a-1]);
            if (last4==vi({1,5,4,3})) {
                ans++;
            }
            debug(last4);
        }
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