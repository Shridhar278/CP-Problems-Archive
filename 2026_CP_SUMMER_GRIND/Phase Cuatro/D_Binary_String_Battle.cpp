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

// screw THIS moving to something better

#define check 1
void solve() {
    int n, k; cin >> n >> k;
    vi arr(n);
    char c;
    loop(0, n) {
        cin >> c;
        arr[i]=c-'0';
    }
    int ones = accumulate(arr.begin(), arr.end(), 0);
    if (ones<=k) {
        cout<<"Alice"<<endl;
        return;
    }

    int max_gap=0, curr_gap=0;
    for (int i=0;i<n;i++) {
        if (arr[i]==1) {
            max_gap = max(max_gap, curr_gap);
            curr_gap=0;
        } else {
            curr_gap++;
        }
    }
    max_gap=max(max_gap, curr_gap);

    // n=13, k=4
    // 1101110111011
    // 1000100011011
    // 1000111111011
    // 1000100010011
    // 1000100111111
    // 1000100010001
    // 1000111110001
    // 1000100010001
    // stalemate
    // 1000100010001

    // 11111
    // 01010
    // 01111
    // 00101
    // 00100
    // 00000

    if (n<=k+(k-1)*(k-1) && max_gap<k) {
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