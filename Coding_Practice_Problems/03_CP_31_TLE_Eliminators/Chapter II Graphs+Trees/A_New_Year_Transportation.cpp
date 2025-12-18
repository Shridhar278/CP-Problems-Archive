#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)(1e9+7)
#define EPS (double)1e-9

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve(int n, int k, vector<int> arr) {
    int i=0;
    while (i+1<=k) {
        if (i+1==k) {
            cout<<"YES"<<endl;
            return;
        }
        i+=arr[i];
    }
    cout<<"NO"<<endl;
}

int32_t main() {
    fast_io();
    int n, k; cin >> n >> k;
    vector<int> arr(n);
    for (int i=0;i<n;i++) {
        cin >> arr[i];
    }
    solve(n, k, arr);
    return 0;
}