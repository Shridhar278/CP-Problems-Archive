#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)(1e9+7)
#define EPS (double)1e-9

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

// fix IT
// after Hello 2026
// minor BUG

void solve() {
    int n, k; cin >> n >> k;
    vector<int> arr(n);
    for (int i=0;i<n;i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    if (k >= 3) {
        cout<<0<<endl;
    } else if (k==2) {
        vector<int> diff;
        int count=0;
        for (int i=0;i<n-1;i++) {
            diff.push_back(arr[i+1]-arr[i]);
        }
        sort(diff.begin(), diff.end());
        int best=LONG_LONG_MAX;
        for (int i=0;i<diff.size();i++) {
            int low=0, high=n-1, mid;
            while(low+1<high) {
                mid = (low+high)/2;
                if (arr[mid] < diff[i]){
                    low = mid;
                } else if (arr[mid] > diff[i]) {
                    high = mid;
                } else {
                    break;
                }
            }
            // cout<<"$"<<best<<" "<<diff[0]<<" "<<diff[i]<<" "<<arr[mid]<<" "<<arr[mid+1]<<endl;
            best = min({best, abs(arr[mid]-diff[i]), abs(arr[mid+1]-diff[i]), diff[0], arr[0]});
            // 30 60 100 171
        }
        cout<<best<<endl;
    } else {
        int min_diff=LONG_LONG_MAX;
        for (int i=1;i<n;i++) {
            min_diff = min(min_diff, arr[i]-arr[i-1]);
        }
        cout<<min(arr[0], min_diff)<<endl;
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