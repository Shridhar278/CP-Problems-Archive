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

// let's GO

#define check 0
void solve() {
    int n; cin >> n;
    vi arr(n+1); loop(0, n) cin >> arr[i+1];
    vvi adj(n+1);
    int x, y;
    loop(0, n-1) {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vi solved(n+1, 0); // just checker FLAG
    vi change(n+1, 0); // per step forward CHANGE           // EXCLUSIVE
    vi result(n+1, 0); // actual answer (max one perform)
    vi scores(n+1, 0); // total score NO changes            // INCLUSIVE
    vi height(n+1, 0); // height of sub-tree rooted there
    vi remaining(n+1, 0);

    // fix PUSH LOGIC (work only when ALL kids are DONE not ONCE)
    queue<int> curr;
    debug(adj)
    loop(1, n+1) {
        if (i!=1 and adj[i].size()==1) {
            curr.push(i);
        }
        change[i]=arr[i];
        remaining[i]=(int)adj[i].size();
        if (i!=1) {
            remaining[i]--;
        }
    }

    while(!curr.empty()) {

        int now=curr.front();
        curr.pop();
        if (solved[now]==1) {
            continue;
        }
        solved[now]=1;
        debug(now)

        int ht1=-1, ht2=-1;
        int idx1=-1, idx2=-1;

        for (auto ele : adj[now]) {
            if (!solved[ele]) {
                remaining[ele]--;
                if (!remaining[ele]) {
                    curr.push(ele);
                }
                scores[ele]+=scores[now]+change[now];
                change[ele]+=change[now];
                height[ele]=max(height[ele], height[now]+1);
            } else {
                // result back-tracking
                // children's "upar-niche"
                if (height[ele]>=ht1) {
                    ht2=ht1;
                    idx2=idx1;
                    ht1=height[ele];
                    idx1=ele;
                } else if (height[ele]>=ht2) {
                    ht2=height[ele];
                    idx2=ele;
                }
                result[now]=max(result[now], result[ele]);
            }
        }
        // result logic think about it : HEIGHT of sub-trees needed
        // result is score + max(height*change)
        int best=0;

        debug(ht1)
        debug(idx1)
        debug(ht2)
        debug(idx2)

        // ht1
        for (auto ele : adj[now]) {
            if (ele!=idx1 and solved[ele]) {
                best = max(best, change[ele]*(ht1+1));
            }
        }
        //ht2
        for (auto ele : adj[now]) {
            if (ele!=idx2 and solved[ele]) {
                best = max(best, change[ele]*(ht2+1));
            }
        }

        result[now]=max(result[now], best);

        debug(solved)
        debug(remaining)
        debug(change)
        debug(result) 
        debug(scores) 
        debug(height)
    
    }
    for (int i=1;i<n+1;i++) {
        cout<<scores[i]+result[i]<<" ";
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