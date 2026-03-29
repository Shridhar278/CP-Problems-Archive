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

vi ans(200001, 1);

#define check 1
void solve() {
    // .0 -> a<b .1 -> a=b
    // vvi dp(n+1, vi(2));
    // dp[1][0]=1;
    // dp[1][1]=0;
    int last0=1, last1=0;
    // vvi count(n+1, vi(2));
    // count[1][0]=1;
    // count[1][1]=0;
    int count0=1, count1=0;
    loop(2, 200001) {
        // count[i][0]=(2*count[i-1][1]+count[i-1][0])%mod7;
        // count[i][1]=(count[i-1][0])%mod7;
        // dp[i][1]=dp[i-1][0]%mod7;
        // dp[i][0]=((dp[i-1][0]+count[i-1][0])*1+(dp[i-1][1]+count[i-1][1])*2)%mod7;
        int nc0=2*count1+count0;
        int nc1=count0;
        int l0 = (last0+count0)*1+(last1+count1)*2;
        int l1= last0;
        count0=nc0%mod7;
        count1=nc1%mod7;
        last0=l0%mod7;
        last1=l1%mod7;
        ans[i]=(last0+last1)%mod7;
    }
    // cout<<(dp[n][0]+dp[n][1])%mod7<<endl;
    
}

int32_t main() {
    fast_io();
    int test;
    cin >> test;
    solve();
    // pre-compute SAVE TIME
    // one check takes O(n)
    // query takes O(1) n times done
    
    // previously worst case querying took n*O(n)=O(n^2)
    while (test--) {
        int n; cin >> n;
        cout<<ans[n]<<endl;
    }
    return 0;
}