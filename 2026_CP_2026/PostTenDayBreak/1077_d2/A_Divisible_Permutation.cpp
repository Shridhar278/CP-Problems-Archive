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
    int x=n;
    vector<int> arr={n};
    for (int i=n-1;i>0;i--) {
        if ((n-i)%2==1) {
            x-=i;
        } else {
            x+=i;
        }
        arr.push_back(x);
    }
    for (int i=n-1;i>=0;i--) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
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