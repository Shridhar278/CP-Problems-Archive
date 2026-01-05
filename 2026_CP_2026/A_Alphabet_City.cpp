#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)(1e9+7)
#define EPS (double)1e-9

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    cout<<1<<endl;
    int n, m; cin >> n >> m;
    vector<string> streets;
    string s;
    vector<vector<int>> assets(n, vector<int>(26, 0));
    vector<int> total_assets(26, 0);
    for (int i=0;i<n;i++) {
        cin >> s;
        streets.push_back(s);
        for (int j=0;j<s.size();j++) {
            assets[i][s[j]-'A']++;
            total_assets[s[j]-'A']++;
        }
    }
    for (int l=0;l<n;l++) {
        int best_so_far=-1;
        for (int alpha=0;alpha<26;alpha++) {
            best_so_far = min((m*total_assets[alpha]-assets[l][alpha])/assets[l][alpha], best_so_far);
        }
        if (best_so_far>=0) {
            cout<<best_so_far<<" ";
        } else {
            cout<<-1<<" ";
        }
    }
    cout<<endl;
}

int32_t main() {
    fast_io();
    solve();
    return 0;
}