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
    int n; cin >> n;
    vector<int> arr(n);
    vector<int> new_arr(n);
    for (int i=0;i<n;i++) {
        cin >> arr[i];
    }
    new_arr=arr;
    sort(new_arr.begin(), new_arr.end());
    int ans=0;
    int max_so_far=-1;
    int count=0;
    for (int i=0;i<n;i++) {
        if (new_arr[i]==arr[i] and max_so_far==-1) {
            ans++;
        } else {
            if (arr[i] > max_so_far) {
                max_so_far=arr[i];
                count=1;
            } else if (arr[i] == max_so_far) {
                count++;
            }
            if (max_so_far==new_arr[i]) {
                count--;
                if (count==0) {
                    ans++;
                    max_so_far=-1;
                }
            }
        }
        // cout<<ans<<max_so_far<<new_arr[i]<<arr[i]<<endl;
    }
    cout<<ans<<endl;
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