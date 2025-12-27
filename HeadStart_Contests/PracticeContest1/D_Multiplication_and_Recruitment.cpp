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
    vector<string> nums(2);
    cin >> nums[0];
    cin >> nums[1];
    int greater=-1;
    char mn, mx;
    for (int i=0;i<nums[0].size();i++) {
        if (greater==-1) {
            if (nums[0][i]<nums[1][i]) {
                greater = 1;
            } else if (nums[0][i]>nums[1][i]) {
                greater = 0;
            }
        } else {
            mn = min(nums[0][i], nums[1][i]);
            mx = max(nums[0][i], nums[1][i]);
            nums[greater][i] = mn;
            nums[1-greater][i] = mx;
        }
    }
    if (nums[0] >= nums[1]) {
        cout<<nums[0]<<endl;
        cout<<nums[1]<<endl;
    } else {
        cout<<nums[1]<<endl;
        cout<<nums[0]<<endl;
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