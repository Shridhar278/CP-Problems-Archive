#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)(1e9+7)
#define EPS (double)1e-9

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

// LOOKout Tutorial
// my solution IS EXTREMELY OPTIMIZED

void solve() {
    int a, b; cin >> a >> b;
    int mx = max(a, b), mn = min(a, b);
    vector<int> nums(2, 0);
    int i;
    for (i=0;;i++) {
        nums[i%2]+=(1<<i);
        if (max(nums[0], nums[1])>mx || min(nums[0], nums[1])>mn) {
            break;
        }
    }
    cout<<i<<endl;
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

