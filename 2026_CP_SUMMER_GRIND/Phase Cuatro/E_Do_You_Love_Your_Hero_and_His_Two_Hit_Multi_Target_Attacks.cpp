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

// 0,0 1,1 2,2 3,3 4,4 5,5 6,6
// 0,0 1,0 2,0

// nc2
// 499*250~100,000
// oo wait
// 200*399=79800

// 11 21 31 41 51 26 27 28 29 310 411 512 

int C2(int n) {
    return n*(n-1)/2;
}

#define check 0
void solve() {
    int k; cin >> k;
    // init points
    vvi points;
    vi state;
    // .ignore
    points.push_back(vi({0, 0}));
    state.push_back(-1);

    for (int i=1;i<=500;i++) {
        points.push_back(vi({i, i}));
        state.push_back(1);
    }

    int i1=1;
    int i2=2;

    // dissecting k;
    while (k>0) {
        int i;
        for (i=2;i<=500;i++) {
            if (C2(i)>k) {
                debug(i)
                debug(i1)
                debug(i2)
                for (int c=1;c<(i-1);i2++,c++) {
                    points[i2][state[i1]]=points[i1][state[i1]];
                    state[i2]=1-state[i1];
                }
                i1++;
                break;
            }
        }
        k-=C2(i-1);
        debug(k)
    }

    cout<<i2-1<<endl;
    for (int i=1;i<=i2-1;i++) {
        cout<<points[i][0]<<" "<<points[i][1]<<endl;
    }
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