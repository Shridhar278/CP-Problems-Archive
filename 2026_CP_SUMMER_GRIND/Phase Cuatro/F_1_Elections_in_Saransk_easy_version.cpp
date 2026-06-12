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

// ANGER++
// if 15 more minutes would have GOT IT

#define check 0
void solve() {
    int n, d; cin >> n >> d;
    vi arr(n); loop(0, n) cin >> arr[i];
    map<int, map<int, int>> nums;
    for (int i=0;i<n;i++) {
        int curr=0;
        int j;
        if (arr[i]==1) {
            continue;
        }
        debug(arr[i])
        for (j=2;j==arr[i] or j*j<=arr[i];) {
            if (arr[i]%j==0) {
                arr[i]/=j;
                curr++;
                if (arr[i]%j) {
                    nums[j][curr]++;
                    j++;
                    curr=0;
                }
            } else {
                j++;
            }
            debug(j)
            debug(curr)
        }
        if (arr[i]!=1) {
            nums[arr[i]][1]++;
        }
    }
    int ans=1;
    for (auto& [key, ele] : nums) {
        debug(key)
        debug(ele)
        int curr=0;
        for (auto & [k, e] : ele) {
            curr+=k*e;
        }
        curr++;
        curr%=mod7;
        ans*=curr;
        ans%=mod7;
    }
    cout<<ans<<endl;
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