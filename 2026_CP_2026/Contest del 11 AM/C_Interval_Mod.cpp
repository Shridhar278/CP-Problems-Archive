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

// NEW DIMENSION OPENED

#define check 0
void solve() {
    int n, k, p, q; cin >> n >> k >> p >> q;
    vi arr(n); loop(0, n) cin >> arr[i];
    if (p != max(p, q)) {
        int t=p;
        p=q;
        q=t;
    }
    vi direct(n); loop(0, n) direct[i]=arr[i]%q;
    vi indirect(n); 
    loop(0, n) {
        indirect[i]=arr[i]%p;
        indirect[i]=indirect[i]%q;
    }
    vi cutoff(n); loop(0, n) cutoff[i]=direct[i]-indirect[i];
    // some derivate of Kadane's Algo
    int ans=0;
    loop(0, n) {
        ans+=direct[i];
    }
    int i=0, j=0, curr=0, best=0, last=0;
    while(j!=n) {
        curr+=cutoff[j];
        last+=cutoff[j];
        if ((j-i+1)>=k) {
            best = max(curr, best);
        }
        if (curr<0) {
            ans-=best;
            last=curr;
            i=j; i++;
            best=0;
            curr=0;
        }
        debug(best)
        debug(curr)
        debug(i)
        debug(j)
        j++;
    }
    if (j-i>=k) {
        ans-=best;
    } else {
        ans-=max(curr+last, (int)0);
    }
    cout<<ans<<endl;
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