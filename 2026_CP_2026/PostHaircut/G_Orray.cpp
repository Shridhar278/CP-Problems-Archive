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
#define int long long

void _print(int a) {
   cout << a;
}
void _print(string a) {
   cout << a;
}
void _print(char a) {
   cout << a;
}
template<class T> void _print(pair<T, T> v) {
    cout << "{ ";
    _print(v.first);
    cout << " ";
    _print(v.second);
    cout << " }";
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

// CLEANER = accepted

#define check 0
void solve() {
    int n; cin >> n;
    vi og(n); loop(0, n) cin >> og[i];
    sort(og.begin(), og.end(), greater<>());
    int all_digits = ilogb(og[0]);
    vector<pair<int, int>> arr(n, pair<int, int>());
    loop(0, n) {
        arr[i].first=og[i];
        arr[i].second=og[i];
    }
    int curr=0;
    for (int j=0;j<=all_digits;j++) {
        if (arr[curr].first&(1<<j)) {
            for (int i=curr+1;i<n;i++) {
                arr[i].first-=arr[i].first&(1<<j);
            }
        }
    }
    while (all_digits>=0) {
        debug(all_digits)
        debug(arr)
        if (!(arr[curr].first&(1<<all_digits))) {
            curr++;
            if (curr==n) {
                break;
            }
            sort(arr.begin()+curr, arr.end(), greater<>());
            for (int j=0;j<=all_digits;j++) {
                if (arr[curr].first&(1<<j)) {
                    for (int i=curr+1;i<n;i++) {
                        arr[i].first-=arr[i].first&(1<<j);
                    }
                }
            }
        }
        all_digits--;
    }
    loop(0, n)  {
        cout<<arr[i].second<<" ";
    }
    cout<<endl;
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