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

// will FIX conceptual ERRORS

#define check 0
void solve() {
    int n; cin >> n;
    vi arr(n); loop(0, n) cin >> arr[i];
    vi fre1(n, INF);
    vi fre2(n, INF);
    vi me1(n, INF);
    vi me2(n, INF);
    fre1[0]=(arr[0]==0)?0:1;
    if (n>1) {
        fre2[1]=fre1[0]+((arr[1]==0)?0:1);
        me1[1]=fre1[0];
    }
    loop(2, n) {
        fre1[i]=((arr[i]==0)?0:1)+min(me1[i-1], me2[i-1]);
        fre2[i]=((arr[i]==0)?0:1)+fre1[i-1];
        me1[i]=min(fre1[i-1], fre2[i-1]);
        me2[i]=me1[i-1];
        debug(arr)
        debug(fre1)
        debug(fre2)
        debug(me1)
        debug(me2)
    }   
    cout<<min({fre1[n-1], fre2[n-1], me1[n-1], me2[n-1]})<<endl;
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