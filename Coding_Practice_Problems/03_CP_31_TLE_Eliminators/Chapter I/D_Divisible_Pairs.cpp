#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e9+7
#define EPS (double)1e-9

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

// collect sames for y while retaining index number and check for x after y

// MEMORY LIMIT EXCEDED
// fix it LATER

int32_t main() {
    fast_io();
    int test;
    cin >> test;
    while (test--) {
        int n, x, y; cin >> n >> x >> y;
        int ele;
        // int mody[1000000000][200000] = {0};
        // for (int i=0;i<y;i++) {
        //     for (int j=0;j<n;j++) {
        //         cout << mody[i][j] << endl;
        //     }
        // }
        vector<vector<int>> mody(y, vector<int>(1, 0));
        for (int i=0;i<n;i++) {
            cin >> ele; // remove arr to cut DOWN on MEMORY problem
            mody[ele%y][0]++; // y statement
            mody[ele%y].push_back(ele%x);
            // mody[ele%y][mody[ele%y][0]] = ele%x;
        }
        int count = 0;
        for (int i=0;i<y;i++) {
            for (int j=1;j<=mody[i][0];j++) {
                for (int k=j+1;k<=mody[i][0];k++) {
                    // cout<<"DEBUG: "<<arr[mody[i][j]]<<" "<<arr[mody[i][k]]<<endl;
                    if ((mody[i][j]+mody[i][k])%x==0) { // x statement
                        count++;
                    }
                }
            }
        }
        cout << count << endl;
    }
    return 0;
}