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

// solve for max area

#define check 1
void solve() {
    int n; cin >> n;
    vi arr(n); loop(0, n) cin >> arr[i];
    map<int, int> eles;
    loop(0, n) {
        eles[arr[i]]++;
    }
    int count=0;
    vi pos;
    for (auto& [key, ele] : eles) {
        count+=ele/2;
        while(ele>=2) {
            pos.push_back(key);
            ele-=2;
        }
    }
    if (count<4) {
        cout<<"NO"<<endl;
        return;
    }
    sort(pos.begin(), pos.end());
    int x = (int)(pos.size())-1;
    vi locs(4);
    if ((pos[x]-pos[0])*(pos[x-1]-pos[1])>=
        (pos[x]-pos[1])*(pos[x-1]-pos[0])) {
        locs[0]=pos[x];
        locs[1]=pos[x-1];
        locs[2]=pos[0];
        locs[3]=pos[1];
    } else {
        locs[0]=pos[x-1];
        locs[1]=pos[x];
        locs[2]=pos[0];
        locs[3]=pos[1];
    }
    cout<<"YES"<<endl;

    cout<<locs[0]<<" ";
    cout<<locs[1]<<" ";

    cout<<locs[0]<<" ";
    cout<<locs[3]<<" ";

    cout<<locs[2]<<" ";
    cout<<locs[1]<<" ";

    cout<<locs[2]<<" ";
    cout<<locs[3]<<endl;
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