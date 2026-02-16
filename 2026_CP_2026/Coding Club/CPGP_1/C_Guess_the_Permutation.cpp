#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MOD (int)(1e9+7)
#define EPS (double)1e-9

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

// Linear Algebra

void solve() {
    int n; cin >> n;
    // first n-2
    vector<int> change(n+1);
    int total=0;
    for (int i=3;i<=n;i++) {
        cout<<"? 1 2 "<<i<<flush<<endl;
        cin>>change[i];
    }
    for (int i=4;i<=n;i++) {
        total+=change[i]-change[3];
    }
    int x=((n*(n+1))/2-total-change[3])/(n-3);
    int ans;
    cout<<"? 1 3 4"<<flush<<endl;
    cin>>ans;
    int y=ans-2*x-(change[4]-change[3]);
    cout<<"! "<<y<<" "<<change[3]-y-x<<" ";
    for (int i=3;i<=n;i++) {
        cout<<x+change[i]-change[3]<<" ";
    }
    cout<<flush<<endl;
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