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
        int n, pre, nw, count=0, old;
        cin >> n;
        cin>>pre;
        int mx = pre;
        for (int i=0;i<n-1;i++) {
            cin>>nw;
            old=mx;
            mx=max(nw, mx);
            if (i%2) {
                if (nw >= pre) {
                    count+=mx-pre+1;
                    // cout<<"*"<<count<<endl;
                    nw = pre-1;
                    if (nw==mx) {
                        mx=old;
                    }
                }
            } else {
                if (nw<=pre) {
                    // interesting edge case of first element 
                    // otherwise balanced with max and max-till pre-1
                    if (i==0) {
                        count+=1;
                    }
                }
                nw=mx;
            }
            pre = nw;
        }
        cout<<count<<endl;
    }
    return 0;
}