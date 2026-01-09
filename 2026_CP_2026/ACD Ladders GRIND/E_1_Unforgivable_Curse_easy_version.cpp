#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MOD (int)(1e9+7)
#define EPS (double)1e-9

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

// EZ. checking PROOF
// checked proof simple algo make to swap adajecant then can be put in any order

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
        // cout<<it->second<<" "<<it->first<<" "<<t_map[it->first]<<endl;
        if (it->second!=t_map[it->first]) {
            cout<<"NO"<<endl;
            return;
        }
    }
    if (n>=6) {
        cout<<"YES"<<endl;
        return;
    }
    if (n==1 or n==2 or n==3) {
        for (int i=0;i<n;i++) {
            if (s[i]!=t[i]) {
                cout<<"NO"<<endl;
                return;
            }
        }
        cout<<"YES"<<endl;
        return;
    }
    if (n==4 or n==5) {
        for (int i=(n-1)/2;i<=n/2;i++) {
            if (s[i]!=t[i]) {
                cout<<"NO"<<endl;
                return;
            }
        }
        cout<<"YES"<<endl;
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