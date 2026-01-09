#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)(1e9+7)
#define EPS (double)1e-9

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

// just A conjecture

int mex(vector<int> arr, int k, int n) {
    vector<int> nums(n+1, 0);
    for (int i=0;i<k;i++) {
        nums[arr[i]]++;
    }
    int j=0;
    for (;j<k;j++) {
        if (nums[j]==0) {
            break;
        }
    }
    return j;
}

int maxi(vector<int> arr, int k) {
    int best=-INF;
    for (int i=0;i<k;i++) {
        best = max(best, arr[i]);
    }
    return best;
}


void solve() {
    int n, k; cin >> n >> k;
    vector<int> arr(n, 0); 
    int num;
    for (int i=0;i<n;i++) {
        cin >> arr[i];
    }
    int curr_mex = mex(arr, k, n), curr_max = maxi(arr, k);
    for (int i=0;i<n-k+1;i++) {
        if (curr_max < curr_mex) {
            if (arr[i+k]);
        }
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