#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)(1e9+7)
#define EPS (double)1e-9

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

// BIZARRE error ON one CHECK IT.. plz

void solve() {
    int n; cin >> n;
    vector<int> arr(n);
    for (int i=0;i<n;i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    int st=0, ed=0, best=1;
    for (;ed<n;) {
        if (arr[ed]-arr[st]>5) {
            st++;
            continue;
        }
        best = max(best, ed-st+1);
        ed++;
    }
    cout<<best<<endl;
}

int32_t main() {
    fast_io();
    solve();
    return 0;
}