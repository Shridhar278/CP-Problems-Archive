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

bool find_factors(int n, int k, vi& curr, vi& tri) {
    if (k==0 and n==0) {
        return true;
    }
    if (k<0 or n<0) {
        return false;
    }
    for (int i=curr.back();i>=1;i--) {
        if (k>=tri[i]) {
            vi rn=curr; rn.push_back(i);
            if (find_factors(n-i,k-tri[i], rn, tri)) {
                curr=rn;
                return true;
            }
        }
    }
    return false;
}

#define check 0
void solve() {
    int n, k; cin >> n >> k;
    vi tri(31); loop(0, 31) tri[i]=i*(i+1)/2;
    vi factors;
    k=n*(n+1)/2-k;
    for (int i=30;i>=1;i--) {
        if (k>=tri[i]) {
            vi rn={i};
            if (find_factors(n-i, k-tri[i], rn, tri)) {
                factors=rn;
                break;
            }
        }
    }
    int tn=accumulate(factors.begin(), factors.end(), 0);
    int tk=0; loop(0, (int)factors.size()) tk+=tri[factors[i]];
    if (n!=tn or k!=tk) {
        cout<<0<<endl;
        return;
    }
    debug(factors)

    vi ans(n); loop(0, n) ans[i]=n-i;
    int i=0;
    for (auto ele : factors) {
        sort(ans.begin()+i, ans.begin()+i+ele);
        i+=ele;
    }
    
    loop(0, n) {
        cout<<ans[i]<<" ";
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