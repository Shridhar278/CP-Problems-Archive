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

// gg LOOK solution

#define check 0
void solve() {
    int n, k; cin >> n >> k;
    string s; cin >> s;

    vi pairs;
    int start=0;

    // count distinct bracket sequences independent
    for (int i=0;i<n;i++) {
        if (!start) {
            if (s[i]=='(') {
                pairs.push_back(i);
                start=1;
            } else {
                // ignore
            }
        } else {
            if (s[i]=='(') {
                // ignore
            } else {
                start=0;
            }
        }
    }
    
    vi bools(n);
    debug(s)
    debug(pairs)
    int a, b;
    for (int i=0;i<(int)pairs.size();i++) {
        a=0;
        b=0;
        if (i+1==(int)pairs.size()) {
            for (int j=pairs[i];j<n;j++) {
                if (s[j]=='(') {
                    a++;
                } else {
                    b++;
                }
            }
            if (a>b) {
                for (int j=pairs[i];j<pairs[i]+a;j++) {
                    if (k>0) {
                        bools[j]=1;
                        k--;
                    } else {
                        break;
                    }                
                }
            } else {
                for (int j=n-1;j>=n-b;j--) {
                    if (k>0) {
                        bools[j]=1;
                        k--;
                    } else {
                        break;
                    }                   
                }
            }
        } else {
            for (int j=pairs[i];j<pairs[i+1];j++) {
                if (s[j]=='(') {
                    a++;
                } else {
                    b++;
                }
            }
            if (a>b) {
                for (int j=pairs[i];j<pairs[i]+a;j++) {
                    if (k>0) {
                        bools[j]=1;
                        k--;
                    } else {
                        break;
                    }
                }
            } else {
                for (int j=pairs[i+1]-1;j>=pairs[i+1]-b;j--) {
                    if (k>0) {
                        bools[j]=1;
                        k--;
                    } else {
                        break;
                    }               
                }
            }
        }
        debug(a)
        debug(b)
        debug(bools)
    }

    for (int i=0;i<n;i++) {
        cout<<bools[i];
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