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
    int n, l, r; cin >> n >> l >> r; l--;
    vi arr(n); loop(0, n) cin >> arr[i];
    sort(arr.begin(), arr.begin()+l);
    sort(arr.begin()+l, arr.begin()+r, greater<int>());
    sort(arr.begin()+r, arr.end());
    int neut=accumulate(arr.begin()+l, arr.begin()+r, (int)0);
    loop(0+1, l) {
        arr[i]+=arr[i-1];
    }
    loop(r+1, n) {
        arr[i]+=arr[i-1];
    }
    loop(l+1, r) {
        arr[i]+=arr[i-1];
    }
    int best=0;
    for (int i=0;i<r-l;i++) {
        int curr=arr[l+i];
        if (i<l) {
            curr=min(curr, arr[i]);
        }
        if (r+i<n) {
            curr=min(curr, arr[r+i]);
        }
        best = max(arr[l+i]-curr, best);
        debug(curr)
        debug(best)
    }
    cout<<neut-best<<endl;
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