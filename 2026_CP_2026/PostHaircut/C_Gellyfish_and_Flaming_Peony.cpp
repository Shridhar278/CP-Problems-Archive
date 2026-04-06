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

#define check 1
void solve() {
    int n; cin >> n;
    vi arr(n); loop(0, n) cin >> arr[i];
    int gcd=arr[0];
    loop(1, n) {
        gcd = __gcd(gcd, arr[i]);
    }
    int ones=0;
    loop(0, n) {
        arr[i]/=gcd;
        if (arr[i]==1) {
            ones++;
        }
    }
    if (ones>0) {
        cout<<n-ones<<endl;
        return;
    }
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            if (__gcd(arr[i], arr[j])==1) {
                cout<<n<<endl;
                return;
            }
        }
    }
    // smallest sub-sequence whose gcd=1
    vector<set<int>> factors(n);
    set<int> primes;
    loop(0, n) {
        int count=2;
        while (arr[i]>1) {
            if (arr[i]%count==0) {
                primes.insert(count);
                factors[i].insert(count);
                arr[i]/=count;
                continue;
            }
            count++;
        }
    }
    // now we have remove stuff
    // 1 1 0 0
    // 1 0 1 0
    // 1 0 0 1
    // 0 1 1 1

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