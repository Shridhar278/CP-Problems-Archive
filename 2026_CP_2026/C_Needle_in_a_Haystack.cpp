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
    string s, t;
    cin >> s;
    cin >> t;
    vector<int> alphaS(26, 0), alphaT(26, 0);
    for (int i=0;i<s.size();i++) {
        alphaS[s[i]-'a']++;
    }
    for (int i=0;i<t.size();i++) {
        alphaT[t[i]-'a']++;    
    }
    for (int i=0;i<26;i++) {
        if (alphaS[i] > alphaT[i]) {
            cout<<"Impossible"<<endl;
            return;
        }
    }
    string res="";
    int curr=0;
    int order=0;
    int phase = 0;
    while(curr<26) {
        if (not phase and s[order]<=(curr+'a')) {
            res+=s[order];
            order++;
            if (order == s.size()) {
                phase = 1;
            }
            continue;
        }
        if (alphaT[curr]>alphaS[curr]) {
            res+=('a'+curr);
            alphaT[curr]--;
        } else {
            curr++;
        }
    }
    cout<<res<<endl;
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