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
    int n, k, q; cin >> n >> k >> q;
    vvi commands(q, vector<int>(3));
    for (int i=0;i<q;i++) {
        cin >> commands[i][0] >> commands[i][1] >> commands[i][2];
    }
    vi morethank(n, -1);
    for (int i=0;i<q;i++) {
        if (commands[i][0]==1) {
            for (int j=commands[i][1]-1;j<commands[i][2];j++) {
                morethank[j]=k;
            }
        }
    }
    for (int i=0;i<q;i++) {
        debug(commands)
        if (commands[i][0]==2) {
            int count=0;
            set<int> ok={k};
            for (int j=commands[i][1]-1;j<commands[i][2];j++) {
                if (morethank[j]==k) {
                    // leave
                } else if (morethank[j]>=0) {
                    ok.insert(morethank[j]);
                }
            }
            for (int j=commands[i][1]-1;j<commands[i][2];j++) {
                if (morethank[j]==-1) {
                    while(ok.count(count)) {
                        count++;
                    }
                    morethank[j]=count;
                    count++;
                } else if (morethank[j]==k) {
                    morethank[j]++;
                }
            }
        }
    }
    for (int i=0;i<n;i++) {
        if (morethank[i]==-1) {
            morethank[i]++;
        }
        cout<<morethank[i]<<" ";
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