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

// less GO

#define check 0
void solve() {
    int n, m; cin >> n >> m;
    vi city(n); loop(0, n) cin >> city[i];
    vi tower(m); loop(0, m) cin >> tower[i];
    int i=0, j=0;
    int r=0;
    if (tower[0]>=city[0]) {
        r = tower[0]-city[0];
    }
    while(i<n and j<m) {
        debug(tower[j])
        debug(city[i])
        debug(r)

        if (j==0 and tower[j]>=city[i]) {
            i++;  
        } else if (tower[j]>=city[i]) {
            if (tower[j]-r<=city[i] or (tower[j-1]+r>=city[i])) {
                i++;
            } else {
                r = max(r, min(abs(tower[j-1]-city[i]), 
                abs(tower[j]-city[i])));
                i++;
            }
        } else if (tower[j]<city[i]) {
            if (j==m-1) {
                r = max(r, abs(tower[j]-city[i]));
                i++;
                continue;
            }
            if (tower[j+1]<city[i]) {
                j++;
            } else {
                r = max(r, min(abs(tower[j]-city[i]), 
                abs(tower[j+1]-city[i])));
                j++;
            }
        }
    }
    
    cout<<r<<endl;
}

int32_t main() {
    fast_io();
    solve();
    return 0;
}