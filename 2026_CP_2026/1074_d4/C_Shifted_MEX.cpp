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
    for (int i=0;i<n;i++) {
        cin >> arr[i];
    }
    int x=*min_element(arr.begin(), arr.end());
    sort(arr.begin(), arr.end());
    int last=0;
    int offset=x;
    int best=-1;
    for (int i=1;i<n;i++) {
        // cout<<arr[i]<<" "<<offset<<" "<<best<<" "<<last<<endl;
        if (arr[i]-offset > last+1) {
            if (last > best) {
                best = last;
            }
            last=0;
            offset=arr[i];
        } else if (arr[i]-offset>last) {
            last=arr[i]-offset;
        }
    }
    cout<<max(best, last)+1<<endl;
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