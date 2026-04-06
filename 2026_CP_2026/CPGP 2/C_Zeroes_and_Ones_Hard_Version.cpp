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

#define check 1
void solve() {
    int n, m; cin >> n >> m;
    vvi q(m, vector<int>(2));
    loop(0, m) {
        cin >> q[i][0] >> q[i][1];
    }
    sort(q.begin(), q.end());
    int started=0;
    int ans=0;
    if (q[0][1]==1) {
        started=1;
        ans+=(q[0][0]+1)/2;
    } else {
        ans+=q[0][0]-(q[0][0]+1)/2;
    }
    loop(1, m) {
        // debug(q)
        if (started) {
            if ((q[i][0]-q[i-1][0])%2==0) {
                if (q[i][1]!=q[i-1][1]) {
                    ans=0;
                    break;
                }
            } else {
                if (q[i][1]==q[i-1][1]) {
                    ans=0;
                    break;
                }
            }
        } else {
            if ((q[i][0]-q[i-1][0])%2==abs(q[i][1]-q[i-1][1])) {
                if (q[i][1]==q[i-1][1]) {
                    ans+=q[i][0]-q[i-1][0]-(q[i][0]-q[i-1][0]+1)/2;
                } else {
                    ans+=(q[i][0]-q[i-1][0]+1)/2;
                }
            } else {
                if (q[i][1]==q[i-1][1]) {
                    ans=q[i][0]-q[i-1][0]-(q[i][0]-q[i-1][0]+1)/2;
                } else {
                    ans=(q[i][0]-q[i-1][0]+1)/2;
                }
            }
            if (q[i][1]==1) {
                started=1;
            }
        }
    }
    cout<<ans<<endl;
}

int32_t main() {
    fast_io();
    solve();
    return 0;
}