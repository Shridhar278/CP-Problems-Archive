#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MOD (int)(1e9+7)
#define EPS (double)1e-9

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

// lot of EDGE cases AUTO-COMPLETE

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    int ttl=0, curr=1;
    for (int i=0;i<n;i++) {
        if (s[i]=='1') {
            ttl+=curr/3;
            curr=0;
            ttl++;
        } else {
            curr++;
        }
    }
    ttl+=(curr+1)/3;
    cout<<ttl<<endl;
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