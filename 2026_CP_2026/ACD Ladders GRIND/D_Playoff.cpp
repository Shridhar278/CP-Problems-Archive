#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MOD (int)(1e9+7)
#define EPS (double)1e-9

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

// an algo always EXISTS
// feel it MOVE ON
// PROOF later ON tackle

void solve() {
    int n; cin >> n;
    string fixing; 
    cin >> fixing;
    int lower=1, upper=1<<n;
    int count0=2, count1=2;
    for (int i=0;i<n;i++) {
        if (fixing[i]=='0') {
            upper = (1<<n) + 1 - count0;
            count0<<=1;
        } else {
            lower = count1;
            count1<<=1;
        }
    }
    for (int i=lower;i<=upper;i++) {
        cout<<i<<" ";
    }
    cout<<endl;
}

int32_t main() {
    fast_io();
    solve();
    return 0;
}