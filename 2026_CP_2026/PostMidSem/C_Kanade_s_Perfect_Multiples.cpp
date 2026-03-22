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

// no proof no wisdom
// WILL FIGURE OUT

#define check 0
void solve() {
    int n, k; cin >> n >> k;
    map ispresent;
    map isnotremaining;
    map isans;
    map iscovered;
    vi arr(n);
    loop(0, n) {
        cin >> arr[i];
        ispresent[arr[i]]=1;
    }
    loop(1, k+1) {
        if (isnotremaining[i]==0) {
            int x=i;
            int fail=0;
            while (x<=k) {
                if (ispresent[x]==0) {
                    fail=1;
                    break;
                }
                x+=i;
            }
            if (!fail) {
                int a=1;
                debug(a)
                isans[i]=1;
                x=i;
                while (x<=k) {
                    isnotremaining[x]=1;
                    iscovered[x]=1;
                    x+=i;
                }
            }
            debug(iscovered)
            debug(isans)
            debug(ispresent)
            debug(isnotremaining)
        }
    }
    int fail=0;
    int count=0;
    loop(0, n) {
        if (iscovered[arr[i]]==0) {
            fail=1;
        }
    }
    if (fail) {
        cout<<-1<<endl;
        return;
    }
    loop(1, k+1) {
        if (isans[i]==1) {
            count++;
        }
    }
    cout<<count<<endl;
    for (auto &[ele, val] : isans) {
        if (val==1) {
            cout<<ele<<" ";
        }
    }
    cout<<endl;
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