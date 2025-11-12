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
        int n; cin >> n; char c;
        vector<int> arr(n);
        vector<int> bin;
        for (int i=0;i<n;i++) {
            cin >> arr[i];
        }
        int count = 0;
        for (int i=0;i<n;i++) {
            cin >> c;
            if (c=='1') {
                count++;
            }
            bin.push_back((int)c);
        }
        vector<int> maxis; maxis.push_back(-INF);
        vector<int> minis; minis.push_back(+INF);
        int curr=0, i=0;
        while (i<n) {
            if (bin[i]==1) {
                if (maxis.back() && minis.back())
                curr++;
            }
            if (arr[i] > maxis.back()) {
                maxis.back() = arr[i];
            }
            if (arr[i] < minis.back()) {
                minis.back() = arr[i];
            }
            i++;
        }
    }
    return 0;
}