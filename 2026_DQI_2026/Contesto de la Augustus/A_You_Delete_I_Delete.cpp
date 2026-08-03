#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MOD (int)(1e9+7)
#define EPS (double)1e-9

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    string s; cin >> s;
    int n = (int)s.size();
    int z=1, o=1;
    int x, y;
    for (int i=0;i<n;i++) {
        if (s[i]=='0' && z) {
            z=0;
            x=i;
        }
        if (s[i]=='1' && o) {
            o=0;
            y=i;
        }
    }
    for(int i=0;i<n;i++) {
        if (i!=x && i!=y) {
            cout<<s[i];
        }
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