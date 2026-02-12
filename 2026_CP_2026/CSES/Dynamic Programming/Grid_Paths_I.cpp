#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MOD (int)(1e9+7)
#define EPS (double)1e-9

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    int n; cin >> n;
    char c;
    vector<vector<int>> grid(n, vector<int>(n, 0));
    grid[0][0] = 1;
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            cin >> c;
            if (c=='*') {
                grid[i][j]=0;
            } else if (i!=0 | j!=0){
                grid[i][j] = (grid[max(i-1, (int)0)][j]+grid[i][max(j-1, (int)0)])%MOD;
            }
        }
    }
    cout<<grid[n-1][n-1]<<endl;
}

int32_t main() {
    fast_io();
    solve();
    return 0;
}