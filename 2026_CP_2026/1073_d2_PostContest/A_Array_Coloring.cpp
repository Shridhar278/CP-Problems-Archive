#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MOD (int)(1e9+7)
#define EPS (double)1e-9

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

// way simpler method make Nx2 with (value, color) 
// and simply sort & check for SAME color

void solve() {
    int n; cin >> n; int num;
    vector<vector<int>> arr(2, vector<int>());   
    for (int i=0;i<n;i++) {
        cin >> num;
        arr[i%2].push_back(num);
    }
    for (auto &a : arr) {
        sort(a.begin(), a.end());
    }
    for (int i=1;i<n;i++) {
        if (n%2==0) {
            if (arr[0][0]<arr[1][0]) {
                if (arr[i%2][i/2] < arr[1-i%2][(i-1)/2]) {
                    cout<<"NO"<<endl;
                    return;
                }
            } else {
                if (arr[1-i%2][i/2] < arr[i%2][(i-1)/2]) {
                    cout<<"NO"<<endl;
                    return;
                }
            }
        } else {
            if (arr[i%2][i/2] < arr[1-i%2][(i-1)/2]) {
                cout<<"NO"<<endl;
                return;
            }
        }
    }
    cout<<"YES"<<endl;
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