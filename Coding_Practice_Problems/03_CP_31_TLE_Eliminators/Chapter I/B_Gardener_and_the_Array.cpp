#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)(1e9+7)
#define EPS (double)1e-9

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

// looks ez;
// SKILL GAINED: maps
// got it TO COUNT frequency of stuff => MAPS
// sorted stored ; access and insert O(log n)
// 

void solve(int n) {
    // WASTE of time assering all to zero and adding INSTEAD USE maps
    // apply 0 to 200000 elements THIS TAKES TIME n=10000 TIMES
    // int universal[100000];
    // # this is the difference map<int, int> will MAKE
    // counting FREQUENCY of certain elements map datatpe HELPS
    map<int, int> universal;
    int num, x;
    vector<vector<int>> sqs;
    for (int i=0;i<n;i++) {
        cin >> num;
        sqs.push_back({num});
        for (int j=1;j<=num;j++) {
            cin >> x;
            sqs[i].push_back(x);
            universal[sqs[i][j]-1]++; // initializes if NOT to ZERO // so helpful
        }
    }
    // uniqueNESS check
    for (int i=0;i<n;i++) {
        int yes=1;
        for (int j=1;j<=sqs[i][0];j++) {
            if (universal[sqs[i][j]-1]==1) {
                yes=0;
                break;
            }
        }
        if (yes) {
            cout<<"Yes"<<endl;
            return;
        }
    }
    cout<<"No"<<endl;
}

int32_t main() {
    fast_io();
    int test;
    cin >> test;
    while (test--) {
        int n; cin >> n;
        solve(n);
    }
    return 0;
}