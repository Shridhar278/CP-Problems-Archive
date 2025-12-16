#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e9+7
#define EPS (double)1e-9

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

// the right IDEA wasn't the FIRST come FIRST serve
// but it did WORK OUT to me getting to the final RIGHT WAY

int32_t main() {
    fast_io();
    int test;
    cin >> test;
    while (test--) {
        int n, x, m; cin >> n >> x >> m;
        vector<vector<int>> ranges(m, vector<int>(2));
        for (int i=0;i<m;i++) {
            cin >> ranges[i][0] >> ranges[i][1];
        }
        int left = x, right = x;
        for (int ops = 0; ops < m; ops++) {
            // works on
            // ....
            //   .....
            // making
            // .......
            if (ranges[ops][0] <= left && ranges[ops][1] >= left) { // crosses and appends
                left = ranges[ops][0];
            }
            if (ranges[ops][1] >= right && ranges[ops][0] <= right) { // crosses and appends
                right = ranges[ops][1];
            }
        }
        int total_range = right - left + 1;
        cout<<total_range<<endl;
    }
    return 0;
}