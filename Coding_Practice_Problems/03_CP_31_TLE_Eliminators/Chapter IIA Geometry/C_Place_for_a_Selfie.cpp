#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)(1e9+7)
#define EPS (double)1e-9

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

// BOOM ez

void solve() {
    int n, m; cin >> n >> m;
    vector<int> lines(n);
    vector<vector<int>> parabolas(m, vector<int>(3));
    for (int i=0;i<n;i++) {
        cin >> lines[i];
    }
    sort(lines.begin(), lines.end());
    for (int i=0;i<m;i++) {
        cin >> parabolas[i][0] >> parabolas[i][1] >> parabolas[i][2];
    }
    for (auto parabola : parabolas) {
        if (parabola[0]*parabola[2] <= 0) {
            cout<<"NO"<<endl;
            continue;
        }
        double root4ac = sqrt(4*parabola[0]*parabola[2]);
        if (floor(root4ac)!=root4ac) {
            root4ac=floor(root4ac);
        } else {
            root4ac--;
        }
        auto it = lower_bound(lines.begin(), lines.end(), parabola[1]-root4ac);
        // not END important cuz. then *it becomes ADORABLE
        if (it != lines.end() && *it <= parabola[1]+root4ac) {
            cout<<"YES"<<endl;
            cout<<*it<<endl;
        } else {
            cout<<"NO"<<endl;
        }
    }
    cout<<endl;
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