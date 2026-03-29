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
    if (n==1) {
        cout<<1<<endl;
        return;
    } else if (n==2) {
        cout<<-1<<endl;
        return;
    } else if (n==3) {
        cout<<-1<<endl;
        return;
    } else if (n==4) {
        cout<<"2 4 1 3"<<endl;
        return;
    }
    int it=1;
    int limit = (n/5)*5-5;
    while (it<limit) {
        cout<<it<<" "<<it+2<<" "<<it+4<<" "<<it+1<<" "<<it+3<<" ";
        it+=5;
    }
    if (n%5==0) {
        cout<<it<<" "<<it+2<<" "<<it+4<<" "<<it+1<<" "<<it+3<<" ";
    } else if (n%5==1) {
        cout<<it<<" "<<it+2<<" "<<it+4<<" "<<it+1<<" "<<it+3<<" "<<it+5;
    } else if (n%5==2) {
        cout<<it<<" "<<it+2<<" "<<it+4<<" "<<it+1<<" "<<it+6<<" "<<it+3<<" "<<it+5;
    } else if (n%5==3) {
        cout<<it<<" "<<it+2<<" "<<it+4<<" "<<it+1<<" "<<it+6<<" "<<it+3<<" "<<it+5<<" "<<it+7;
    } else {
        cout<<it<<" "<<it+2<<" "<<it+4<<" "<<it+1<<" "<<it+3<<" "<<it+6<<" "<<it+8<<" "<<it+5<<" "<<it+7;
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