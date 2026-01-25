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
    int n, m; cin >> n >> m;
    vector<int> ops(m);
    string s; cin >> s;
    for (int i=0;i<m;i++) {
        cin >> ops[i];
    }
    vector<int> new_ops={0};
    int state;
    if (ops[0]>0) {
        state=1;
    } else if(ops[0]<0) {
        state=-1;
    } else {
        state=0;
    }
    for (int i=0;i<m;i++) {
        if (ops[i]>0) {
            if (state==0) {
                new_ops.back()+=ops[i];
            } else if (state>0) {
                new_ops.back()+=ops[i];
            } else {
                new_ops.push_back(ops[i]);
                state=1;
            }
        } else if (ops[i]<0) {
            if (state==0) {
                new_ops.back()+=ops[i];
            } else if (state>0) {
                state=-1;
                new_ops.push_back(ops[i]);
            } else {
                new_ops.back()+=ops[i];
            }
        }
    }
    for (int i=0;i<(int)new_ops.size();i++) {
        // cout<<s<<endl;
        if (new_ops[i] < 0) {
            for (int j=0;j<-new_ops[i];j++) {
                if (s=="") {
                    break;
                }
                s.pop_back();
            }
        } else {
            for (int j=0;j<new_ops[i];j++) {
                s+='0';
            }
        }
    }
    if (s[0]=='0' or s=="") {
        cout<<0<<endl;
        return;
    }
    for (int i=0;i<(int)s.size();i++) {
        cout<<s[i];
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