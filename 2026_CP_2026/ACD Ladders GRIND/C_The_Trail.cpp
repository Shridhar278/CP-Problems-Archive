#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MOD (int)(1e9+7)
#define EPS (double)1e-9

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

// hints=1
// total sum = 0 always WORKS
// n*x = m*x so, at last WORKS
// ALWAYS WORKS

// ACCEPTED ben stokes

void solve() {
    int n, m; cin >> n >> m;
    string steps; cin >> steps;
    vector<vector<int>> grid(n, vector<int>(m));
    int X;
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            cin >> grid[i][j];
        }
    }
    vector<int> row(n, 0);
    vector<int> col(m, 0);
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            row[i]+=grid[i][j];
        }
    }
    for (int i=0;i<m;i++) {
        for (int j=0;j<n;j++) {
            col[i]+=grid[j][i];
        }
    }
    int p1=0, p2=0;
    X=0;
    for (int i=0;i<n+m-1;i++) {
        // cout<<row[p1]<<" "<<col[p2]<<endl;
        if (i<n+m-2) {
            // cout<<steps[i]<<endl;
            if (steps[i]=='D') {
                grid[p1][p2]=X-row[p1];
                row[p1]=X;
                col[p2]+=grid[p1][p2];
            } else {
                grid[p1][p2]=X-col[p2];
                col[p2]=X;
                row[p1]+=grid[p1][p2];
            }
            if (steps[i]=='D') {
                p1++;
            } else {
                p2++;
            }
        } else {
            grid[p1][p2]=X-row[p1];
        }
    }
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            cout << grid[i][j] << " ";
        }
        cout<<endl;
    }
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