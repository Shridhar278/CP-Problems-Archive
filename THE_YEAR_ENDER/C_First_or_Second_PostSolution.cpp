#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)(1e9+7)
#define EPS (double)1e-9

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

// A More Third Person Perspective of Solving
// Reverse Engineering
// select the Last Stranding and the story for all till n;
// GOOD
// NICEE optimal code performance

void solve() {
    int n; cin >> n;
    vector<int> prefix_mod(n, 0);
    vector<int> suffix_neg(n, 0);
    vector<int> nums(n);
    for (int i=0;i<n;i++) {
        cin >> nums[i];
        if (i==0) {
            //chill
        } else if (i==1) {
            prefix_mod[1]=nums[0];
        } else {
            prefix_mod[i]=prefix_mod[i-1]+abs(nums[i-1]);
        }
    }
    // for suffix_neg
    for (int i=n-2;i>=0;i--) {
        suffix_neg[i]=suffix_neg[i+1]-nums[i+1];
    }
    int best=-LONG_MIN, curr;
    for (int i=0;i<n;i++) {
        curr = prefix_mod[i]+suffix_neg[i];
        best = max(curr, best);
    }
    cout<<best<<endl;
    // NICEE, prefix/suffix SUMS : be smart Re-Contstruct BACK-TRACKING
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