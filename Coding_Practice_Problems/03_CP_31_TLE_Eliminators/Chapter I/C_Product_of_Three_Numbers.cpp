#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)(1e9+7)
#define EPS (double)1e-9

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    int n; cin >> n;
    int none = 1;
    int i, j, new_n;
    for (i=2;i<sqrt(n);i++) { // equal to srqt remove
        if (n%i==0) {
            new_n=n/i;
            for (j=i+1;j<sqrt(new_n);j++) {
                if (new_n%j==0) {
                    none=0;
                    break;
                }
            }
            break;
        }
    }
    if (none) {
        cout<<"NO"<<endl;
    } else {
        cout<<"YES"<<endl;
        cout<<i<<" "<<j<<" "<<new_n/j<<endl;
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