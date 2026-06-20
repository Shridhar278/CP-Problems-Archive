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
void _print(double a) {
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

// saved the day
auto fracCmp = [](const vi& a, const vi& b){
    return a[0] * b[1] < b[0] * a[1];
};

int mod_pow(int base, int exp) {
    int result = 1;
    base %= mod9;
    while (exp > 0) {
        if (exp & 1) result = (result * base) % mod9;
        base = (base * base) % mod9;
        exp >>= 1;
    }
    return result;
}

int mod_inv(int a) {
    if (a % mod9 == 0) return -1;
    return mod_pow(a, mod9 - 2);
}

// nice PAIR-WISE check for #inversions
// reduce n! to n^2

// still double-comparing issue STAYS

#define check 0
void solve() {
    int n; cin >> n;
    vector<int> a(n); loop(0, n) cin >> a[i];
    vector<int> b(n); loop(0, n) cin >> b[i];

    // entirely* NEW DOMAIN of REASONING
    // instead of n! as a whole 
    // for specific b_i & b_j #inversions is just all 1/n(n+1) cases count which are
    // possibly reduce O(n!) to O(n^2)

    // so for i&j if ai*bi>aj*bj
    // if bi/bj>aj/ai then inverted so count for each

    // organise bi/bj
    vvi bb;
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            if (i==j) {
                continue;
            }
            bb.push_back(vi({b[i], b[j]}));
        }
    }
    vvi aa;
    for (int i=0;i<n;i++) {
        for (int j=i+1;j<n;j++) {
            aa.push_back(vi({a[j], a[i]}));
        }
    }

    sort(aa.begin(), aa.end(), [](const vi& a, const vi& b) {
        return a[0] * b[1] < b[0] * a[1];
    });
    sort(bb.begin(), bb.end(), [](const vi& a, const vi& b) {
        return a[0] * b[1] < b[0] * a[1];
    });

    debug(bb)
    debug(aa)
    int ans=0;

    // can go smarter but this is still correct
    // for (int i=0;i<n;i++) {
    //     for (int j=i+1;j<n;j++) {
    //         // need CUSTOM search double/double equated creating some anomalies;
    //         // floating point precision errors > 17 digits 0.1+0.2!=0.3
    //         auto it = upper_bound(poss.begin(), poss.end(), a[j]/a[i]);
    //         // 1 2 3 4 4 5 6
    //         ans+=(int)(poss.end()-it);
    //         ans%=mod9;
    //     }
    // }

    // 2-pointer
    int last=0;
    for (int i=0, j=0;j<n*(n-1);j++) {
        int curr=0;
        for (;i<n*(n-1)/2;i++) {
            // bb[0]/bb[1] > aa[0]/aa[1]
            if (bb[j][0]*aa[i][1]>aa[i][0]*bb[j][1]) {
                curr++;
            } else {
                break;
            }
        }
        ans+=last+=curr;
        ans%=mod9;
        debug(last)
        debug(curr)
        debug(ans)
    }

    // 1/n(n-1) common remainder
    ans*=mod_inv(n);
    ans%=mod9;
    ans*=mod_inv(n-1);
    ans%=mod9;

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