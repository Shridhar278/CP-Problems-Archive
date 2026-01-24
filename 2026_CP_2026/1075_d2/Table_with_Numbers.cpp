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
    int n, h, l; cin >> n >> h >> l;
    vector<int> arr(n);
    for (int i=0;i<n;i++) {
        cin >> arr[i];
    }
    int total=0;
    vector<int> alive(n, 1);
    sort(arr.begin(), arr.end());
    for (int i=0;i<n-1;i++) {
        for (int j=n-1;j>=i+1;j--) {
            if ((max(arr[i], arr[j]) <= max(h, l)) and (min(arr[i], arr[j]) <= min(l, h))) {
                if (alive[i] and alive[j]) {
                    total++;
                    alive[i]=0;
                    alive[j]=0;
                }
            }
        }
    }
    cout<<total<<endl;
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