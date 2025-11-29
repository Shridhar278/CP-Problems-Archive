#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e9+7
#define EPS (double)1e-9

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

// Kadane's O(n) Algorithm : Will Dive DEEPER later...
int maxSubArraySum(vector<int>& a) {
    int curr = a[0];
    int best = a[0];

    for(int i = 1; i < a.size(); i++) {
        curr = max(a[i], curr + a[i]);
        best = max(best, curr);
    }
    return best;
}
// just using as an STL-like function for now
// this + sorting algos STUDY LATER 


// ASSUMPTION: best moves independent of no. of moves left
// just the best state TO best state TRAVEL
// NO COMPLEX decision-making

int32_t main() {
    fast_io();
    int test;
    cin >> test;
    while (test--) {
        int n, k; cin >> n >> k;
        vector<int> arr(n);
        for (int i=0;i<n;i++) {
            cin >> arr[i];
        }
    }
    return 0;
}