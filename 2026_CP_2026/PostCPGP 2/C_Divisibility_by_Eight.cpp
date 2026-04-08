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
    string s; cin >> s;
    // 2i+1 4j 4k oee
    // 2i 4j+2 4k oee
    // 2i 4j+1 4k+2 eoe
    // 2i+1 4j+3 4k+2 ooe
    vi arr;
    loop(0, s.size()) {
        arr.push_back(s[i]-'0');
    }
    
    // size 1
    for (int i=0;i<arr.size();i++) {
        if (arr[i]%8==0) {
            yes;
            cout<<arr[i]<<endl;
            return;
        }
    }
    // size 2
    for (int i=0;i<arr.size();i++) {
        for (int j=i+1;j<arr.size();j++) {
            if ((10*arr[i]+arr[j])%8==0) {
                yes;
                cout<<(10*arr[i]+arr[j])<<endl;
                return;
            }
        }
    }
    // size 3
    for (int i=0;i<arr.size();i++) {
        for (int j=i+1;j<arr.size();j++) {
            for (int k=j+1;k<arr.size();k++) {
                if ((100*arr[i]+10*arr[j]+arr[k])%8==0) {
                    yes;
                    cout<<(100*arr[i]+10*arr[j]+arr[k])<<endl;
                    return;
                }
            }
        }
    }
    no;
}

int32_t main() {
    fast_io();
    solve();
    return 0;
}