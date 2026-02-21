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

int formula(int a, int x, int b) {
    // a 1 2 x 3 4 5 b(x)
    // 0 1 2 3 4 5 6 7
    int ans = (b-a)*(b-a+1)/2-(b-x-1)*(b-x)/2;
    return ans;
}

// chance to move BACK when (*it).second is less than ban
// elements not considered had to be ignored.
// hence, " or (*it).second<ban" applied

#define check 0
void solve() {
    int n; cin >> n;
    vi arr(n); loop(0, n) cin >> arr[i];
    map stop_here; 
    int ans=0;
    int ban=0;
    // 1 4 5 4 6 4 5 8
    // 1 2 1 3
    // MOVE backwords ISSUE address // NICE
    loop(0, n) {
        auto it = stop_here.find(arr[i]);
        if (it==stop_here.end() or (*it).second<ban) {
            stop_here[arr[i]]=i;
        } else {
            // a formula
            ans+=formula(ban, (*it).second, i);
            ban=(*it).second+1;
            stop_here[(*it).first]=i;
        }
        debug(ans); debug(arr[i]); 
        debug(i); debug(ban);
        debug((*it).second);

    }
    ans+=(n-ban)*(n-ban+1)/2;
    cout<<ans<<endl;
}

int32_t main() {
    fast_io();
    solve();
    return 0;
}