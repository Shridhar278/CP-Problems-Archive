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
template<class T> void _print(set<T> v) {
    cout << "{ ";
    for (auto i : v) {
        _print(i);
        cout << " ";
    }
    cout << "}";
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

int fastexp(int base, int exp) {
    int result = 1;
    while (exp > 0) {
        if (exp & 1) { // Check if the current bit is set
            result *= base;
            result%=mod9;
        }
        base *= base; // Square the base
        base%=mod9;
        
        exp >>= 1; // Right shift the exponent
    }
    return result;
}

#define check 0
void solve() {
    int n; cin >> n;
    vvi arrs(n);
    vi arr(n+1);
    int x;
    for(int i=0;i<n;i++) {
        cin >> x;
        arrs[i]=vi({x, i+1});
        arr[i+1]=x;
    }

    sort(arrs.begin(), arrs.end(), greater<>());

    int alpha = 0;
    int result=0;
    set<int> used;
    debug(arrs)
    for (int i=0;i<n;i++) {
        int ele = arrs[i][1];
        if (used.count(ele)) {
            continue;
        }
        int pre = n-(int)used.size();
        int facts = 0;
        for (int j=1;j*j<=ele;j++) {
            if (ele%j==0) {
                if (!used.count(j)) {
                    used.insert(j);
                    facts++;
                }
                if (!used.count(ele/j)) {
                    used.insert(ele/j);
                    facts++;
                }
            }
        }
        // add (2^facts-1)
        pre-=facts;

        debug(pre)
        debug(facts)

        int x;
        x=fastexp(2, pre);
        x%=mod9;
        x*=fastexp(2, facts)-1; 
        x%=mod9;
        
        alpha+=x;
        debug(x)

        x*=arrs[i][0];
        x%=mod9;
        result+=x;

        result%=mod9;
        debug(result)
        debug(alpha)
        debug(used)
    }

    cout<<result<<endl;
}

int32_t main() {
    fast_io();
    solve();
    return 0;
}