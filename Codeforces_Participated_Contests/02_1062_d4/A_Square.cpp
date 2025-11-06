#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e9+7

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

int32_t main() {
    fast_io();
    int test;
    cin >> test;
    while (test--) {
        int arr[4];
        bool same = true;
        for (int i=0;i<4;i++) {
            cin >> arr[i];
            if (arr[i]!=arr[i-1] && i>0) {
                same = false;
            }
        }
        if (same) {
            cout<<"YES"<<endl;
        } else {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}