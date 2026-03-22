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

// this is going to be a lesson
// cutely proved the INTUITUVE answer
// NO NEED of STALLING, no benefit in the long run, can only be equal OR losses

#define check 0
void solve() {
    int n, k, p, m;
    cin >> n >> k >> p >> m;
    vi costs(n);
    loop(0, n) {
        cin >> costs[i];
    }
    // try simulation the process looks a periodic
    int count=0;
    int cost=0;
    int pos=p-1;
    while(cost<m) {
        debug(cost)
        debug(costs)
        if (pos<=k-1) {
            cost+=costs[pos];
            int val = costs[pos];
            if (cost>m) {
                break;
            }
            count++;
            costs.erase(costs.begin()+pos);
            costs.push_back(val);
            pos=n-1;
        } else {
            auto move_it = min_element(costs.begin(), costs.begin()+k);
            int val = *move_it;
            cost+=val;
            if (cost>m) {
                break;
            }
            costs.erase(move_it);
            costs.push_back(val);
            pos--;
        }
    }
    cout<<count<<endl;
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