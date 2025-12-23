#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)(1e9+7)
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
    int least1=INF, least2=INF;
    least1 = min(arr[0], arr[1]);
    least2 = max(arr[0], arr[1]);
    for (int i=2;i<n;i++) {
        if (arr[i] < least1) {
            least2 = least1;
            least1 = arr[i];
        } else if (arr[i] < least2) {
            least2 = arr[i];
        }
    }
    if (least2 > 2*least1) {
        cout<<least2-least1<<endl;
    } else {
        cout<<least1<<endl;
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