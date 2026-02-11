#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MOD (int)(1e9+7)
#define EPS (double)1e-9

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

// ACCEPTED, ez. INTUTION

void solve() {
    int n; cin >> n;
    string symbols;
    cin >> symbols;
    int q; cin >> q;
    vector<vector<int>> controllers(q, vector<int>(2));
    for (int i=0;i<q;i++) {
        cin >> controllers[i][0] >> controllers[i][1];
    }
    int plus=0, minus=0;
    for (int i=0;i<n;i++) {
        if (symbols[i]=='+') {
            plus++;
        } else {
            minus++;
        }
    }
    int g_barr=min(plus, minus), g_min=abs(plus-minus);
    for (int i=0;i<q;i++) {
        int a=controllers[i][0], b=controllers[i][1];
        int gcd=__gcd(a, b);
        int minimum=(abs(a-b))/gcd, barrier=min(a/gcd, b/gcd);
        int scale = g_barr/barrier;
        if (minimum==0) {
            if (g_min==0) {
                cout<<"YES"<<endl;
            } else {
                cout<<"NO"<<endl;
            }
            continue;
        }
        if (scale*minimum>=g_min and g_min%minimum==0) {
            cout<<"YES"<<endl;
        } else {
            cout<<"NO"<<endl;
        }
    }
}

int32_t main() {
    fast_io();
    solve();
    return 0;
}