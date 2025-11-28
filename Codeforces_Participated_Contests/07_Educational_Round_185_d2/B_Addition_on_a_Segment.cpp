#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e9+7
#define EPS (double)1e-9

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

// EXPERIMENTAL find NOT YET proven...

// answer is n-no. of zeroes-(n-max_num)
// = max_num-no. of zeroes + (last_non_zero-1) // last minute adjustment

// BRAIN-FADE

int32_t main() {
    fast_io();
    int test;
    cin >> test;
    while (test--) {
        int n; cin >> n;
        vector<int> arr(n);
        for (int i=0;i<n;i++) {
            cin>>arr[i];
        }
        sort(arr.begin(), arr.end(), greater<int>());
        int x=0, zero=0;
        for (int i=0;i<n-1;i++) {
            if (arr[i]==0) {
                zero++;
            }
            x += arr[i]-arr[i+1];
        }
        if (arr[n-1]==0) {
            zero++;
        }
        cout<<n-zero-(n-x)<<endl; // x - zero
    }
    return 0;
}