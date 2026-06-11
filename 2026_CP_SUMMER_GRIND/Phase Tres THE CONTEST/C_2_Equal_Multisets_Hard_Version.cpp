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

// LATER ON

// all MATCH condition
// or CYCLES

// c'mon i got this the last time


// BRAIN DAMAGE
// CP do tmrw NOW

#define check 0
void solve() {
    int n, k; cin >> n >> k;

    vi og(n);
    loop(0, n) {
        cin >> og[i];
    }

    vi arr(n);
    loop(0, n) {
        cin >> arr[i];
    }

    vi issues(n, 0);
    vi locked(n, 0);
    loop(0, n) {
        if (arr[i]==og[i] and locked[i%k]!=-1) {
            locked[i%k]=1;
        }
        if (arr[i]!=-1 and arr[i]!=og[i]) {
            issues[i%k]=1;
            locked[i%k]=-1;
        }
    }
    loop(0, k) {
        if (locked[i]==-1) {
            locked[i]=0;
        }
    }

    // all match
    int flag1=0;
    loop(0, n) {
        if (arr[i]==-1) {
            // okay
        } else {
            if (arr[i]!=og[i]) {
                flag1=1;
                break;
            }
        }
    }
    if (!flag1) {
        yes;
        return;
    }

    vi isto1(k, 0);
    int flag2=0;
    for (int i=0;i<n;i++) {
        debug(isto1)
        if (isto1[i%k]){
            if (og[i]!=isto1[i%k]) {
                if (issues[i%k]) {
                    flag2=1;
                    break;
                }
            }
        } else {
            if (!locked[i%k]) {
                isto1[i%k]=og[i];
            }
        }
    }
    if (flag2) {
        no;
        return;
    }

    vi isto2(k, 0);
    int flag3=0;
    for (int i=0;i<n;i++) {
        debug(isto2)
        if (isto2[i%k]) {
            if (arr[i]!=-1) {
                if (arr[i]!=isto2[i%k]) {
                    if (issues[i%k]) {
                        flag3=1;
                        break;
                    }
                }
            }
        } else {
            if (arr[i]!=-1 and !locked[i%k]) {
                isto2[i%k]=arr[i];
            }
        }
    }
    if (flag3) {
        no;
        return;
    }

    // sanitary the CASES are same OVERALL check
    multiset<int> now;
    loop(0, k) {
        if (isto2[i]) {
            now.insert(isto2[i]);
        }
    }
    loop(0, k) {
        if (locked[i]) {
            auto it = now.find(isto2[i]);
            if (it!=now.end()) {
                now.erase(it);
            }
        }
    }
    loop(0, k) {
        auto it = now.find(isto1[i]);
        if (it!=now.end()) {
            now.erase(it);
        }
    }
    if ((int)now.size()) {
        no;
        return;
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