#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MOD (int)(1e9+7)
#define EPS (double)1e-9

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    string t; cin >> t;
    map<int, int> s_map;
    map<int, int> t_map;
    for (int i=0;i<(int)s.size();i++) {
        s_map[s[i]]++;
    }
    for (int i=0;i<(int)t.size();i++) {
        t_map[t[i]]++;
    }
    for (auto it=s_map.begin();it!=s_map.end();it++) {
        if (it->second!=t_map[it->first]) {
            cout<<"NO"<<endl;
            return;
        }
    }
    if (n>=2*k) {
        cout<<"YES"<<endl;
        return;
    }
    if (n<=k) {
        for (int i=0;i<n;i++) {
            if (s[i]!=t[i]) {
                cout<<"NO"<<endl;
                return;
            }
        }
        cout<<"YES"<<endl;
        return;
    }
    // 1st try COntraints went WRONG but managed
    for (int i=n-k;i<k;i++) {
        if (s[i]!=t[i]) {
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
    return;

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