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

// compute inverse stuff

int fast_exp(int base, int exp) {
    int result=1;
    base%=mod7;
    while(exp>0) {
        if (exp & 1) {
            result=(result*base)%mod7;
        }
        base=(base*base)%mod7;
        exp=exp>>1;
    }
    return result;
}

#define check 0
void solve() {
    int a, b, n; cin >> a >> b >> n;
    // big summation
    vi fact(min(n, mod7)+1); fact[0]=1;
    for (int i=1;i<=min(n, mod7);i++) {
        fact[i]=(fact[i-1]*i)%mod7;
    }
    vi invfact(min(n, mod7)+1);
    for (int i=0;i<=min(n, mod7);i++) {
        invfact[i]=fast_exp(fact[i], mod7-2);
        invfact[i]%=mod7;
    }
    int invb=fast_exp(b, mod7-2);
    int ans=0;
    ans+=fast_exp(b-a, n);
    ans%=mod7;
    ans*=fast_exp(invb, n);
    ans%=mod7;
    for (int i=1;2*i<=n+1;i++) {
        int term=1;
        term*=fact[min(n+1-i, mod7)];
        term%=mod7;
        term*=invfact[min(i, mod7)];
        term%=mod7;
        term*=invfact[min(n+1-2*i, mod7)];
        term%=mod7;
        debug(term)
        debug(fact[min(n+1-i, mod7)])
        debug(invfact[min(i, mod7)])
        debug(invfact[min(n+1-2*i, mod7)])

        term*=fast_exp(a, i);
        term%=mod7;
        term*=fast_exp(b-a, n-i);
        term%=mod7;
        debug(term)
        debug(fast_exp(a, i))
        debug(fast_exp(b-a, n-i))

        term*=fast_exp(invb, n);
        term%=mod7;
        debug(term)

        ans+=term;
        ans%=mod7;
        debug(ans)
    }
    cout<<ans<<endl;
}

int32_t main() {
    fast_io();

    solve();
    return 0;
}