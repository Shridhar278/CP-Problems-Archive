#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)(1e9+7)
#define EPS (double)1e-9

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve(int n, vector<int> disk) {
    int last=-INF;
    int curr;
    int count=0;
    for (int i=1;i<n;i++) {
        curr=disk[i]-disk[i-1];
        if (curr >= last) {
            last=curr;
            count++;
        } else {
            last = -INF;
        }
    }
    cout<<count<<endl;
}

int32_t main() {
    fast_io();
    int test;
    cin >> test;
    while (test--) {
        int n; cin >> n;
        vector<int> disk(n);
        for (int i=0;i<n;i++) {
            cin>>disk[i];
        }
        solve(n, disk);
    }
    return 0;
}