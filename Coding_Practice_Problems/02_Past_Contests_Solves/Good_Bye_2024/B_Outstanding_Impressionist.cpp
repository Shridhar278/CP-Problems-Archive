#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define int long long
#define INF (int)(1e9+7)
#define EPS (double)1e-9

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

//F it watching TUTORIAL
void solve() {
    int n; cin >> n;
    map<int, vector<int>> nums;
    vector<int> restricted(2*n+1, 0);
    int count=0;
    int li, ri;
    for (int i=0;i<n;i++) {
        cin >> li >> ri;
        nums[i].push_back(li);
        nums[i].push_back(ri);
        if (li==ri) {
            restricted[li-1]++;
            count++;
        }
    }
    for (int i=0;i<n;i++) {
        int k = (nums[i][0] == nums[i][1]) ? 2 : 1;
        auto it = lower_bound(&restricted[nums[i][0]], &restricted[nums[i][1]]+1, k);
        if (it != &restricted[2*n]) {
            cout<<0;
        } else {
            cout<<1;
        }
    }
    cout<<endl;
}

void tutorial() {
    // wth read AFTER waking UP
    //eventually
}
int32_t main() {
    fast_io();
    int test;
    cin >> test;
    while (test--) {
        // solve();
        tutorial();
    }
    return 0;
}