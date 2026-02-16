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
    int n, m; cin >> n >> m;
    string b; cin>>b;
    int right=0, left=0;
    for (int i=0;i<n;i++) {
        if (b[i]=='(') {
            right++;
        } else {
            left++;
        }
    }
    int right_right=right, right_left;
    int left_right, left_left=left;
    // int x+y+z
    int total = (n-m-right-left)/2;
}

int32_t main() {
    fast_io();
    solve();
    return 0;
}