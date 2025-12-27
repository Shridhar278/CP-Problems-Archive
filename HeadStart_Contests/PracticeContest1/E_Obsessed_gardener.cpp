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
    int n, k; cin >> n >> k;
    string plot;
    cin >> plot;
    int li, ri;
    for (int i=0;i<k;i++) {
        cin >> li >> ri;
        int one=0, zero=0;
        for (int j=li-1;j<=ri-1;j++) {
            if (plot[j]=='0') {
                zero++;
            } else {
                one++;
            }
        }
        int count=1;
        int x;
        for (x=0;x<one-30;x+=30) {
            count = count*(1<<30);
            count%=1000000007;
        }
        if (one-x>0) {
            count = count*(1<<(one-x));
            count--;
            count%=1000000007;
        }
        count*=(zero+1);
        count%=1000000007;
        cout<<count<<endl;
    }
}

int32_t main() {
    fast_io();
    solve();
    return 0;
}