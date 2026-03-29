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

// ez. needed CLARITY OF MIND

#define check 1
void solve() {
    int n; cin >> n;
    vi arr(n); loop(0, n) cin >> arr[i];
    int gcd=arr[0];
    loop(0, n) {
        gcd = __gcd(gcd, arr[i]);
    }
    loop(0, n) {
        arr[i]/=gcd;
    }
    // sort(arr.begin(), arr.end());
    int cummulative=arr[0];
    vi lr={cummulative};
    loop(1, n) {
        int new_c = __gcd(cummulative, arr[i]);
        if (new_c < cummulative) {
            cummulative=new_c;
        }
        lr.push_back(cummulative);
    }
    cummulative=arr[n-1];
    vi rl = {cummulative};
    for(int i=n-2;i>=0;i--) {
        int new_c = __gcd(cummulative, arr[i]);
        if (new_c < cummulative) {
            cummulative=new_c;
        }
        rl.push_back(cummulative);
    }
    vi remain(n);
    remain[0]=rl[n-2];
    loop(1, n-1) {
        remain[i]=__gcd(lr[i-1], rl[n-i-2]);
        // cout<<remain[i]<<endl;
    }
    remain[n-1]=lr[n-2];
    sort(arr.begin(), arr.end());
    if (arr[n-1]!=1 and arr[n-2]==1) {
        cout<<"Bob"<<endl;
        return;
    }
    loop(0, n) {
        if (remain[i]==1) {
            cout<<"Alice"<<endl;
            return;
        }
    }
    cout<<"Bob"<<endl;
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