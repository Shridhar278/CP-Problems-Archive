#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e9+7
#define EPS (double)1e-9

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

// int recursive(int arr[2][200000], int curr[2], int states[2][2], int limits[2]) {
//     if (curr[0]==0) {

//     } else {

//     }
// }

int32_t main() {
    fast_io();
    int test;
    cin >> test;
    while (test--) {
        // use recursion;
        int n; cin >> n;
        int arr[2][n];
        for (int i=0;i<2;i++) {
            for (int j=0;j<n;j++) {
                cin >> arr[i][j];
            }
        }
        // int states[2][2] = {{0, 0}, {0, 0}};
        // int ttl=0;
        // int other[2][2] = {{1,0}, {1,0}};
        // int a[2] = {0, -1};
        // int b[2] = {-1, 0};
        // int c1[2] = {0, 0};
        // int c2[2] = {1, 0};
        // ttl += recursive(arr, c1, states, a);
        // ttl += recursive(arr, c2, other, b);
        // cout<<ttl;
        int i=-1;
        int j=0;
        int maxi=-INF, mini=INF;
        while (i!=n) {
            if (i==-1) {
                
            }
            j++;
            if (j==n) {
                i++;
                j=i;
            }
        }
    }
    return 0;
}