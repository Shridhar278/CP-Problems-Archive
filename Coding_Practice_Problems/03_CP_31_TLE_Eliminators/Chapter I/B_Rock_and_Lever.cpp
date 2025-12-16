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
        int ele;
        int bit_size[32] = {0};
        for (int i=0;i<n;i++) {
            cin >> ele;
            bit_size[ilogb(ele)]++; // same MSB is answer ELSE not EZ
        }
        int sols=0;
        for (int i=0;i<32;i++) {
            sols+=bit_size[i]*(bit_size[i]-1)/2;
        }
        cout<<sols<<endl;
    }
    return 0;
}