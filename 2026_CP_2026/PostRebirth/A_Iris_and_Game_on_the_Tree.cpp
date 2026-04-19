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

void traverse(int node, vvi& adjList, vi& done, set<int>& leaves) {
    int count=0;
    done[node]=1;
    for (auto vtx : adjList[node]) {
        if (done[vtx]==0) {
            count++;
            traverse(vtx, adjList, done, leaves);
        }
    }
    if (count==0) {
        leaves.insert(node);
    }
}

#define check 1
void solve() {
    int n; cin >> n;
    vvi adjList(n);
    int x, y;
    loop(0, n-1) {
        cin >> x >> y;
        adjList[x-1].push_back(y-1);
        adjList[y-1].push_back(x-1);
    }
    // find leaves;
    set<int> leaves;
    vi done(n, 0);
    traverse(0, adjList, done, leaves);
    string state; cin >> state;
    int lq=0, l1=0, l0=0;
    int count=0;
    for (int i=1;i<n;i++) {
        if (state[i]=='?') {
            count++;
        }
        if (leaves.count(i)) {
            if (state[i]=='?') {
                lq++;
            } else if (state[i]=='0') {
                l0++;
            } else {
                l1++;
            }
        }
    }
    count-=lq;
    if (state[0]=='0') {
        cout<<l1+(lq+1)/2<<endl;
    } else if (state[0]=='1') {
        cout<<l0+(lq+1)/2<<endl;
    } else {
        if (l0!=l1) {
            cout<<max(l0, l1)+lq/2<<endl;
        } else {
            if (count%2==0) {
                cout<<l0+lq/2<<endl;
            } else {
                cout<<l0+(lq+1)/2<<endl;
            }
        }
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