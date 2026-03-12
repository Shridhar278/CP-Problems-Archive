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
    vi arr1(n); loop(0, n) cin >> arr1[i]; sort(arr1.begin(), arr1.end());
    vi arr2(m); loop(0, m) cin >> arr2[i]; sort(arr2.begin(), arr2.end());
    int round=0;
    while (arr1.size()!=0 and arr2.size()!=0) {
        if (round%2) {
            int high=arr1.back();
            arr1.pop_back();
            high-=arr2.back();
            if (high>0) {
                auto it = lower_bound(arr1.begin(), arr1.end(), high);
                arr1.insert(it, high);
            }
        } else {
            int high=arr2.back();
            arr2.pop_back();
            high-=arr1.back();
            if (high>0) {
                auto it = lower_bound(arr2.begin(), arr2.end(), high);
                arr2.insert(it, high);
            }
        }
        debug(arr1)
        debug(arr2)
        round++;
    }
    if (round%2) {
        cout<<"Alice"<<endl;
    } else {
        cout<<"Bob"<<endl;
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