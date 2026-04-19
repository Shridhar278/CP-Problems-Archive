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

// YOU DID IT !!!!
// no. od repitions reduced drastically
// STILL HIGHER LEVEL ANALYSIS Required

void visit(set<int>& nums, int a, int b, set<pair<int, int>>& edges, vi& in_tree) {
    int x=b;
    int last;
    if (a==b) {
        nums.erase(b);
        return;
    }
    int nexus=0;
    while(x!=a) {
        debug(a)
        debug(b)
        debug(x)
        last=x;
        cout<<"? "<<a<<" "<<x<<"\n"<<flush;
        cin >> x;
        if (x!=a and in_tree[x]) {
            nexus=1;
            break;
        }
    }
    if (!nexus) {
        edges.insert({a, last});
        nums.erase(last);
        in_tree[last]=1;
    } else {
        visit(nums, x, last, edges, in_tree);
    }
    visit(nums, last, b, edges, in_tree);
}

void solve() {
    int n; cin >> n;
    set<int> nums;
    vi in_tree(n+1, 0); // ease of access; 
    in_tree[1]=1;
    loop(1, n) {
        nums.insert(i+1);
    }
    set<pair<int, int>> edges;
    while(!nums.empty()) {
        visit(nums, 1, *nums.begin(), edges, in_tree);
    }
    cout<<"! ";
    for (auto edge : edges) {
        cout<<edge.first<<" "<<edge.second<<" ";
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