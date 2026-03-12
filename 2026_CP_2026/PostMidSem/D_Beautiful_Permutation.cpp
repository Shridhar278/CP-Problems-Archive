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
            cout<<#x<<" = "; _print(x); cout<<endl \
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

//recursion
void search(int n, int li, int ri, int change) {
    int x, y;
    int oli=li, ori=ri;
    ri = (li+ri)/2;
    cout<<"1 "<<li<<" "<<ri<<endl<<flush;
    cin>>x;
    cout<<"2 "<<li<<" "<<ri<<endl<<flush;
    cin>>y;
    if (y-x==change) {
        if (li==ri) {
            cout<<"! "<<li<<" "<<ri<<endl<<flush;
            return;
        }
        search(n, li, ri, change);
    } else {
        int new_change = y-x;
        if (y==x) {
            oli = (oli+ori+1)/2;
            search(n, oli, ori, change);
        } else {
            cout<<"! "<<ri+1-new_change<<" "<<ri+change-new_change<<endl<<flush; 
            return;
        }
    }
}

//YES

#define check 1
void solve() {
    int n; cin >> n;
    // 1 l r : OG // 2 l r : MODIFIED
    int next=0, li=1, ri=n;
    int x, y;
    cout<<"1 "<<li<<" "<<ri<<endl<<flush;
    cin>>x;
    cout<<"2 "<<li<<" "<<ri<<endl<<flush;
    cin>>y;
    int change=y-x;
    search(n, li, ri, change);
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