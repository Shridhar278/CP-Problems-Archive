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

// ACCEPTED

#define check 1
void solve() {
    int n; cin >> n;
    vi arr(n); loop(0, n) cin >> arr[i];
    set<int> factors;
    for (int i=1;i*i<=n;i++) {
        if (n%i==0) {
            factors.insert(i);
            factors.insert(n/i);
        }
    }
    int ans=0;
    int alpha=-1;
    for (auto& fac : factors) {
        vi all(fac, alpha);
        if (fac!=n) {
            loop(0, fac) {
                if (arr[fac+i]-arr[i]!=0) {
                    all[i]=abs(arr[fac+i]-arr[i]);
                }
            }
        }
        loop(fac, n) {
            if (all[i%fac]==alpha and abs(arr[i]-arr[i%fac])==0) {
                // leave
            } else if (all[i%fac]==alpha and abs(arr[i]-arr[i%fac])!=0){
                all[i%fac]=abs(arr[i]-arr[i%fac]);
            } else if (all[i%fac]!=alpha and abs(arr[i]-arr[i%fac])==0) {
                // leave;
            } else {
                all[i%fac]=__gcd(abs(arr[i]-arr[i%fac]), all[i%fac]);
            }
        }
        int total=all[0];
        for(auto& ele : all) {
            if (total==alpha and ele==alpha) {
                // leave
            } else if (total==alpha and ele!=alpha) {
                total = ele;
            } else if (total!=alpha and ele==alpha) {
                // leave
            } else {
                total = __gcd(total, ele);
            }
        }
        if (total>1 or total==alpha) {
            ans++;
        }
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