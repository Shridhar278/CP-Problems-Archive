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
    int n, k; cin >> n >> k;
    vi arr(n); loop(0, n) cin >> arr[i];
    vi spec(n); loop(0, k) cin >> spec[i];
    loop(0, n) spec[i]--;
    // count partitions
    vi broken={0};
    for (int i=spec[0]-1;i>=0;i--) {
        if (arr[i]!=arr[spec[0]] and arr[i]!=arr[i+1]) {
            broken.back()++;
        }
    }
    for (int i=1;i<k;i++) {
        broken.push_back(0);
        for (int i=spec[i]-1;i>spec[i-1];i--) {
            if (arr[i]!=arr[spec[i]] and arr[i]!=arr[i+1]) {
                broken.back()++;
            }
        }
    }
    broken.push_back(0);
    for (int i=spec[k-1]+1;i<n;i++) {
        if (arr[i]!=arr[spec[i]] and arr[i]!=arr[i-1]) {
            broken.back()++;
        }
    }
    for (int i=0;i<broken.size();i++) {
        if (broken[i]==0) {
            broken.erase(broken.begin()+i);
            i--;
        }
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