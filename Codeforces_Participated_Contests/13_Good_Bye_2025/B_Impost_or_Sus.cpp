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
    string str;
    cin >> str;
    int count=0;
    int start=1;
    int ans = 0;
    for (int i=0;i<str.size();i++) {
        if (str[i]=='u') {
            count++;
        } else {
            if (start) {
                start=0;
                ans += (count+1)/2;
            } else {
                ans += count/2;
            }
            count=0;
        }
    }
    if (count!=0) {
        if (start) {
            ans += (count/2)+1;
        } else {
            ans += (count+1)/2;
        }
    }
    cout<<ans<<endl;
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