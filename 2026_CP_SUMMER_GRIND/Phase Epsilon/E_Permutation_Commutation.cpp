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

template<class T> void _print(pair<T, T> v) {
    cout << "{ ";
    _print(v.first);
    cout << " ";
    _print(v.second);
    cout << " }";
}

template<class T> void _print(queue<T> v) {
    cout << "{ ";
    for (auto i : v) {
        _print(i);
        cout << " ";
    }
    cout << "}";
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

// #1 deterministic
// #2 trial & error

// FIX the TRIAL & ERROR part then UP and RUNNIN'

#define check 0
void solve() {
    int n; cin >> n;
    vi a(n); loop(0, n) cin >> a[i];
    vi b(n); loop(0, n) cin >> b[i];
    vi a_inv(n);
    loop(0, n) {
        a_inv[a[i]-1]=i+1;
    }

    queue<pair<int, int>> dtr;
    loop(0, n) {
        if (b[i]!=-1) {
            dtr.push({i+1, b[i]});
        }
    }

    vi ans(n, 0);
    // deterministic
    while(!dtr.empty()) {
        pair<int, int> curr = dtr.front();
        dtr.pop();

        if (ans[curr.first-1]==a[curr.second-1]) {
            // ignore
        } else if (ans[curr.first-1]==0) {
            ans[curr.first-1]=a[curr.second-1];
        } else {
            no;
            return;
        }

        b[curr.first-1]=curr.second;

        // a-1(this one) CHECK
        if (ans[a_inv[curr.first-1]-1]==curr.second) {
            // not sure
        } else if (ans[a_inv[curr.first-1]-1]==0) {
            ans[a_inv[curr.first-1]-1]=curr.second;
        } else {
            no;
            return;
        }

        // b-1(this one) COLD FACT
        if (b[a[curr.first-1]-1]==-1) {
            dtr.push({a[curr.first-1]-1+1, a[curr.second-1]-1+1});
        }
        
    }

    debug(ans)
    debug(b)
    // trial & error
 
    set<int> rems;
    vi ispresent(n, 0);
    for (int i=0;i<n;i++) {
        if (b[i]!=-1) {
            ispresent[b[i]-1]=1;
        }
    }
    loop(0, n) {
        if (ispresent[i]==0) {
            rems.insert(i+1);
        }
    }
    auto it = rems.begin();
    for (int i=0;i<n;i++) {
        if (b[i]==-1) {
            b[i]=*it;
            it++;
        }
    }

    vi count(n+1, 0);
    for (int i=0;i<n;i++) {
        count[b[i]]++;
    }
    for (int i=1;i<=n;i++) {
        if (count[i]>1) {
            no;
            return;
        }
    }

    yes;
    for (int i=0;i<n;i++) {
        cout<<b[i]<<" ";
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