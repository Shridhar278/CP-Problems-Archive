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

template<class T> void _print(vector<T> v) {
    cout << "[ ";
    for (auto i : v) {
        _print(i);
        cout << " ";
    }
    cout << "]";
}

#define debug(x) \
   do { \
        if (check) {\
            cout<<#x<<" = "; _print(x); cout<<endl; \
        } \
    } while(0)

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

// DEBUG tomorrow
// accepted
// SOME god-damn REASON that i<=sqrt(n) / i*i<=n doesn't cover the root or something
// i <= n FLEW THROUGH THE CODE
// BIG question MARK ?

#define check 0
void solve() {
    int n, k; cin >> n >> k;
    vector<string> strips(k); 
    loop(0, k) {
        cin >> strips[i];
    }
    vector<map> posalpha(26); // A to Z
    loop(0, k) {
        for(int j=0;j<n;j++) {
            posalpha[strips[i][j]-'a'][j]=1;
        }
    }
    // nice
    // iterate over factors
    debug(posalpha);
    // whenever need i<=sqrt(n) use i*i <= n for BETTER PRECISION
    for (int i=1;i<=n;i++) {
        if (n%i==0) {
        vector<int> rems(i, 0);
        for (int j=0;j<26;j++) {
            for (auto [pos, indicator] : posalpha[j]) {
                if (rems[pos%i]<n/i) {
                    rems[pos%i]++;
                }
                debug(rems);
            }
            for (int k=0;k<i;k++) {
                if (rems[k] == n/i) {
                    rems[k]=n/i+j+1;
                } else if (rems[k]<n/i) {
                    rems[k]=0;
                }
            }
        }
        bool all=true;
        string s;
        for (int k=0;k<i;k++) {
            if (rems[k] < n/i) {
                all=false;
            } else {
                s+=rems[k]-n/i-1+'a';
            }
        }
        if (all) {
            for (int k=0;k<n/i;k++) {
                cout<<s;
            }
            cout<<endl;
            return;
        }
        }
    }
    cout<<strips[0]<<endl;
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