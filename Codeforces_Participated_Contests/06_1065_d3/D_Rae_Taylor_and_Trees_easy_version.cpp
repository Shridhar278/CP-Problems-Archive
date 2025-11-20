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
        vector<int> a(n);
        // everybody connected -> YES else -> NO
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int mini=INF, old=INF;
        for (int i = 0; i < n; i++) {
            if (i==0) {
                mini=a[i];
                old=a[i];
                continue;
            }
            if (a[i]<mini) {
                mini=a[i];
            }
            if (a[i]>old){
                old=mini;
            }
        }
        if (mini==old) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}