#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MOD (int)(1e9+7)
#define EPS (double)1e-9

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

// decimal point trickery
// ACCEPTED

void solve() {
    int n, m; cin >> n >> m;
    vector<int> ops(m);
    string s; cin >> s;
    for (int i=0;i<m;i++) {
        cin >> ops[i];
    }
    int og = n;
    int worst=0;
    int final=0;
    for (int i=0;i<m;i++) {
        final+=ops[i];
        worst = min(final, worst);
    }
    if (og+worst<=0) {
        cout<<'0'<<endl;
        return;
    }
    for (int i=0;i<og+final;i++) {
        if (i >= og+worst) {
            cout<<'0';
        } else {
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