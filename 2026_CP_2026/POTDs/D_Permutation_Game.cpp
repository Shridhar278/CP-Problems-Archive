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

#define check 0
void solve() {
    int n, k, p1, p2; cin >> n >> k >> p1 >> p2; p1--; p2--;
    vi yougoto(n);
    int x;
    loop(0, n) {
        cin >> x;
        yougoto[i]=--x;
    }
    vi arr(n); loop(0, n) cin >> arr[i];

    // go around the loop
    int curr;
    int count;
    int overall;

    curr=p1;
    count=0;
    overall=arr[p1];
    int best_p1=arr[p1]*(k-count);
    curr=yougoto[curr];
    count++;
    while(curr!=p1 and count<k) {
        best_p1=max(best_p1, overall+arr[curr]*(k-count));
        overall+=arr[curr];
        curr=yougoto[curr];
        count++;
    }

    curr=p2;
    count=0;
    overall=arr[p2];
    int best_p2=arr[p2]*(k-count);
    curr=yougoto[curr];
    count++;
    debug(best_p2)
    while(curr!=p2 and count<k) {
        best_p2=max(best_p2, overall+arr[curr]*(k-count));
        overall+=arr[curr];
        curr=yougoto[curr];
        count++;
        debug(best_p2)
    }
    debug(best_p1)
    debug(best_p2)
    if (best_p1>best_p2) {
        cout<<"Bodya"<<endl;
    } else if (best_p2>best_p1) {
        cout<<"Sasha"<<endl;
    } else {
        cout<<"Draw"<<endl;
    }
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