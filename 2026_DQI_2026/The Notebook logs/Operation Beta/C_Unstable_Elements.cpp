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
    int n, k; cin >> n >> k;
    vi arr(n); loop(0, n) cin >> arr[i];
    vi count; count.push_back(1);
    loop(1, n) {
        if (arr[i]!=arr[i-1]) {
            count.push_back(1);
        } else {
            count.back()++;
        }
    }
    int x = k-n;
    sort(count.begin(), count.end());
    int sz = (int)count.size();
    int ways=0;
    int curr=0;
    int last=0;
    debug(x)
    debug(count)
    if ((x+curr)>=0 and ((x+curr))%(sz)==0) {
        ways++;
    }
    loop(0, sz) {
        debug(count[i])
        debug(curr)
        debug(ways)
        if ((x+curr)<0 and (-(x+curr))%(sz-i)==0 and (-(x+curr))/(sz-i)<(count[i]-last)) {
            ways++;
        }
        curr+=(count[i]-last)*(sz-i);
        auto it = upper_bound(count.begin(), count.end(), count[i]);
        i = (int)(it-count.begin())-1;
        if (i!=sz-1 and (x+curr)>=0 and ((x+curr))%(sz-i-1)==0) {
            ways++;
        }
        last=count[i];
    }
    cout<<ways<<endl;
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