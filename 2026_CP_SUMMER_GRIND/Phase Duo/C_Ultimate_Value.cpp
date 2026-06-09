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

// INSANE thinking and optimization PERFORMED

#define check 0
void solve() {
    int n; cin >> n;
    vi arr(n); loop(0, n) cin >> arr[i];
    vi old=arr;

    int score1=0;
    int low_odd=INF, low_index=-1;
    int high_even=-INF, high_index=-1;

    for (int i=0;i<n;i++) {
        if (i%2==0) {
            score1+=arr[i];
        } else {
            score1-=arr[i];
        }
        arr[i]*=2;
        arr[i]+=i;
    }

    for (int i=0;i<n;i++) {
        if (i%2==0) {
            if (low_odd>arr[i]) {
                low_index=i;
                low_odd=arr[i];
            }
        } else {
            if (high_even<arr[i]) {
                high_index=i;
                high_even=arr[i];
            }
        }
        debug(low_odd)
        debug(high_even)
    }

    score1+=max(high_even-low_odd, ((n-1)/2)*2);
    
    int score2=0;
    low_odd=INF; low_index=-1;
    high_even=-INF; high_index=-1;
    arr=old;

    for (int i=0;i<n;i++) {
        if (i%2==0) {
            score2+=arr[i];
        } else {
            score2-=arr[i];
        }
        arr[i]*=2;
        arr[i]-=i;
    }

    for (int i=0;i<n;i++) {
        if (i%2==0) {
            if (low_odd>arr[i]) {
                low_index=i;
                low_odd=arr[i];
            }
        } else {
            if (high_even<arr[i]) {
                high_index=i;
                high_even=arr[i];
            }
        }
        debug(low_odd)
        debug(high_even)
    }

    score2+=max(high_even-low_odd, ((n-1)/2)*2);

    cout<<max(score1, score2)<<endl;
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