#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MOD (int)(1e9+7)
#define EPS (double)1e-9

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

// clean approach
// look into it

int nCr(int n, int r) {
    double ans=1;
    r=min(r,n-r);
    for (double i=1;i<=r;i++) {
        ans*=(n+1-i)/i;
    }
    return round(ans);
}

void solve() {
    int n, k; cin >> n >> k;
    int maxbit, cntbit;
    int total=0;
    for (maxbit=0;maxbit<ilogb(n);maxbit++) {
        for (cntbit=1;cntbit<=maxbit+1;cntbit++) {
            if (maxbit+cntbit>k) {
                // cout<<"$"<<total<<"$"<<maxbit<<"$"<<cntbit<<endl;
                total+=nCr(maxbit, cntbit-1);
            } 
        }
    }
    if (ilogb(n)+1>k) {
        total++;
    }
    cout<<total<<endl;
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