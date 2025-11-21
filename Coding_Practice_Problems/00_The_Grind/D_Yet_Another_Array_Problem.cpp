#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e9
#define EPS (double)1e-9

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

// 1062 d4

// standard time complexity ka dokha moments
// just about n only :: illusion of n^2
// cuz. lcm (1,2,3,..,43) itself > 1e18

int32_t main() {
    fast_io();
    int test;
    cin >> test;
    while (test--) {
        int n; cin >> n;
        vector<int> arr; int num;
        for (int i=0;i<n;i++) {
            cin >> num; arr.push_back(num);
        }
        sort(arr.begin(), arr.end());
        int j = 0;
        for (int i=2;i<=arr[j]+1;i++) {
            if (__gcd(i, arr[j])!=1) {
                int tru=0;
                while(j < n) {
                    if (__gcd(i, arr[j])==1) {
                        tru=1;
                        break;
                    }
                    j++;
                }
                j=0;
                if (!tru) {
                    continue;
                }
            }
            cout<<i<<endl;
            break;
        }
    }
    return 0;
}