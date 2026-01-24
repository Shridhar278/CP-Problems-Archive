#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MOD (int)(1e9+7)
#define EPS (double)1e-9

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

// no idea WHAT I AM DOING

void solve() {
    int n; cin >> n;
    vector<int> ans(n);
    map<int, int> nums;
    ans[n-2]=1;
    nums[1]=1;
    ans[n-1]=(n-1)^1;
    nums[ans[n-1]]=1;
    for (int i=0;i<n-2;i++) {
        ans[i]=(i+1)^1;
        nums[ans[i]]++;
    }
    for (int i=1;i<=n;i++) {
        if (nums[i]!=1) {
            ans[0]=i;
            break;
        }
    }
    for (int i=0;i<n;i++) {
        cout<<ans[i]<<" ";
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