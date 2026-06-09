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
    vvi grid(n, vi(m));
    int high=0;
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            cin >> grid[i][j];
            if (grid[i][j] > high) {
                high = grid[i][j];
            } 
        }
    }
    vi rows(n, 0);
    vi cols(m, 0);
    int count=0;
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            if (grid[i][j]==high) {
                count++;
                rows[i]++;
                cols[j]++;
            }
        }        
    }
    int dead=0;
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            if ((rows[i]+cols[j]==(count+1) and grid[i][j]==high) or
                (rows[i]+cols[j]==(count) and grid[i][j]!=high)) {
                high--;
                dead=1;
                break;
            }
            if ((rows[i]==count) or
                (cols[j]==count)) {
                high--;
                dead=1;
                break;
            }            
        }   
        if (dead) {
            break;
        }     
    }
    cout<<high<<endl;
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