#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)(1e9+7)
#define EPS (double)1e-9

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve(int n, int k, char str[]) {
    vector<int> girls = {0};
    for (int i=0;i<n;i++) {
        if (str[i]=='B') {
            girls.push_back(0);
        } else {
            girls.back()++;
        }
    }
    for (int i=0;i<k;i++) {
        for (int j=0;j<girls.size()-1;j++) {
            if (girls[j+1]>0) {
                girls[j+1]--;
                girls[j]++;
            }
        }
    }
    for (int i=0;i<girls.size();i++) {
        for (int j=0;j<girls[i];j++) {
            cout<<'G';
        }
        if (i!=girls.size()-1) {
            cout<<'B';
        }
    }
    cout<<endl;
}

int32_t main() {
    fast_io();
    int n, k; cin >> n >> k;
    char str[200001];
    cin >> str;
    solve(n, k, str);
    return 0;
}