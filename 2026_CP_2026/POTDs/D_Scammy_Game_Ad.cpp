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
template<class T> void _print(pair<T, T> v) {
    cout << "{ ";
    _print(v.first);
    cout << " ";
    _print(v.second);
    cout << "}";
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
    vector<vector<pair<int, int>>> ops(n, vector<pair<int, int>>());
    vector<int> multiply02(n, 0);
    vector<int> multiply03(n, 0);
    vector<int> multiply12(n, 0);
    vector<int> multiply13(n, 0);
    char c; int x;
    loop(0, n) {
        cin >> c; cin >> x;
        if (c=='+') {
            ops[i].push_back({0, x});
        } else {
            ops[i].push_back({1, x});
            if (x==2) {
                multiply02[i]=1;
            } else {
                multiply03[i]=1;
            }
        }
        cin >> c; cin >> x;
        if (c=='+') {
            ops[i].push_back({0, x});
        } else {
            ops[i].push_back({1, x});
            if (x==2) {
                multiply12[i]=1;
            } else {
                multiply13[i]=1;
            }
        }
    }
    int last;
    last=n;
    for (int i=n-1;i>0;i--) {
        if (multiply02[i]==1) {
            last=i;
        }
        multiply02[i]=last-i;
    }
    last=n;
    for (int i=n-1;i>0;i--) {
        if (multiply03[i]==1) {
            last=i;
        }
        multiply03[i]=last-i;
    }
    last=n;
    for (int i=n-1;i>0;i--) {
        if (multiply12[i]==1) {
            last=i;
        }
        multiply12[i]=last-i;
    }
    last=n;
    for (int i=n-1;i>0;i--) {
        if (multiply13[i]==1) {
            last=i;
        }
        multiply13[i]=last-i;
    }
    // simulate;
    debug(multiply02)
    debug(multiply03)
    debug(multiply12)
    debug(multiply13)
    int p0=1, p1=1;
    int total=0;
    if (ops[0][0].first==0) {
        total+=ops[0][0].second;
    } else {
        total+=p0*(ops[0][0].second-1);
    }
    if (ops[0][1].first==0) {
        total+=ops[0][1].second;
    } else {
        total+=p1*(ops[0][1].second-1);
    }
    int m02, m03, m12, m13;
    pair<int, int> m0_now, m1_now;
    int tie_break=0;
    last=n;
    for (int stage=1;stage<n;stage++) {
        debug(total)
        m02=multiply02[stage];
        m03=multiply03[stage];
        m12=multiply12[stage];
        m13=multiply13[stage];
        if (m02<m03) {
            m0_now = {m02, -2};
        } else {
            m0_now = {m03, -3};
        }
        if (m12<m13) {
            m1_now = {m12, -2};
        } else {
            m1_now = {m13, -3};
        }
        debug(m0_now)
        debug(m1_now)
        if (m0_now<m1_now) {
            p0+=total;
        } else if (m0_now>m1_now) {
            p1+=total;
        } else {
            if (stage>last) {
                tie_break=0;
            }
            if (tie_break==1) {
                p0+=total;
            } else if (tie_break==2) {
                p1+=total;
            } else {
            int j=stage+1;
            while (j<n and !tie_break) {
                 m02=multiply02[j];
        m03=multiply03[j];
        m12=multiply12[j];
        m13=multiply13[j];
        if (m02<m03) {
            m0_now = {m02, -2};
        } else {
            m0_now = {m03, -3};
        }
        if (m12<m13) {
            m1_now = {m12, -2};
        } else {
            m1_now = {m13, -3};
        }
        debug(m0_now)
        debug(m1_now)
        if (m0_now<m1_now) {
            tie_break=1;
            last=j;
        } else if (m0_now>m1_now) {
            tie_break=2;
            last=j;
            }
            j++;
        }
             if (tie_break==1 or (tie_break==0 and j==n)) {
                p0+=total;
            } else if (tie_break==2) {
                p1+=total;
            }
            }
        }
        debug(p0)
        debug(p1)
        // perform for next;
        total=0;
        if (ops[stage][0].first==0) {
            total+=ops[stage][0].second;
        } else {
            total+=p0*(ops[stage][0].second-1);
        }
        if (ops[stage][1].first==0) {
            total+=ops[stage][1].second;
        } else {
            total+=p1*(ops[stage][1].second-1);
        }
    }
    cout<<p0+p1+total<<endl;
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