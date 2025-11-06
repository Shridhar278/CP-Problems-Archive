#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e9+7

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

// MUCH SIMPLER and SAME time-complexity alogorithm O(N^(1/2))
// MUCH easier IT WORKS

int32_t main() {
    fast_io();
    int test;
    cin >> test;
    while (test--) {
        int n, count=0, i;
        cin >> n;
        for (i=1;i*i<n;i++){
            if (n%i==0) {
                count++;
            }
        } count*=2;
        if (i*i==n) {
            count++;
        }
        cout<<count<<endl;
    }
    return 0;
}