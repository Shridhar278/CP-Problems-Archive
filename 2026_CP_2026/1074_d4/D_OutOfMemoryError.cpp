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
    int n, m, h; cin >> n >> m >> h;
    vector<int>a(n), og(n);
    vector<int>b(m);
    vector<int>c(m);
    for (int i=0;i<n;i++) {
        cin >> a[i];
        og[i]=a[i];
    }
    map<int, int> bs;
    for (int i=0;i<n;i++) {
        bs[i]=a[i];
    }
    int last=0;
    vector<int> just(n, 0); int curr=0;
    for (int i=0;i<m;i++) {
        cin >> b[i] >> c[i];
        if (just[b[i]-1]!=curr) {
            bs[b[i]-1]=a[b[i]-1];
            just[b[i]-1]=curr;
        }
        bs[b[i]-1]+=c[i];
        if (bs[b[i]-1]>h) {
            curr++;
            last=i+1;
            bs[b[i]-1]=a[b[i]-1];
            just[b[i]-1]=curr;
        }
    }
    for (int i=last;i<m;i++) {
        a[b[i]-1]+=c[i];
    }
    for (int i=0;i<n;i++) {
        cout<<a[i]<<" ";
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