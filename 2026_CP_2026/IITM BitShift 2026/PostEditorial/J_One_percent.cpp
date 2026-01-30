#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MOD (int)(1e9+7)
#define EPS (double)1e-9

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

// ACCEPTED
// eagle sense

void solve() {
    int n; cin >> n;
    vector<int> nums(n);
    vector<int> vals(n);
    vector<vector<int>> coins(n, vector<int>(2));
    for (int i=0;i<n;i++) {
        cin >> coins[i][1];
    }
    for (int i=0;i<n;i++) {
        cin >> coins[i][0];
    }
    double totalVal=0;
    double totalCoins=0;
    for (int i=0;i<n;i++) {
        totalVal+=coins[i][0]*coins[i][1];
        totalCoins+=coins[i][1];
    }
    sort(coins.begin(), coins.end(), greater<>());
    double curr=0;
    int currCoins=0;
    double currValue=0;
    for (int i=0;i<n;i++) {
        // cout<<currCoins<<" "<<currValue<<" "<<coins[i][0]<<" "
        //     <<coins[i][1]<<" "<<totalCoins<<" "<<totalVal<<endl;
        // cout<<((currCoins+coins[i][1])/totalCoins)*totalVal+currValue+coins[i][0]*coins[i][1]<<endl;
        if (((currCoins+coins[i][1])/totalCoins)*totalVal+currValue+coins[i][0]*coins[i][1] < totalVal) {
            currCoins+=coins[i][1];
            currValue+=coins[i][0]*coins[i][1];
            continue;
        }
        // kind of binary search
        int low=0;
        int high=coins[i][1];
        int mid;
        while (low + 1 < high) {
            mid = low + (high-low)/2;
            // cout<<high<<" "<<low<<" "<<mid<<endl;
            // cout<<((currCoins+mid)/totalCoins)*totalVal+currValue+coins[i][0]*mid<<endl;
            if (((currCoins+mid)/totalCoins)*totalVal+currValue+coins[i][0]*mid < totalVal) {
                low = mid;
            } else if (((currCoins+mid)/totalCoins)*totalVal+currValue+coins[i][0]*mid > totalVal) {
                high = mid;
            } else {
                cout<<currCoins+mid<<endl;
                return;
            }
        }
        cout<<currCoins+low+1<<endl;
        return;
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