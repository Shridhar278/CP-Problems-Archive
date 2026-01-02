#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)(1e9+7)
#define EPS (double)1e-9

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

// check IT ONCE boah !
// edited OUT

void solve() {
    int n; cin >> n;
    string num; cin >> num;
    int yes=0, no=0;
    auto n2025 = num.find("2025");
    auto n2026 = num.find("2026");
    if (n2025==string::npos || n2026!=string::npos) {
        cout<<0<<endl;
    } else {
        cout<<1<<endl;
    }
    // for (int i=0;i<n-3;i++) {
    //     if (num[i]=='2') {
    //         if (num[i+1]=='0') {
    //             if (num[i+2]=='2') {
    //                 if (num[i+3]=='5') {
    //                     no++;
    //                 } else if (num[i+3]=='6') {
    //                     yes++;
    //                 }
    //             }
    //         }
    //     }
    // }
    // if (no==0 || yes==1) {
    //     cout<<0<<endl;
    // } else {
    //     cout<<1<<endl;
    // }
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