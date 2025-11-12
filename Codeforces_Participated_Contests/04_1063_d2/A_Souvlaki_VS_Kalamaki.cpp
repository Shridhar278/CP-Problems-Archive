#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e9+7
#define EPS (double)1e-9

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

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
        sort(arr.begin(), arr.end());
        int ans=1;
        for (int i=1;i<n;i++) {
            if (i%2==0) {
                if (arr[i]!=arr[i-1]) {
                    ans=0;
                    break;
                }
            }
        }
        if (ans) {
            cout<<"YES"<<endl;
        } else {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}