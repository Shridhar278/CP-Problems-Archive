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

// minor OVERFLOW error FIXED with (int)0 instead of 0
// &

// GAME PLAN
// 6 6 2 4 3 0 1 8
// calc. MEX once for each SMARTLY

// then repeat FIRST MULTIMOVE

// 5 5 2 4 3 0 1 5.1
// 6 6 2 4 3 0 1 6.even
// 5 5 2 4 3 0 1 5.odd         
// ...
// 0 1 1
// 0 2 2
// 0 1 1
// 0 2 2
// 0 1 1

// 0 0 1 2 2 3 4 4 5
// 6 6 1 6 6 3 6 6 5
// 0 0 0 0 0 0 0 0 0

// 0 1 2 2 3 4 4 5
// 0 1 6 6 3 6 6 5
// 0 1 2 2 2 2 2 2
// do twice then STABILIZE
// 0 1 2 3 5 5 5
// 0 1 2 3 3 3 3 3

// 1 1 1 1
// 0 0 0 0

#define check 1
void solve() {
    int n, k; cin >> n >> k;
    vi arr(n);
    int x;
    loop(0, n) {
        cin >> x;
        arr[i]=x;
    }
    // MEX. think 'bout it
    
    // move 1
    vi counts1(n+1, 0);
    for (int i=0;i<n;i++) {
        counts1[arr[i]]++;
    }
    int mex1=0;
    for (int i=0;i<=n;i++) {
        if (counts1[mex1]>0) {
            mex1++;
        } else {
            break;
        }
    }
    for (int i=0;i<n;i++) {
        if (arr[i]<mex1) {
            if (counts1[arr[i]]>1) {
                arr[i]=mex1;
            }        } else {
            arr[i]=mex1;
        }
    }
    int ans1 = accumulate(arr.begin(), arr.end(), (int)0);
    if (k==1) {
        cout<<ans1<<endl;
        return;
    }

    // move 2
    vi counts2(n+1, 0);
    for (int i=0;i<n;i++) {
        counts2[arr[i]]++;
    }
    int mex2=0;
    for (int i=0;i<=n;i++) {
        if (counts2[mex2]>0) {
            mex2++;
        } else {
            break;
        }
    }
    for (int i=0;i<n;i++) {
        if (arr[i]<mex2) {
            if (counts2[arr[i]]>1) {
                arr[i]=mex2;
            }        
        } else {
            arr[i]=mex2;
        }
    }
    int ans2=accumulate(arr.begin(), arr.end(), (int)0);

    // move 3
    vi counts3(n+1, 0);
    for (int i=0;i<n;i++) {
        counts3[arr[i]]++;
    }
    int mex3=0;
    for (int i=0;i<=n;i++) {
        if (counts3[mex3]>0) {
            mex3++;
        } else {
            break;
        }
    }
    for (int i=0;i<n;i++) {
        if (arr[i]<mex3) {
            if (counts3[arr[i]]>1) {
                arr[i]=mex3;
            }        
        } else {
            arr[i]=mex3;
        }
    }
    int ans3=accumulate(arr.begin(), arr.end(), (int)0);

    // (k-1)mod2
    if (k%2) {
        cout<<ans3<<endl;
    } else {
        cout<<ans2<<endl;
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