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
template<class T> void _print(multiset<T> v) {
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
#define yes cout<<"Yes\n"
#define no cout<<"No\n"
#define el cout<<endl;

const int mod7 = 1e9 + 7;
const int mod9 = 998244353;
const int INF = 1e18;
const double EPS = 1e-9;

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

// GO reverse

// trying PLAIN greedy FIRST
// ITS POSSIBLE lets GO
// cuz. choice MATTERS

// COMPLETED

#define check 0
bool traverse(int n, multiset<int>& arr) {
    debug(n)
    debug(arr)
    if (n==1) {
        auto z = arr.find(n);
        if (z!=arr.end()) {
            arr.erase(z);
            return true;
        } else {
            return false;
        }
    } else {
        auto z = arr.find(n);
        if (z!=arr.end()) {
            arr.erase(z);
            return true;
        }
    }

    int x=n/2, y=(n+1)/2;

    auto it1=arr.find(x);
    if (it1!=arr.end()) {
        arr.erase(it1);
    } else {
        if(!traverse(x, arr)) {
            return false;
        }

    }

    auto it2=arr.find(y);
    if (it2!=arr.end()) {
        arr.erase(it2);
    } else {
        if (!traverse(y, arr)) {
            return false;
        }
    }

    return true;
}

void solve() {
    int n, m; cin >> n >> m;
    multiset<int> arr;
    multiset<int> target;
    int sum1=0, sum2=0;

    int x; 
    loop(0, n) {
        cin >> x;
        arr.insert(x);
        sum1+=x;
    }
    loop(0, m) {
        cin >> x;
        target.insert(x);
        sum2+=x;
    }

    if (sum1!=sum2) {
        no;
        return;
    }

    // the simulation starts

    for (auto ele : target) {
        if(!traverse(ele, arr)) {
            no;
            return;
        }
    }

    yes;

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