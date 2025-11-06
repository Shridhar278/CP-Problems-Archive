#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e9+7

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

int32_t main() {
    fast_io();
    int test;
    cin >> test;
    while (test--) {
        int n;
        cin >> n;
        char c;
        bool happen=true;
        int stuff[26] = {0};
        for (int i=0;i<n;i++) {
            cin>>c;
            stuff[c-97]++;
        }
        for (int i=0;i<n;i++) {
            cin>>c;
            stuff[c-97]--;
        }
        for (int l=0;l<26;l++) {
            if (stuff[l]!=0) {
                cout<<"NO"<<endl;
                happen=false;
                break;
            }
        }
        if (happen) {
            cout<<"YES"<<endl;
        }
    }
    return 0;
}