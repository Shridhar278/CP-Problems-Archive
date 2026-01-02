#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)(1e9+7)
#define EPS (double)1e-9

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

// IT'S PERFECT
// to be looked for WHERE WENT WRONG

void solve() {
    int n; cin >> n;
    vector<vector<int>>blocks;
    int num;
    for (int i=0;i<n;i++) {
        cin >> num;
        if (i!=0) {
            if (blocks.back().back()<num) {
                blocks.push_back({num, num});
            } else {
                blocks.back().back() = num;
            }
        } else {
            blocks.push_back({num, num});
        }
    }
    if (n<=2) {
        cout<<0<<endl;
        return;
    }
    vector<vector<int>>branches;
    int penalty=-1; // 2 different arrays = 1 removed;
    for (int i=blocks.size()-1;i>=0;i--) {
        // cout<<"$"<<blocks[i][0]<<" "<<blocks[i][1]<<endl;
        if (i==blocks.size()-1) {
            branches.push_back(blocks.back());
        } else {
            vector<int> key = {blocks[i][1], blocks[i][1]};
            auto it = lower_bound(branches.begin(), branches.end(), key, greater<>());
            if (it==branches.end()) {
                penalty++;
                // cout<<blocks[i][0]<<" "<<blocks[i][1]<<endl;
                auto it2 = lower_bound(branches.begin(), branches.end(), blocks[i], greater<>());
                branches.insert(it2, blocks[i]);
            } else {
                // cout<<(*it)[0]<<" "<<(*it)[1]<<endl;
                branches.erase(it);
                auto it3 = lower_bound(branches.begin(), branches.end(), blocks[i], greater<>());
                branches.insert(it3, blocks[i]);
            }
        }
    }
    if (penalty<0) {
        penalty=0;
    }
    cout<<penalty<<endl;
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