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
    for (int i=0;i<str.size();i++) {
        if (str[i]=='Y') {
            count++;
        }
    }
    if (count<2) {
        cout<<"YES"<<endl;
    } else {
        cout<<"NO"<<endl;
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