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
    int n; cin >> n;
    vvi adj(n+1);
    int x, y;
    loop(0, n-1) {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    int a=0, b=0;
    vi leafs(n+1, 0);

    vi visited(n+1, 0);
    queue<int> q;
    for (int i=1;i<=n;i++) {
        if (adj[i].size()==1 and i!=1) {
            q.push(i);
        }
        if (i==1) {
            visited[i]=(int)adj[i].size();
        } else {
            visited[i]=(int)adj[i].size()-1;
        }
    }

    while(!q.empty()) {
        int curr = q.front();
        q.pop();
        if (visited[curr]!=0) {
            continue;
        }
        
        int ans=0;
        for (auto ele : adj[curr]) {
            if (visited[ele]!=0) {
                visited[ele]--;
                if (visited[ele]==0) q.push(ele);
            } else {
                ans+=leafs[ele];
            }
        }

        leafs[curr]=max(ans, (int)1);
        debug(leafs)
    }

    int que; cin >> que;
    for (int i=0;i<que;i++) {
        cin >> x >> y;
        cout<<leafs[x]*leafs[y]<<endl;
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