// Online C++ compiler to run C++ program online
#include <bits/stdc++.h> 
using namespace std;

// ACCEPTED ben stokes

int main() {
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> grid(m, vector<int>(n, 0));
        for (int i=0;i<n;i++) {
            for (int j=0;j<m;j++) {
                cin >> grid[j][i];
            }
        }
        for (int i=n-1;i>=0;i--) {
            if (i<n-1) {
                for (int j=0;j<m;j++) {
                    grid[j][i]+=grid[j][i+1];
                }
            }
        }
        int total=0;
        for (int i=0;i<m;i++) {
            total+=grid[i][0];
        }
        cout<<1LL*(total/2)*((total+1)/2)<<endl;
        int curr=total/2;
        int down=0;
        for (int col=0;col<m;col++) {
            // cout<<curr<<endl;
            if (curr==0) {
                cout<<"R";
                continue;
            }
            auto it = lower_bound(grid[col].begin(), grid[col].end(), curr, greater<>());
            // cout<<(int)(it-grid[col].begin())<<endl;
            if (it==(grid[col]).begin() && *it!=curr) {
                curr-=(grid[col])[0];
                cout<<"R";
            } else {
                down=1;
                curr=0;
                int x=it-(grid[col]).begin();
                for (int j=0;j<n;j++) {
                    if (x==j) {
                        cout<<"R";
                    }
                    cout<<"D";
                }
            }
        }
        if (down==0) {
            for (int i=0;i<n;i++) {
                cout<<"D";
            }
        }
        cout<<endl;
    }
    return 0;
}