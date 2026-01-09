#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MOD (int)(1e9+7)
#define EPS (double)1e-9

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

// AFTER CLASS
// HAppy New Year!

void solve() {
    string database; cin >> database;
    int m; cin >> m;
    string l; cin >> l;
    string r; cin >> r;
    int best;
    int last=0;
    for (int j=0;j<m;j++) {
        // cout<<best<<" "<<last<<endl;
        best=-1;
        for (int i=min(l[j], r[j]);i<=max(l[j], r[j]);i++) {
            auto it = find(database.begin()+last, database.end(), i);
            best = max((int)(it-database.begin()), best);
        }
        if (best==(int)database.size()) {
            cout<<"YES"<<endl;
            return;
        }
        last = best+1;
    }
    cout<<"NO"<<endl;
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