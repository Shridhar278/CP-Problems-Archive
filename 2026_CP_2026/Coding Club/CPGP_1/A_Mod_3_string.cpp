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
    int n; cin >> n;
    string s; cin >> s;
    int even=0, odd=0;
    for (int i=n-1;i>=0;i--) {
        if (s[i]=='1') {
        if (i%2==0) {
            even++;
        } else {
            odd++;
        }
        }
    }
    if ((abs(even-odd))%3==0) {
        cout<<1<<endl;
    } else {
        cout<<0<<endl;
    }
}

int32_t main() {
    fast_io();
    solve();
    return 0;
}