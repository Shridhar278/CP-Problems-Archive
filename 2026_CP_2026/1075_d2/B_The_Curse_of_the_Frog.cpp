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
    int n, x; cin >> n >> x;
    vector<int> a(n);
    vector<int> b(n);
    vector<int> c(n);
    int score=x;
    for (int i=0;i<n;i++) {
        cin >> a[i] >> b[i] >> c[i];
        score -= a[i]*(b[i]-1);
    }
    int rounds;
    int best=-1;
    for (int i=0;i<n;i++) {
        best = max(best, (-c[i]+a[i]*b[i]));
    }
    if (score<=0) {
        cout<<0<<endl;
    } else if (best<=0) {
        cout<<-1<<endl;
    } else {
        rounds=score/best;
        if (score%best!=0) {
            rounds++;
        }
        cout<<rounds<<endl;
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