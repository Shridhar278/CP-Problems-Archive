#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MOD (int)(1e9+7)
#define EPS (double)1e-9

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

int isCentre(vector<vector<int>> pos) {
    if ((pos[0][0]-pos[1][0])*(pos[0][0]-pos[2][0])+(pos[0][1]-pos[1][1])*(pos[0][1]-pos[2][1])==0) {
        return 0;
    }
    if ((pos[1][0]-pos[0][0])*(pos[1][0]-pos[2][0])+(pos[1][1]-pos[0][1])*(pos[1][1]-pos[2][1])==0) {
        return 1;
    }
    return 2;
}

void solve() {
    int n; cin >> n;
    vector<vector<int>> pos(3, vector<int>(2));
    for (int i=0;i<3;i++) {
        cin >> pos[i][0];
        cin >> pos[i][1];
    }
    int target[2];
    cin >> target[0] >> target[1];
    vector<int> centre(2);
    centre = pos[isCentre(pos)];
    if ((centre[0]==1 or centre[0]==n) and (centre[1]==1 or centre[1]==n)) {
        if (centre[0]-target[0]==0 or centre[1]-target[1]==0) {
            cout<<"YES"<<endl;
            return;
        }
        cout<<"NO"<<endl; 
        
    } else {
        if (abs(centre[0]-target[0])%2==1 and abs(centre[1]-target[1])%2==1) {
            cout<<"NO"<<endl;
            return;
        }
        cout<<"YES"<<endl;
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