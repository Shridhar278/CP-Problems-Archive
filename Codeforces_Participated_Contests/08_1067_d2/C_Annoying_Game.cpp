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
        vector<int> change(n);
        for (int i=0;i<n;i++) {
            cin >> arr[i];
        }
        for (int i=0;i<n;i++) {
            cin >> change[i];
        }
        if (k%2==0) {
            cout<<maxSubArraySum(arr)<<endl;
            continue;
        }
        // think clearly
        // vector<int> breaks;
        // for (int i=1;i<n;i++) {
        //     if (arr[i]<0 && arr[i-1]>=0) {
        //         breaks.push_back(i-1);
        //     }
        // }
        // vector<int> blocks;
        // int sm=0, count=0;
        // for (int i=0;i<n;i++) {
        //     sm+=arr[i];
        //     if (i==breaks[count]) {
        //         blocks.push_back(sm);
        //         sm=0;
        //         count++;
        //     }
        // }
        // blocks.push_back(sm);
        // vector <int> b = arr;
        // int mx=maxSubArraySum(arr);
        // // smartify THIS
        // for (int i=0;i<n;i++) {
        //     b[i] += change[i];
        //     if (maxSubArraySum(b)>mx) {
        //         mx = maxSubArraySum(b);
        //     }
        //     b[i]-=change[i];
        // }
        // cout<<mx<<endl;
        int curr = arr[0];
        int best = arr[0];
        for(int i = 1; i < arr.size(); i++) {
            curr = max(arr[i], curr + arr[i]);
            best = max(best, curr);
        }
        // i want a value for each index to surpass means added.
        // TOO COMPLICATED out of MY LEAGUE for 20 minutes remaining...
    }
    return 0;
}